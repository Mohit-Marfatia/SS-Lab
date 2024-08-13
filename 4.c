/*
Name: Mohit Marfatia
Reg. No.: MT2024090
Problem: Write a program to open an existing file with read write mode. Try O_EXCL flag also.
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
