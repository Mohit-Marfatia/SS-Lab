/*
============================================================================

Name : 17b.c
Author: Mohit Marfatia
Problem: Write a program to execute ls -l | wc.
b. use dup2
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
        close(pipefds[1]); // Close the write end of the pipe
        close(0); // Close the stdin

        // Duplicate the pipe's read end to stdin using dup2()
        dup2(pipefds[0], 0);

        execlp("wc", "wc", NULL);
        perror("execlp failed");
        exit(1);
    } else {
        close(pipefds[0]); // Close the read end of the pipe
        close(1); // Close the stdout

        // Duplicate the pipe's write end to stdout using dup2()
        dup2(pipefds[1], 1); 

        execlp("ls", "ls", "-l", NULL);
        perror("execlp failed");
        exit(1);
    }
    
    return 0;
}

/*
Output:
     32     283    2150

*/