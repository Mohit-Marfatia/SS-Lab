/*
============================================================================

Name : 32cd.c
Author: Mohit Marfatia
Problem: Write a program to implement semaphore to protect any critical section.
c. protect multiple pseudo resources ( may be two) using counting semaphore
d. remove the created semaphore
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

// Global variable to hold the semaphore ID
int semid;

// Function to perform semop operation
void semaphore_operation(int semid, int sem_num, int op) {
    struct sembuf sop;
    sop.sem_num = sem_num;  // Specify which semaphore (0 or 1)
    sop.sem_op = op;        // -1 for wait (P), 1 for signal (V)
    sop.sem_flg = 0;
    semop(semid, &sop, 1);  // Perform the operation on the semaphore
}

int main() {
    key_t key;
    SemUnion sem_union;
    // Generate unique key
    key = ftok("semfile", 65);
    
    // Create a semaphore set with 2 semaphores
    semid = semget(key, 2, 0666 | IPC_CREAT);
    if (semid == -1) {
        perror("semget failed");
        exit(1);
    }
    
    // Initialize the semaphores to 1 (both resources available)
    sem_union.val = 1;
    semctl(semid, 0, SETVAL, sem_union);  // Semaphore for resource 1
    semctl(semid, 1, SETVAL, sem_union);  // Semaphore for resource 2
    
    // Simulating resource access
    printf("Process is trying to access resource 1...\n");
    semaphore_operation(semid, 0, -1);  // P (wait) operation on resource 1
    printf("Resource 1 acquired!\n");
    sleep(2);  // Simulate critical section
    
    printf("Process is trying to access resource 2...\n");
    semaphore_operation(semid, 1, -1);  // P (wait) operation on resource 2
    printf("Resource 2 acquired!\n");
    sleep(2);  // Simulate critical section
    
    printf("Releasing resource 1...\n");
    semaphore_operation(semid, 0, 1);  // V (signal) operation on resource 1
    
    printf("Releasing resource 2...\n");
    semaphore_operation(semid, 1, 1);  // V (signal) operation on resource 2
    
    // Cleanup semaphore set (IPC_RMID) explicitly before exiting
    printf("Removing semaphore set...\n");
    semctl(semid, 0, IPC_RMID);  // Remove the semaphore set

    return 0;
}

/*
Output:
Process is trying to access resource 1...
Resource 1 acquired!
Process is trying to access resource 2...
Resource 2 acquired!
Releasing resource 1...
Releasing resource 2...
Removing semaphore set...

*/