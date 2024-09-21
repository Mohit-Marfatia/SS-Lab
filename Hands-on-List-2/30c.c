/*
============================================================================

Name : 30c.c
Author: Mohit Marfatia
Problem: Write a program to create a shared memory.
c. detach the shared memory
Date: 20th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

int main() {
    key_t key;
    int shmid;
    char *data;

    key = ftok(".", 'm');
    shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    data = (char *)shmat(shmid, NULL, SHM_RDONLY);
    printf("Detach from the shared memory (read-only)");
    if (shmdt(data) == -1) {
        perror("shmdt failed");
        exit(1);
    }
    return 0;
}

/*
Output:
Attaching in read-only mode. Current data: Hello, Shared Memory!
Attempting to overwrite in read-only mode...
Segmentation fault (core dumped)
*/