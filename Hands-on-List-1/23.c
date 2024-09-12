/*
============================================================================

Name : 23.c
Author: Mohit Marfatia
Problem: Write a program to create a Zombie state of the running program.
Date: 31st Aug, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
    } else if (pid == 0) {
        printf("Child process PID: %d is exiting...\n", getpid());
        exit(0);
    } else {
        printf("Parent process PID: %d created a child process PID: %d.\n", getpid(), pid);
        // int status;
        // wait(&status);
        sleep(10);
        printf("Parent process PID: %d is exiting...\n", getpid());
    }

    return 0;
}

/*
Output:
Parent process PID: 19843 created a child process PID: 19844.
Child process PID: 19844 is exiting...
Parent process PID: 19843 is exiting...

*/