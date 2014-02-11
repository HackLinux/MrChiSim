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
  int valid, index;
  char *tmp;
  char *Id;
  char *tmpdat;
  char dat[50];
  tmpdat = const_cast<char *>TO_CSTR(ChibiSimulation__io_out_dat_str);
  strcpy(dat, tmpdat);
  Id = strtok(const_cast<char *>TO_CSTR(ChibiSimulation__io_out_dat_id), "x");
  Id = strtok(NULL, "x");
  index = atoi(Id);
  tmp = strtok(const_cast<char *>(TO_CSTR(ChibiSimulation__io_out_val)), "x");
  tmp = strtok(NULL, "x");
  valid = atoi(tmp);

  if((valid == 1) && ((index != prevId) || !strstr(prevdat, dat))) {
    // Make String
    char *res = new char[200];
    strcpy(res, TO_CSTR(ChibiSimulation__io_out_dat_id));
    strcat(res, " ");
    strcat(res, TO_CSTR(ChibiSimulation__io_out_dat_str));
    strcat(res, " ");
    strcat(res, TO_CSTR(ChibiSimulation__io_out_dat_int));
    // Write Value
    mmap_write(res, index);
    free(res);
    prevId = index;
    strcpy(prevdat, dat);
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
    char res[NUMHEX][100];
} charArray;


void ChibiSimulation_t::mmap_write(char* str, int index) {
  // Set up mmap variables
  int fd;
  int result;
  char *name;
  char value[100];
  charArray *map; // String Mapping

  strcpy(value, str);

  // Create simIn
  fd = open(OUTPATH, O_RDWR | O_CREAT, (mode_t)0600);
  if (fd == -1) {
      perror("FPGA Write: Error opening file for writing");
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
  strcpy(map->res[index], value);

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

  fd = open(INPATH, O_RDWR | O_CREAT, (mode_t)0600);
  if (fd == -1) {
      perror("FPGA Read: Error opening file for writing");
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

  map = (charArray *)mmap(0, FILESIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
  if (map == MAP_FAILED) {
      close(fd);
      perror("Error mmapping the file");
      exit(EXIT_FAILURE);
  }


  int i = 0;
  while(i <= NUMHEX) {
    if (map->res[i][0] != '\\0')
      break;
    i++;
  }
  if(i == NUMHEX+1) {
    if (munmap(map, FILESIZE) == -1) {
        perror("Error un-mmapping the file");
    }
    close(fd);
    return NULL;
  }

  usleep(1); // This doesn't make a huge difference to performance
  strcpy(value, map->res[i]);

  strcpy(map->res[i], "\\0");

  if (munmap(map, FILESIZE) == -1) {
      perror("Error un-mmapping the file");
  }

  close(fd);
  return value;
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

#define INPATH    "/tmp/simIn.bin"
#define OUTPATH   "/tmp/simOut.bin"
#define NUMHEX    100
#define FILESIZE  (NUMHEX * sizeof(char)*100)"""
  
  ChiSimH_OLD="""void dump ( FILE* f, int t );"""

  ChiSimH_NEW="""void dump ( FILE* f, int t );
  char* mmap_read();
  void mmap_write(char* value, int index);
  int prevId;
  char prevdat[50];"""

  replace("ChibiSimulation.cpp", ChiSimCPP_OLD, ChiSimCPP_NEW)
  replace("ChibiSimulation.h", ChiSimH_OLD, ChiSimH_NEW)
  replace("emulator.h", EMU_OLD, EMU_NEW)