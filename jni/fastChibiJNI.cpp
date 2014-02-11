#include "ChibiJNI.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <dirent.h>

#define INPATH      "/tmp/simIn.bin"
#define OUTPATH     "/tmp/simOut.bin"
#define NUMHEX      100
#define FILESIZE    (NUMHEX * sizeof(char)*100)

typedef struct charArray
{
    char res[NUMHEX][100];
} charArray;

// --- Native Write Methods
JNIEXPORT jint JNICALL Java_ChibiJNI_hexSend
(JNIEnv* env, jobject obj, jstring in_hex, jint index) {
    // Set up mmap variables
    int fd;
    int result;
    charArray *map; // String Mapping

    // Read String from Scala
    char *str = const_cast<char *>(env->GetStringUTFChars(in_hex, 0));

    // Create simIn
    fd = open(INPATH, O_RDWR | O_CREAT, (mode_t)0600);
    if (fd == -1) {
        perror("PC Write: Error opening file for writing");
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
    strcpy(map->res[index], str);

    if (munmap(map, FILESIZE) == -1) {
        perror("Error un-mmapping the file");
    }
    close(fd);
    free(str);
    return 0;
}


// --- Native Read Methods
JNIEXPORT jstring JNICALL Java_ChibiJNI_hexRead
(JNIEnv* env, jobject obj, jint index) {
    int fd;
    int result;
    char value[100];
    charArray *map; //String Mapping

    fd = open(OUTPATH, O_RDWR | O_CREAT, (mode_t)0600);
    if (fd == -1) {
        perror("PC Read: Error opening file for writing");
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

    while (map->res[index][0] == '\0');

    usleep(1);
    strcpy(value, map->res[index]);

    strcpy(map->res[index], "\0");

    if (munmap(map, FILESIZE) == -1) {
      perror("Error un-mmapping the file");
    }

    close(fd);
    return env->NewStringUTF(value);
}