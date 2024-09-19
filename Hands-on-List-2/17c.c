/*
============================================================================

Name : 17c.c
Author: Mohit Marfatia
Problem: Write a program to execute ls -l | wc.
c. use fcntl
Date: 18th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

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

        // Duplicate the pipe's read end to stdin using fcntl()
        fcntl(pipefds[0], F_DUPFD, 0);

        execlp("wc", "wc", NULL);
        perror("execlp failed");
        exit(1);
    } else {
        close(pipefds[0]); // Close the read end of the pipe
        close(1); // Close the stdout

        // Duplicate the pipe's write end to stdout using fcntl()
        fcntl(pipefds[1], F_DUPFD, 1);

        execlp("ls", "ls", "-l", NULL);
        perror("execlp failed");
        exit(1);
    }
    
    return 0;
}

/*
Output:
     33     292    2219

*/