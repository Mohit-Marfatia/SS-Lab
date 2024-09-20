/*
============================================================================

Name : 27b.c
Author: Mohit Marfatia
Problem: Write a program to receive messages from the message queue.
b. with IPC_NOWAIT as a flag
Date: 19th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>

struct msg_buffer {
    long msg_type;
    char msg_text[512];
};
int main() {
    key_t key;
    int msgid;
    struct msg_buffer message;
    key = ftok(".", 'M');
    msgid = msgget(key, 0666);
    while (1) {
        ssize_t result = msgrcv(msgid, (void*)&message, 512, 0, IPC_NOWAIT);
        if (result == -1) {
                break;
            }
        printf("Received Message Type: %ld\n", message.msg_type);
        printf("Message Text: %s\n", message.msg_text);
        printf("----------------------------\n");
    }

    return 0;
}


/*
Output:
(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise/Hands-on-List-2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x4203358b 0          mohit-marf 666        0            0           
0x4d03358b 1          mohit-marf 666        0            0 
(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise/Hands-on-List-2$ cc 27b.c
(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise/Hands-on-List-2$ ./a.out
(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise/Hands-on-List-2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x4203358b 0          mohit-marf 666        0            0           
0x4d03358b 1          mohit-marf 666        512          1 
(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise/Hands-on-List-2$ cc 27b.c
(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise/Hands-on-List-2$ ./a.out
Received Message Type: 1
Message Text: Hello!!
----------------------------

(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise/Hands-on-List-2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x4203358b 0          mohit-marf 666        0            0           
0x4d03358b 1          mohit-marf 666        0            0  
*/