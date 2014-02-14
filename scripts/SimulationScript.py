#!/usr/bin/env python


from tempfile import mkstemp
from shutil import move
from os import remove, close, environ, getcwd
import subprocess
import sys

def replace(file_path, pattern, subst):
    #Create temp file
    fh, abs_path = mkstemp()
    new_file = open(abs_path,'w')
    old_file = open(file_path)
    text = old_file.read()
    new_file.write(text.replace(pattern, subst))
    #close temp file
    new_file.close()
    close(fh)
    old_file.close()
    #Remove original file
    remove(file_path)
    #Move new file
    move(abs_path, file_path)

if __name__ == "__main__":
  ChiSimCPP_OLD="""void ChibiSimulation_t::print ( FILE* f, FILE* e ) {
}
bool ChibiSimulation_t::scan ( FILE* f ) {
  return(!feof(f));
}"""

  ChiSimCPP_NEW="""void ChibiSimulation_t::print ( FILE* f, FILE* e ) {
  
  // Extract ID from Hardware Results - String Spliting
  int index;
  char *Id;
  Id = strtok(const_cast<char *>TO_CSTR(ChibiSimulation__io_out_dat_id), "x");
  Id = strtok(NULL, "x");
  index = atoi(Id);

  // Extract Valid Flags from Hardware Result - String Spliting
  char *tmp;
  int valid;
  tmp = strtok(const_cast<char *>(TO_CSTR(ChibiSimulation__io_out_val)), "x");
  tmp = strtok(NULL, "x");
  valid = atoi(tmp);

  // Check to make sure valid Resutlt and Unique example
  // Since the Simulation runs alot faster than the data is sent
  // it can try to send the results multiple times.
  // This check is to prevent that --- Strickly Speaking Valid should be enough.
  if((valid == 1) && (prevId != index) && (prevId2 != index)) {
    // Start to Create the Return String - WordCount
    char *res = new char[100];

    // Start with ID
    strcpy(res, TO_CSTR(ChibiSimulation__io_out_dat_id));
    strcat(res, " ");

    // Add Word
    strcat(res, TO_CSTR(ChibiSimulation__io_out_dat_str));
    strcat(res, " ");

    // Add Count
    strcat(res, TO_CSTR(ChibiSimulation__io_out_dat_int));
    
    // Write Return back to Software
    mmap_write(index, res);

    free(res);

    // Set the prevId flag to the current result to prevent sending the same
    // result multiple times
    prevId2 = prevId;
    prevId = index;
  }
}
bool ChibiSimulation_t::scan ( FILE* f ) {
  // Attempt to Read Result for a FIFO
  char *res;
  res = mmap_read();

  // Check if Result Valid
  if (res != NULL) {
    // Result Split for Entry into Hardware Modules
    char *tmp;
    tmp = strtok(res, " ");

    // Insert Unique Data Point ID
    str_to_dat(string(tmp), ChibiSimulation__io_in_dat_id);

    // Get pointer to next " " split
    tmp = strtok(NULL, " ");

    // Insert Data - Setup for WordCount
    str_to_dat(string(tmp), ChibiSimulation__io_in_dat_str);

    // Give 1 to in_val for new Data Point
    str_to_dat("1", ChibiSimulation__io_in_val);
  }

  free(res);
  return(!feof(f));
}


void ChibiSimulation_t::mmap_write(int id, char* str) {
  
  // First need to find the Name of the FIFO for the Results
  int i= 0;
  while(idToName[0][i] != id) i++;

  // ID Found - Create FIFO name
  char outName[100];
  sprintf(outName, "%s%dout", DIR_NAME, idToName[1][i]);  

  // Open Results FIFO
  int fd = open(outName, O_WRONLY);

  // Write to FIFO
  write(fd, str, SIZE);

  // Close FIFO
  close(fd);

  // Clear idToName of ID and Name
  idToName[0][i] = 0;
  idToName[1][i] = 0;
  
}

char* ChibiSimulation_t::mmap_read() {

  // FIND FIFO
  // READ -> TEST IF VALUE
    // IF VALUE RETURN RESULT
    // IF NOT VALUE LOOK FOR ANOTHER FIFO
  // IF NOT MORE FIFO RETURN NULL

  // Finds all FIFO's
  int *fifos;
  fifos = find_dir();

  char *res = (char *)malloc(SIZE);

  // Loop Through the Different FIFOs
  int i = 0;
  while(fifos[i] != 0) {
      // printf("+");
    // Create FIFO name
    char inName[100];
    sprintf(inName, "%s%din", DIR_NAME, fifos[i]);

    char flagName[100];
    sprintf(flagName, "%s%d", FLAG_NAME, fifos[i]);

    ssize_t r = 0;

    if( access(flagName, F_OK) != -1) {
      // Open FIFO - BLOCKING
      int fd = open(inName, O_RDONLY);

      // Attempt to Read Result
      r = read(fd, res, SIZE);

      // Close FIFO
      close(fd);
    }

    // Test Result - IF exists return res
    if (r > 0) {
      // Create a copy of the read to return
      char *the_res = (char *)malloc(SIZE);
      strcpy(the_res, res);

      // Need some way to track which ID corresponds to which fifo pair
      // Split to Get the ID
      char *tmp;
      tmp = strtok(res, " ");
      int resID = atoi(tmp);

      // Add ID and FIFO Name to idToName Array
      // Find Empty Entry
      int j = 0;
      while (idToName[0][j] != 0) j++;

      // Empty Found Add ID and Name to Array
      idToName[0][j] = resID; // ID
      idToName[1][j] = fifos[i]; // NAME

      free(res);
      free(fifos);
      return the_res;
    }

    i++;
  }

  // No Valid Results Found
  free(res);
  free(fifos);
  return NULL;
}

int* ChibiSimulation_t::find_dir() {
  
  // Directory Structure Variables
  DIR *dir;
  struct dirent *ent;

  // Array that holds fifo name
  int *fifos = (int*)malloc(sizeof(int)*20);
  int i = 0;

  // IF THERE IS A DIR
  if ((dir = opendir (DIR_NAME)) != NULL) {

    // While there are files to look at
    while ((ent = readdir (dir)) != NULL) {

      // Test to sure that it isn't curr/prev dir
      if(ent->d_name[0] != '.') {

        // Translate Name to Integer
        fifos[i] = atoi(ent->d_name);
        i++;
      }
    }

    // Once All FIFO are found close dir and return
    closedir (dir);
    return fifos;
  
  } else {

    /* could not open directory */
    perror ("Directory does not exist");
    exit(EXIT_FAILURE);
  }
}"""

  EMU_OLD="""#include <stdexcept>"""

  EMU_NEW="""#include <stdexcept>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <ctype.h>
#include <dirent.h>

#define DIR_NAME "/tmp/fifo/"
#define FLAG_NAME "/tmp/flag"
#define SIZE  (sizeof(char)*100)"""

  ChiSimH_OLD="""void dump ( FILE* f, int t );"""

  ChiSimH_NEW="""void dump ( FILE* f, int t );
  char* mmap_read();
  void mmap_write(int id, char* value);
  int* find_dir();
  int idToName[2][10000];
  int prevId;
  int prevId2;"""


  replace("ChibiSimulation.cpp", ChiSimCPP_OLD, ChiSimCPP_NEW)
  replace("ChibiSimulation.h", ChiSimH_OLD, ChiSimH_NEW)
  replace("emulator.h", EMU_OLD, EMU_NEW)