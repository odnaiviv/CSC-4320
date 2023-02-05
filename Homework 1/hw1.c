/*
Vivian Do
CSC 4320
Jan 22 2023
*/

// adding libraries to use in program
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

// main method
int main() {
    // creating variable for fork() function
    int id = fork();
    // checking if child id is 0
    if (id == 0) {
        // child id waits for 1 second
        sleep(1);
    }

    // printing ids from getpid() & getppid() functions
    printf("Child ID: %d | Parent ID: %d\n", getpid(), getppid());

    // creating variable for waitpid() function
    int waiting = waitpid(-1, NULL, 0);
    // checking for processing results of current id
    if (waiting == -1) {
        // printing results
        printf("%d has no children to wait for.\n\n", getppid());
    }
    else if (waiting != -1) {
        // printing results
        printf("%d has finished processing.\n\n", waiting);
    }
    else {
        exit(0);
    }

    // specifying path name & creating arguments
    char *path = "/bin/ls";
    char *arg1 = "ls";
    // pathing to my directory on snowball
    char *arg2 = "/home/vdo10/OS";

    // calling execl() function
    execl(path, path, arg1, arg2, NULL);
    // terminating program
    exit(0);
}
