/*
============================================================================

Name : 31a.c
Author: Mohit Marfatia
Problem: Write a program to create a semaphore and initialize value to the semaphore.
a. create a binary semaphore
Date: 20th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/sem.h>
#include "definition.h"

int main(){
    SemUnion arg;
    int key, semid;

    key = ftok(".", 'm');
    semid = semget(key, 1, 0644 | IPC_CREAT);
    arg.val = 1;
    semctl(semid, 0, SETVAL, arg);
    printf("Semaphore id = %d\n", semid);

    return 0;
}

/*
Output:
(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise/Hands-on-List-2$ ./a.out
Semaphore id = 2
(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise/Hands-on-List-2$ ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems     
0x00105b6b 0          root       600        1         
0x00105b6c 1          root       666        2         
0x6d03358b 2          mohit-marf 644        1   
*/