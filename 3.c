/*
Name: Mohit Marfatia
Reg. No.: MT2024090
Problem: Write a program to create a file and print the file descriptor value. Use creat ( ) system call
*/

#include<fcntl.h>
#include<stdio.h>
#include<errno.h>

int main(void){
	printf("File descriptor value: %d\n", creat("3.txt", 0744));
	perror("File descriptor");
}
