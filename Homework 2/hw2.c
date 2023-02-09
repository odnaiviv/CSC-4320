/*
Vivian Do
CSC 4320
Feb 05 2023
*/

// adding libraries to use in program
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

// creating text file 
const char* path = "file.txt";

// starting processes
int main() {
	if (fork() == 0) {
		printf("Starting P1\n");
		if (fork() == 0) {
			printf("Starting P2\n");
			if (fork() == 0) {
				printf("Starting P3\n"); 
			}
		}
	}

	// adding variables
	pid_t pid = getpid();
	int i;
	FILE* fp; 
	int num; 

	// loop to increment number until getting 200
	for (i = 0; i < 200; i++) {
		// opening file
		fp = fopen(path, "r");
		// reading number from file
		fscanf(fp, "&d", &num);
		// closing file
		fclose(fp);
		// printing number with its process id
		printf("N: %d | Process ID: %d\n", num, pid);
		// incrementing number by 1
		num++;
		// opening file again
		fp = fopen(path, "w");
		// writing number into file
		fprintf(fp, "%d", num);
		// closing file again
		fclose(fp);
	}
	exit(0);
}
