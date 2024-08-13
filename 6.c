/*
Name: Mohit Marfatia
Reg No.: MT2024090
Problem: Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
*/

#include <unistd.h>
#include <stdio.h>

int main(void) {
	int buffer_size = 80;
	ssize_t bytes_read, bytes_written;
	char buffer[buffer_size];
        bytes_read = read(STDIN_FILENO, buffer, buffer_size);
        perror("Read:");
	printf("%ld", bytes_read);
        write(STDOUT_FILENO, buffer, bytes_read);
        perror("Write:");
}
