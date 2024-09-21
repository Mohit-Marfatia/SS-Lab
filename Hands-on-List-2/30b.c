/*
============================================================================

Name : 30b.c
Author: Mohit Marfatia
Problem: Write a program to create a shared memory.
b. attach with O_RDONLY and check whether you are able to overwrite.
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
    printf("Attaching in read-only mode. Current data: %s\n", data);
    printf("Attempting to overwrite in read-only mode...\n");
    if (strcpy(data, "New Data") == NULL) {
        perror("Overwrite failed");
    } else {
        printf("Data after overwrite attempt: %s\n", data);
    }
    return 0;
}

/*
Output:
Attaching in read-only mode. Current data: Hello, Shared Memory!
Attempting to overwrite in read-only mode...
Segmentation fault (core dumped)
*/