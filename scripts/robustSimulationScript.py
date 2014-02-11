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
  int valid;
  char *tmp;
  char *Id;
  char index[20];
  Id = strtok(const_cast<char *>TO_CSTR(ChibiSimulation__io_out_dat_id), "x");
  Id = strtok(NULL, "x");
  tmp = strtok(const_cast<char *>(TO_CSTR(ChibiSimulation__io_out_val)), "x");
  tmp = strtok(NULL, "x");
  valid = atoi(tmp);
  strcpy(index, Id);

  // Dodgy checking
  if((valid == 1) && !strstr(prevId, Id)) {
    // Make String
    char *res = new char[200];
    strcpy(res, TO_CSTR(ChibiSimulation__io_out_dat_id));
    strcat(res, " ");
    strcat(res, TO_CSTR(ChibiSimulation__io_out_dat_str));
    strcat(res, " ");
    strcat(res, TO_CSTR(ChibiSimulation__io_out_dat_int));
    // Write Value
    mmap_write(res);
    free(res);
    strcpy(prevId, index);
  }
}
bool ChibiSimulation_t::scan ( FILE* f ) {
  char *res;
  res = mmap_read();
  if (res != NULL) {
    char *tmp;
    tmp = strtok(res, " ");
    str_to_dat(string(tmp), ChibiSimulation__io_in_dat_id);
    tmp = strtok(NULL, " ");
    str_to_dat(string(tmp), ChibiSimulation__io_in_dat_str);
    str_to_dat("1", ChibiSimulation__io_in_val);
  }
  free(res);
  return(!feof(f));
}

typedef struct charArray
{
    char res[100];
} charArray;


void ChibiSimulation_t::mmap_write(char* str) {
  // Set up mmap variables
  int fd;
  int result;
  char *name;
  char value[100];
  charArray *map; // String Mapping

  strcpy(value, str);

  name = strtok(str, " ");
  name = strtok(name, "x");
  name = tr(strtok(NULL, "x"));

  char filename[20];
  sprintf(filename, "\%s\%s", OUTPATH, name);

  // Create simIn
  fd = open(filename, O_RDWR | O_CREAT, (mode_t)0600);
  if (fd == -1) {
      perror("FPGA: Error opening file for writing");
      exit(EXIT_FAILURE);
  }

  // Open File
  result = lseek(fd, FILESIZE-1, SEEK_SET);
  if (result == -1) {
      close(fd);
      perror("Error calling lseek() to 'stretch' the file");
      exit(EXIT_FAILURE);
  }

  // Wirte Empty string to file to preserve size
  result = write(fd, "", 1);
  if (result != 1) {
      close(fd);
      perror("Error writing last byte of the file");
      exit(EXIT_FAILURE);
  }

  //Create mmapped
  map = (charArray*)mmap(0, FILESIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
  if (map == MAP_FAILED) {
      close(fd);
      perror("Error mmapping the file");
      exit(EXIT_FAILURE);
  }

  // Write ints
  strcpy(map->res, value);

  if (munmap(map, FILESIZE) == -1) {
      perror("Error un-mmapping the file");
  }
  close(fd);
}

char* ChibiSimulation_t::mmap_read() {

  // MMAP READ
  int fd;
  int result;
  char *value = (char *)malloc(sizeof(char)*100);
  charArray *map; //String Mapping

  char *name = find_dir();
  if(name == NULL) {
    return NULL;
  }

  char filename[20];
  sprintf(filename, "\%s\%s", INPATH, name);

  fd = open(filename, O_RDWR, (mode_t)0600);
  if (fd == -1) {
      perror("FPGA: Error opening file for writing");
      exit(EXIT_FAILURE);
  }

  // Open File
  result = lseek(fd, FILESIZE-1, SEEK_SET);
  if (result == -1) {
      close(fd);
      perror("Error calling lseek() to 'stretch' the file");
      exit(EXIT_FAILURE);
  }

  // Wirte Empty string to file to preserve size
  result = write(fd, "", 1);
  if (result != 1) {
      close(fd);
      perror("Error writing last byte of the file");
      exit(EXIT_FAILURE);
  }

  map = (charArray *)mmap(0, FILESIZE, PROT_READ, MAP_SHARED, fd, 0);
  if (map == MAP_FAILED) {
      close(fd);
      perror("Error mmapping the file");
      exit(EXIT_FAILURE);
  }

  while (!strstr(map->res, name));
  usleep(1); // NEED TO FIND SOME WAY TO PREVENT THIS
  strcpy(value, map->res);

  if (munmap(map, FILESIZE) == -1) {
      perror("Error un-mmapping the file");
  }
  close(fd);

  if(remove(filename) != 0)
      perror("Error deleting file");

  return value;
}

char* ChibiSimulation_t::find_dir() {
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir (INPATH)) != NULL) {
      /* print all the files and directories within directory */
      while ((ent = readdir (dir)) != NULL) {
        if(ent->d_name[0] != '.')  {
          closedir (dir);
          return ent->d_name;
        }
      }
      closedir (dir);
      return NULL;
    } else {
      /* could not open directory */
      perror ("Directory does not exist");
      exit(EXIT_FAILURE);
    }
}
char* ChibiSimulation_t::tr ( char *s )
{
  int i = 0;
  int j = strlen ( s ) - 1;
  int k = 0;
 
  while ( isspace ( s[i] ) && s[i] != '\\0' )
    i++;
 
  while ( isspace ( s[j] ) && j >= 0 )
    j--;
 
  while ( i <= j )
    s[k++] = s[i++];
 
  s[k] = '\\0';
 
  return s;
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

#define INPATH    "/tmp/simIn/"
#define OUTPATH	  "/tmp/simOut/"
#define FILESIZE  (sizeof(char)*100)"""
	
	ChiSimH_OLD="""void dump ( FILE* f, int t );"""

	ChiSimH_NEW="""void dump ( FILE* f, int t );
  char* mmap_read();
  void mmap_write(char* value);
  char* find_dir();
  char *tr (char *s);
  char prevId[20];"""

	replace("ChibiSimulation.cpp", ChiSimCPP_OLD, ChiSimCPP_NEW)
	replace("ChibiSimulation.h", ChiSimH_OLD, ChiSimH_NEW)
	replace("emulator.h", EMU_OLD, EMU_NEW)