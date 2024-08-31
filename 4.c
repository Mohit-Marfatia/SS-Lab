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
	printf("File descriptor value: %d\n", creat("4.txt", O_RDWR));
	perror("File descriptor");
	printf("File descriptor value: %d\n", creat("4.txt", O_EXCL));
	perror("File descriptor");
}

/*
Output:
File descriptor value: 3
File descriptor: Success
File descriptor value: 4
File descriptor: Success

*/