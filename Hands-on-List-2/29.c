/*
============================================================================

Name : 29.c
Author: Mohit Marfatia
Problem: Write a program to remove the message queue.
Date: 20th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t key;
    int msgid;
    key = ftok(".", 'M');
    msgid = msgget(key, 0744);
    msgctl(msgid, IPC_RMID, NULL);
    printf("Message Queue removed successfully.\n");
    return 0;
}

/*
Output:
(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise/Hands-on-List-2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x4d03358b 0          mohit-marf 744        512          1           

(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise/Hands-on-List-2$ cc 29.c
(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise/Hands-on-List-2$ ./a.out
Message Queue removed successfully.
(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise/Hands-on-List-2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    

*/