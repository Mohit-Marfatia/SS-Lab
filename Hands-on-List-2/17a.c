/*
============================================================================

Name : 17a.c
Author: Mohit Marfatia
Problem: Write a program to execute ls -l | wc.
a. use dup
Date: 18th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pipefds[2];
    pid_t pid;
    if (pipe(pipefds) == -1) {
        perror("Pipe failed");
        exit(1);
    }

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid == 0) {
        close(pipefds[1]); 
        close(0);

        dup(pipefds[0]);

        execlp("wc", "wc", NULL);
        perror("execlp failed");
        exit(1);
    } else {
        close(pipefds[0]);
        close(1); 

        dup(pipefds[1]);

        execlp("ls", "ls", "-l", NULL);
        perror("execlp failed");
        exit(1);
    }
    
    return 0;
}

/*
Output:
     31     274    2080

*/