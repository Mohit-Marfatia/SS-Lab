/*
============================================================================
Name : 4.c
Author : Mohit Marfatia
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 8th Aug, 2024.
============================================================================
*/
#include<fcntl.h>
#include<stdio.h>
#include<errno.h>

int main(void){
	int fd = open("4.txt", O_RDWR);
    if (fd == -1) {
        perror("Error opening the file in read-write mode");
    } else {
        printf("File opened successfully with read-write mode, file descriptor: %d\n", fd);
        close(fd);
    }

    fd = open("4.txt", O_CREAT | O_EXCL, 0644);
    if (fd == -1) {
        perror("Error opening the file with O_EXCL (file must already exist)");
    } else {
        printf("File opened successfully with O_EXCL, file descriptor: %d\n", fd);
        close(fd);
    }
}

/*
Output:
File opened successfully with read-write mode, file descriptor: 3
Error opening the file with O_EXCL (file must already exist): File exists

*/