/*
============================================================================
Name : 12.c
Author : Mohit Marfatia
Description : Write a program to find out the opening mode of a file. Use fcntl.
Date: 21st Aug, 2024.
============================================================================
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

/*
Output:
flags: 33794, O_ACCMODE: 3, accessMode: 2
File access mode: Read and Write
File is opened in append mode.

*/