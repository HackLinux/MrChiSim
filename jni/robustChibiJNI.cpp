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

#define INPATH      "/tmp/simIn/"
#define OUTPATH     "/tmp/simOut/"
#define FILESIZE    (sizeof(char)*100)

char* find_dir(char* target) {
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir (OUTPATH))!= NULL) {
      /* print all the files and directories within directory */
      while ((ent = readdir (dir)) != NULL) {
        if(strstr(ent->d_name,target))  {
          closedir (dir);
          return ent->d_name;
        }
      }
    }
    closedir(dir);
    return NULL;
}

typedef struct charArray
{
    char res[100];
} charArray;

// --- Native Write Methods
JNIEXPORT jint JNICALL Java_ChibiJNI_hexSend
(JNIEnv* env, jobject obj, jstring in_hex, jstring in_name) {
    // Set up mmap variables
    int fd;
    int result;
    charArray *map; // String Mapping

    // Read String from Scala
    char *str = const_cast<char *>(env->GetStringUTFChars(in_hex, 0));
    char *name = const_cast<char *>(env->GetStringUTFChars(in_name, 0));
    char filename[20];
    sprintf(filename, "%s%s", INPATH, name);

    // Create simIn
    fd = open(filename, O_RDWR | O_CREAT, (mode_t)0600);
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
    strcpy(map->res, str);

    if (munmap(map, FILESIZE) == -1) {
        perror("Error un-mmapping the file");
    }
    close(fd);
    free(str);
    free(name);
    return 0;
}


// --- Native Read Methods
JNIEXPORT jstring JNICALL Java_ChibiJNI_hexRead
(JNIEnv* env, jobject obj, jstring in_name) {
    int fd;
    int result;
    char value[100];
    char *name2;
    charArray *map; //String Mapping

    char *name = const_cast<char *>(env->GetStringUTFChars(in_name, 0));
    while((name2 = find_dir(name)) == NULL);

    char filename[20];
    sprintf(filename, "%s%s", OUTPATH, name2);

    fd = open(filename, O_RDWR, (mode_t)0600);
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

    while (!strstr(map->res, name2));
    strcpy(value, map->res);
    

    if (munmap(map, FILESIZE) == -1) {
      perror("Error un-mmapping the file");
    }
    close(fd);

    char filename2[20];
    sprintf(filename2, "%s%s", OUTPATH, name);

    if(remove(filename2) != 0)
        perror("Error deleting file");

    free(name);
    return env->NewStringUTF(value);
}