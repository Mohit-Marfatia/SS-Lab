/*
============================================================================

Name : 26.c
Author: Mohit Marfatia
Problem: Write a program to send messages to the message queue. Check $ipcs -q
Date: 19th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
struct msg_buffer 
{
    long msg_type;
    char msg_text[512];
};
int main() 
{
    key_t key;
    int msgid;
    struct msg_buffer message;
    key = ftok(".", 'M');
    msgid = msgget(key, 0666);
    message.msg_type = 1;
    printf("Enter a message to send to the message queue:\n");
    fgets(message.msg_text, 512, stdin);
    size_t len = strlen(message.msg_text);
    if (len > 0 && message.msg_text[len - 1] == '\n') 
    {
        message.msg_text[len - 1] = '\0';
    }
    msgsnd(msgid, (void*)&message, 512, 0);
    printf("Message sent to the message queue.\n");
    return 0;
}

/*
Output:
(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise/Hands-on-List-2$ ./a.out
Enter a message to send to the message queue:
Hello!!
Message sent to the message queue.
(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise/Hands-on-List-2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x4203358b 0          mohit-marf 666        0            0           
0x4d03358b 1          mohit-marf 666        512          1 

(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise/Hands-on-List-2$ ./a.out
Enter a message to send to the message queue:
Hii!!
Message sent to the message queue.
(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise/Hands-on-List-2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x4203358b 0          mohit-marf 666        0            0           
0x4d03358b 1          mohit-marf 666        1024         2  
*/