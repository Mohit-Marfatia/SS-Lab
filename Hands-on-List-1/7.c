/*
============================================================================
Name : 7.c
Author : Mohit Marfatia
Description : Write a program to copy file1 into file2 ($cp file1 file2).
Date: 13th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[]){
	int source_file = open(argv[1], O_RDONLY);
	perror("Read from source file: ");
	if(source_file < 0){
		exit(0);
	}
	int dest_file = open(argv[2], O_CREAT | O_RDWR, 0600);

	//int buffer_size = 1024;
	char buffer[1024];

	int bytes_read, bytes_written;
	while((bytes_read = read(source_file, buffer, sizeof(buffer))) > 0) {
		write(dest_file, buffer, bytes_read);
	}
	//perror("Bytes read from source file: ");
	printf("Write success\n");
	//perror("Bytes written from source file: ");
	close(source_file);
	close(dest_file);

}

/*
Output:
Read from source file: : Success
Write success
*/