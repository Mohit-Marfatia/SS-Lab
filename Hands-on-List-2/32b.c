/*
============================================================================

Name : 32B.c
Author: Mohit Marfatia
Problem: Write a program to implement semaphore to protect any critical section.
b. protect shared memory from concurrent write access
Date: 20th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include "definition.h"

int main() {
    SemUnion arg;
    int semid, shmid, *data;
    int key;

    key = ftok(".", 'n'); 
    shmid = shmget(key, 1024, IPC_CREAT | 0666);

    semid = semget(key+1, 1, 0644 | IPC_CREAT);  // Create semaphore
    arg.val = 1;
    semctl(semid, 0, SETVAL, arg);  // Initialize semaphore to 1

    struct sembuf sb;
    sb.sem_num = 0;
    sb.sem_op = -1;  // Wait until the semaphore is available
    sb.sem_flg = 0;

    printf("Waiting for semaphore\n");
    semop(semid, &sb, 1);  // Wait (decrement)

    // In critical section
    printf("In critical section:\n");
    printf("Enter data:\n");    
    data = (int *)shmat(shmid, (void *)0, 0);
    scanf("%d", data);
    
    printf("Press enter to unlock semaphore.");

    getchar();
    getchar();
    sb.sem_op = 1;  // Signal (increment)
    semop(semid, &sb, 1);  // Release the semaphore

    printf("Exiting critical section\n");

    return 0;
}
/*
Output:
Waiting for semaphore
In critical section:
Enter data:
7
Press enter to unlock semaphore.
Exiting critical section

*/