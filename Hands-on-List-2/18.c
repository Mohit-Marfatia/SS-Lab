/*
============================================================================

Name : 18.c
Author: Mohit Marfatia
Problem: Write a program to find out total number of directories on the pwd.
execute ls -l | grep ^d | wc ? Use only dup2.
Date: 18th Sept, 2024.
============================================================================
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int pipe_ls[2], pipe_grep[2];
    pid_t pid1, pid2;
    
    if (pipe(pipe_ls) == -1) {
        perror("Pipe failed");
        exit(1);
    }
    
    if (pipe(pipe_grep) == -1) {
        perror("Pipe failed");
        exit(1);
    }

    pid1 = fork();
    if (pid1 < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid1 != 0) {
        dup2(pipe_ls[1], 1);

        close(pipe_ls[0]);
        close(pipe_grep[0]);
        close(pipe_grep[1]);

        execlp("ls", "ls", "-l", "../", NULL);
        perror("execlp failed");
        exit(1);
    } else {
        pid2 = fork();
        if (pid2 < 0) {
             perror("Fork failed");
            exit(1);
        }
        if (pid2 != 0) {
            dup2(pipe_ls[0], 0);
            dup2(pipe_grep[1], 1);
            
            close(pipe_ls[1]);
            close(pipe_grep[0]);
            
            execlp("grep", "grep", "^d", NULL);
            perror("execlp failed");
            exit(1);
        } else {
            dup2(pipe_grep[0], 0); // redirects the standard input to the read end of the pipe.
            // This means that any input that the program would normally read from the keyboard (stdin) will now come from the data written to the pipe by another process.
            
            close(pipe_grep[1]);
            close(pipe_ls[0]);
            close(pipe_ls[1]);
            
            execlp("wc", "wc", NULL);
            perror("execlp failed");
            exit(1);
        }
    }
}

/*
Output:
      2      18     154

*/