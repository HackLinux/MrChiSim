#include <jni.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "MrChiSim.h"

#define SIZE sizeof(char)*100
#define DIR_NAME "/tmp/fifo/"
#define FLAG_NAME	"/tmp/flag"

int name;

// --- Native send Method
void send(char* val, char* ind) {

	// Create Data
	char writein[100];
	sprintf(writein, "%s %s", ind, val);
	
	// Create Fifo name
	char inName[100];
	sprintf(inName, "%s%din", DIR_NAME, name);
	
	char flagName[100];
	sprintf(flagName, "%s%d", FLAG_NAME, name);

	// Create Read FLAG
	int flag = open(flagName, O_RDWR | O_CREAT);

	// Open FIFO - BLOCKING
	int fd = open(inName, O_WRONLY);
	
	// Close and Remove Read FLAG
	close(flag);
	unlink(flagName);

	// Write to FIFO
	write(fd, writein, SIZE);

	// Close FIFO
	close(fd);
}


// --- Native read Method
char* get() {
    // Create out FIFO Name
    char outName[100];
    sprintf(outName, "%s%dout", DIR_NAME, name);

    // Open FIFO - BLOCKING
    int fd = open(outName, O_RDONLY);

    // Read from FIFO
    char *value = (char*)malloc(SIZE);
    read(fd, value, SIZE);

    // Close FIFO
    close(fd);

    // Return Result
    return value;
}

// --- Native send Method
JNIEXPORT jstring JNICALL Java_MrChiSim_doFPGA
(JNIEnv* env, jclass self, jstring in, jstring index) {

	// Input Variables
	char *ind = const_cast<char *>(env->GetStringUTFChars(index, 0));
	char *val = const_cast<char *>(env->GetStringUTFChars(in, 0));
	
	// Return Variable
	char *result = (char*)malloc(SIZE);

	// Send Value	
	send(val, ind);

	// Get Result
	char *res = get();
	strcpy(result, res);

	free(res);
	// Return Result
    return env->NewStringUTF(result);
}




// --- Native create Method
JNIEXPORT jint JNICALL Java_MrChiSim_create
(JNIEnv* env, jclass self) {
	unsigned int seed = time(NULL);
	name = rand_r(&seed);

	// Create In FIFO
	char inName[100];
	sprintf(inName, "%s%din", DIR_NAME, name);
	mkfifo(inName, 0666);

	// Create Out FIFO
	char outName[100];
    sprintf(outName, "%s%dout", DIR_NAME, name);
	mkfifo(outName, 0666);

    return 0;
}

// --- Native destroy Methods
JNIEXPORT jint JNICALL Java_MrChiSim_destroy
(JNIEnv* env, jclass self) {
	
	// Remove In FIFO
	char inName[100];
	sprintf(inName, "%s%din", DIR_NAME, name);
	unlink(inName);

	// Remove Out FIFO
	char outName[100];
    sprintf(outName, "%s%dout", DIR_NAME, name);
	unlink(outName);

    return 0;
}

JNIEXPORT jint JNICALL JNI_OnLoad( JavaVM *vm, void *pvt )
	{
	// fprintf( stdout, "* JNI_OnLoad called\n" );
	return JNI_VERSION_1_2;
	}

JNIEXPORT void JNICALL JNI_OnUnload( JavaVM *vm, void *pvt )
	{
	fprintf( stdout, "* JNI_OnUnload called\n" );
	}
	
void _init()
	{
	fprintf(stdout,"* _init called\n");
	}

void _fini()
	{
	fprintf( stdout, "* _fini called\n" );
	}