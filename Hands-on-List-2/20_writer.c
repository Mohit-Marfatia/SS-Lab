/*
============================================================================

Name : 20.c
Author: Mohit Marfatia
Problem: Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 18th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main() 
{
    mkfifo("20_fifo", 0666);
    int fd = open("20_fifo", O_WRONLY);
    const char *message = "Hello, FIFO!";
    write(fd, message, strlen(message));
    printf("Writer process sent: %s\n", message);
    close(fd);
    return 0;
}

/*
Output: 
(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise/Hands-on-List-2$ ./20_writer 
Writer process sent: Hello, FIFO!

*/