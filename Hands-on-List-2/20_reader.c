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
int main()
{
    int fd = open("20_fifo", O_RDONLY);
    char buffer[100];
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer));
    printf("Reader process received: ");
    printf("%s\n", buffer);
    close(fd);
    unlink("20_fifo");
    return 0;
}

/*
(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise/Hands-on-List-2$ ./20_reader 
Reader process received: Hello, FIFO!�
*/