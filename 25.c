/*
============================================================================

Name : 25.c
Author: Mohit Marfatia
Problem: Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).
Date: 31st Aug, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2, pid3; 

    
    pid1 = fork();
    if (pid1 < 0) {
        perror("Fork failed for child 1");
    } else if (pid1 == 0) {
        printf("Child 1 PID: %d is running...\n", getpid());
        sleep(1); 
        printf("Child 1 PID: %d is exiting.\n", getpid());
        exit(0);
    }

    pid2 = fork();
    if (pid2 < 0) {
        perror("Fork failed for child 2");
    } else if (pid2 == 0) {
        printf("Child 2 PID: %d is running...\n", getpid());
        sleep(3);
        printf("Child 2 PID: %d is exiting.\n", getpid());
        exit(0);
    }

    pid3 = fork();
    if (pid3 < 0) {
        perror("Fork failed for child 3");
    } else if (pid3 == 0) {
        printf("Child 3 PID: %d is running...\n", getpid());
        sleep(5);
        printf("Child 3 PID: %d is exiting.\n", getpid());
        exit(0);
    }

    printf("Parent PID: %d is waiting for Child 2 PID: %d to complete.\n", getpid(), pid2);

    int status;
    pid_t waited_pid = waitpid(pid2, &status, 0);
    if (waited_pid == -1) {
        perror("waitpid failed");
        exit(EXIT_FAILURE);
    }

    printf("Parent PID: %d detected that Child 2 PID: %d has finished.\n", getpid(), waited_pid);

    while ((waited_pid = wait(NULL)) > 0) {
        printf("Parent PID: %d detected that Child PID: %d has finished.\n", getpid(), waited_pid);
    }

    printf("Parent PID: %d is exiting.\n", getpid());

    return 0;
}

/*
Output:
Child 1 PID: 5085 is running...
Parent PID: 5084 is waiting for Child 2 PID: 5086 to complete.
Child 2 PID: 5086 is running...
Child 3 PID: 5087 is running...
Child 1 PID: 5085 is exiting.
Child 2 PID: 5086 is exiting.
Parent PID: 5084 detected that Child 2 PID: 5086 has finished.
Parent PID: 5084 detected that Child PID: 5085 has finished.
Child 3 PID: 5087 is exiting.
Parent PID: 5084 detected that Child PID: 5087 has finished.
Parent PID: 5084 is exiting.

*/
