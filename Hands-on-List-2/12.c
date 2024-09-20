/*
============================================================================

Name : 12.c
Author: Mohit Marfatia
Problem: Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
the parent process from the child process.
Date: 17th Sept, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid == 0) {
        printf("Child process: PID = %d\n", getpid());
        sleep(10);

        printf("Child killing the parent (PID = %d)\n", getppid());
        kill(getppid(), SIGKILL);

        sleep(10);
        printf("Orphan child process now adopted by init, PID = %d, parent PID = %d\n", getpid(), getppid());
    } else {
        printf("Parent process: PID = %d\n", getpid());
        sleep(10);
    }

    return 0;
}
