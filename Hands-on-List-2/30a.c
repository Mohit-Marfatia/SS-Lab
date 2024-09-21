/*
============================================================================

Name : 30a.c
Author: Mohit Marfatia
Problem: Write a program to create a shared memory.
a. write some data to the shared memory
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
    data = (char *)shmat(shmid, (void *)0, 0);
    scanf(" %[^\n]", data);
    printf("Data in shared memory: %s\n", data);

    // sleep(10);
    return 0;
}

/*
Output:
(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise/Hands-on-List-2$ ./a.out
Writing to shared memory...
Data in shared memory: Hello, Shared Memory!
(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise/Hands-on-List-2$ ipcs -m

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status  
0x6d03358b 32802      mohit-marf 666        1024       0  
*/