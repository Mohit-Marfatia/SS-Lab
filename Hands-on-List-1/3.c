/*
============================================================================
Name : 3.c
Author : Mohit Marfatia
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call
Date: 8th Aug, 2024.
============================================================================
*/
#include<fcntl.h>
#include<stdio.h>
#include<errno.h>

int main(void){
	printf("File descriptor value: %d\n", creat("3.txt", 0744));
	perror("File descriptor");
}

/*
Output:

File descriptor value: 3
File descriptor: Success

-rwxr--r-- 1 mohit-marfatia mohit-marfatia      0 Aug  8 23:25  3.txt*
*/
