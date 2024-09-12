/*
============================================================================

Name : 22.c
Author: Mohit Marfatia
Problem: Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
Date: 31st Aug, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int fd;
    pid_t pid;

    fd = open("22.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd < 0) {
        perror("Failed to open file");
    }

    write(fd, "Start of file\n", 14);

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        close(fd);
    } else if (pid == 0) {
        write(fd, "Child process writing.\n", 23);
    } else {
        write(fd, "Parent process writing.\n", 24);
        
        wait(NULL);
    }

    write(fd, "End of file\n", 12);

    close(fd);
    
    return 0;
}

/*
Output:
Start of file
Parent process writing.
Child process writing.
End of file
End of file

*/