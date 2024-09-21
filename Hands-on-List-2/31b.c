/*
============================================================================

Name : 31a.c
Author: Mohit Marfatia
Problem: Write a program to create a semaphore and initialize value to the semaphore.
b. create a counting semaphore
Date: 20th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/sem.h>

union semun{
    int val;
    struct semid_ds *buf;
    int key, semid;
};

int main(){
    union semun arg;
    int key, semid;

    key = ftok(".", 'n');
    semid = semget(key, 1, 0644 | IPC_CREAT);
    arg.val = 5;
    semctl(semid, 0, SETVAL, arg);
    printf("Semaphore id = %d\n", semid);

    return 0;
}

/*
Output:
(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise/Hands-on-List-2$ ./a.out
Semaphore id = 3
(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise/Hands-on-List-2$ ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems     
0x00105b6b 0          root       600        1         
0x00105b6c 1          root       666        2         
0x6d03358b 2          mohit-marf 644        1         
0x6e03358b 3          mohit-marf 644        1 
*/