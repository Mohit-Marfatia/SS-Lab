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
        bytes_read = read(0, buffer, buffer_size);
        perror("Read:");
	printf("%ld", bytes_read); //will wait till whole program is executed. To prevent this use fflush(stdout) or use \n
        write(1, buffer, bytes_read);
        perror("Write:");
}
