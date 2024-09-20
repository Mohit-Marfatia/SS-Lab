/*
============================================================================

Name : 21.c
Author: Mohit Marfatia
Problem: Write two programs so that both can communicate by FIFO -Use two way communication.
Date: 18th Sept, 2024.
============================================================================
*/


#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    int fd1, fd2;
    char buff_r[100], buff_w[100];
    fd1 = open("21_fifo1", O_WRONLY);
    fd2 = open("21_fifo2", O_RDONLY);
    while (1)
    {
        read(fd1, buff_r, sizeof(buff_r));
        printf("Message from pipe is..%s\n", buff_r);
        printf("Enter the message: \n");
        fgets(buff_w, sizeof(buff_w), stdin);
        write(fd2, buff_w, sizeof(buff_w));
    }
    return 0;
}