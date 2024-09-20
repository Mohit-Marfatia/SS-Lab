/*
============================================================================

Name : 24.c
Author: Mohit Marfatia
Problem: Write a program to create a message queue and print the key and message queue id.
Date: 19th Sept, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() 
{
    key_t key;
    int msgid;
    key = ftok(".", 'M');
    msgid = msgget(key, 0666 | IPC_CREAT);
    printf("Key: %x\n", (unsigned int)key);
    printf("Message Queue ID: %d\n", msgid);
    return 0;
}

/*
Output:
(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise/Hands-on-List-2$ ./a.out
Key: 4203358b
Message Queue ID: 0
(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise/Hands-on-List-2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x4203358b 0          mohit-marf 666        0            0   

(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise/Hands-on-List-2$ ./a.out
Key: 4d03358b
Message Queue ID: 1
(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise/Hands-on-List-2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x4203358b 0          mohit-marf 666        0            0           
0x4d03358b 1          mohit-marf 666        0            0 
*/