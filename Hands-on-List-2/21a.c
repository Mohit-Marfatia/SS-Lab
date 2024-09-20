/*
============================================================================

Name : 21.c
Author: Mohit Marfatia
Problem: Write two programs so that both can communicate by FIFO -Use two way communication.
Date: 18th Sept, 2024.
============================================================================
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    int fd1, fd2;
    char buff_r[100], buff_w[100];
    mkfifo("21_fifo1", 0666);
    mkfifo("21_fifo2", 0666);
    fd1 = open("21_fifo1", O_RDWR);
    fd2 = open("21_fifo2", O_RDWR);
    if (fd2 == -1 || fd1 == -1) {
        printf("There is some error..\n");
    }
    while (1){
        printf("Enter the message..\n");
        fgets(buff_w, sizeof(buff_w), stdin);
        write(fd1, buff_w, sizeof(buff_w));
        read(fd2, buff_r, sizeof(buff_r));
        printf("Message from the FIFO is... %s", buff_r);
    }
    return 0;
}