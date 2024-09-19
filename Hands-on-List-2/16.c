/*
============================================================================

Name : 16.c
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
    int pipe_p_to_c[2];
    int pipe_c_to_p[2];
    pid_t pid;
    char parent_msg[100];
    char child_msg[100];
    char read_buffer[100];

    if (pipe(pipe_p_to_c) == -1) {
        perror("Pipe creation failed (Parent to Child)");
        exit(1);
    }

    if (pipe(pipe_c_to_p) == -1) {
        perror("Pipe creation failed (Child to Parent)");
        exit(1);
    }

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid > 0) {
        close(pipe_p_to_c[0]); // Close read end of parent to child pipe
        close(pipe_c_to_p[1]); // Close write end of child to parent pipe

        printf("Enter message:\n");
        scanf("%[^\n]s", parent_msg);
        write(pipe_p_to_c[1], parent_msg, strlen(parent_msg) + 1);
        printf("Parent: Sent message to child: \"%s\"\n", parent_msg);

        read(pipe_c_to_p[0], read_buffer, sizeof(read_buffer));
        printf("Parent: Received message from child: \"%s\"\n", read_buffer);

        close(pipe_p_to_c[1]);
        close(pipe_c_to_p[0]);

    } else {
        close(pipe_p_to_c[1]); // Close write end of parent to child pipe
        close(pipe_c_to_p[0]); // Close read end of child to parent pipe

        read(pipe_p_to_c[0], read_buffer, sizeof(read_buffer));
        printf("Child: Received message from parent: \"%s\"\n", read_buffer);

        printf("Enter message:\n");
        scanf("%[^\n]s", child_msg);
        write(pipe_c_to_p[1], child_msg, strlen(child_msg) + 1);
        printf("Child: Sent message to parent: \"%s\"\n", child_msg);

        close(pipe_p_to_c[0]);
        close(pipe_c_to_p[1]);
    }

    return 0;
}

/*
Output:
Enter message:
Hello from Parent
Parent: Sent message to child: "Hello from Parent"
Child: Received message from parent: "Hello from Parent"
Enter message:
Hello from Child
Child: Sent message to parent: "Hello from Child"
Parent: Received message from child: "Hello from Child"


*/