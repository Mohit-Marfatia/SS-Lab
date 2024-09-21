/*
============================================================================

Name : 28.c
Author: Mohit Marfatia
Problem: Write a program to change the exiting message queue permission. (use msqid_ds structure)
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
    msgid = msgget(key, 0666);
    struct msqid_ds msq_info;
    msgctl(msgid, IPC_STAT, &msq_info);
    printf("Original Permission: %#o\n", msq_info.msg_perm.mode);
    msq_info.msg_perm.mode=0744;
    msgctl(msgid, IPC_SET, &msq_info);
    printf("Updated Permission: %#o\n", msq_info.msg_perm.mode);
    return 0;
}

/*
Output:
(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise/Hands-on-List-2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x4d03358b 0          mohit-marf 666        512          1           

(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise/Hands-on-List-2$ cc 28.c
(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise/Hands-on-List-2$ ./a.out
Original Permission: 0666
Updated Permission: 0744
(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise/Hands-on-List-2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x4d03358b 0          mohit-marf 744        512          1 
*/