/*
Name: Mohit Marfatia
Reg. No.: MT2024090
Problem: Write a program to find out the opening mode of a file. Use fcntl.
*/

#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>

int main(){
	int fd = open("temp_dup.txt", O_RDWR | O_APPEND, 0644);
	int flags = fcntl(fd, F_GETFL);

	int accessMode = flags & O_ACCMODE;
	printf("flags: %d, O_ACCMODE: %d, accessMode: %d\n", flags, O_ACCMODE, accessMode);

	printf("File access mode: ");
	if(accessMode == O_RDONLY) printf("Read only\n");
	else if(accessMode == O_WRONLY) printf("Write only\n");
 	else if(accessMode == O_RDWR) printf("Read and Write\n");

	if(flags & O_APPEND) printf("File is opened in append mode.\n");
	if(flags & O_NONBLOCK)  printf("File is opened in non-blocking mode.\n");
	if(flags & O_SYNC)  printf("File is opened in synchronous mode.\n");

	close(fd);
}
