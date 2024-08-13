/*
Name: Mohit Marfatia
Reg. No.: MT2024090
Problem: Write a program to copy file1 into file2 ($cp file1 file2).
*/
#include<stdio.h>
#include<fcntl.h>

int main(){
	int source_file = open("./6.c", O_RDONLY);
	printf("source fd: %d", source_file);
	perror("Read from source file: ");
	int dest_file = open("./6_copy.txt", O_CREAT | O_RDWR, 0644);

	int buffer_size = 2048;
	char buffer[buffer_size];

	ssize_t bytes_read, bytes_written;
	bytes_read = read(source_file, buffer, buffer_size);
	perror("Bytes read from source file: ");
	bytes_written = write(dest_file, buffer, bytes_read);
	perror("Bytes written from source file: ");

}
