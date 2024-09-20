/*
============================================================================

Name : 27a.c
Author: Mohit Marfatia
Problem: Write a program to receive messages from the message queue.
a. with 0 as a flag
Date: 19th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
struct  msg_buffer {
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
        msgrcv(msgid, (void*)&message, 512, 0, 0);
        printf("Received Message Type: %ld\n", message.msg_type);
        printf("Message Text: %s\n", message.msg_text);
        printf("----------------------------\n");
    }
    exit(0);
    return 0;
}

/*
Output:
(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise/Hands-on-List-2$ cc 27a.c
(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise/Hands-on-List-2$ ./a.out
Received Message Type: 1
Message Text: Hello!!
----------------------------
Received Message Type: 1
Message Text: Hii!!
----------------------------
^C
(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise/Hands-on-List-2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x4203358b 0          mohit-marf 666        0            0           
0x4d03358b 1          mohit-marf 666        0            0  
*/