/*
============================================================================

Name : 15.c
Author: Mohit Marfatia
Problem: Write a simple program to send some data from parent to the child process.
Date: 18th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int pipefds[2];
    pid_t pid;
    char write_msg[100];
    char read_msg[100];

    if (pipe(pipefds) == -1) {
        perror("Pipe failed");
        exit(1);
    }

    pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid > 0) {
        close(pipefds[0]); // Close the read end 

        printf("Enter message:\n");
        scanf("%[^\n]s", write_msg);
        printf("Parent: Sending data: \"%s\"\n", write_msg);
        write(pipefds[1], write_msg, strlen(write_msg) + 1);

        close(pipefds[1]); // Close the write end
    } else {
        close(pipefds[1]); // Close the write end

        read(pipefds[0], read_msg, sizeof(read_msg));
        printf("Child: Receiving data: \"%s\"\n", read_msg);

        close(pipefds[0]); // Close the read end
    }

    return 0;
}


/*
Output:
Enter message:
Hello!
Parent: Sending data: "Hello!"
Child: Receiving data: "Hello!"

*/