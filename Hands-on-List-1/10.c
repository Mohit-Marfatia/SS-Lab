/*
============================================================================
Name : 10.c
Author : Mohit Marfatia
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
Date: 18th Aug, 2024.
============================================================================
*/


#define _GNU_SOURCE
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdint.h>

int main(){
	int fd = creat("10.txt", O_RDWR);
	char temp[5] = "12345";
	printf("Writing %s to 10.text\n", temp);
	write(fd, temp, 5);
	off_t offset = lseek(fd, 10, SEEK_SET); 
	printf("File cursor at %ld\n", offset);
	char temp2[5] = "54321";
	printf("Writing %s to 10.text\n", temp2);
	write(fd, temp2, 5);
	close(fd);

	// int fd = creat("10_2.txt", 0666);
	 fd = open("10.txt", O_RDONLY);
	// int write_val = 0x22;
	// off_t offset = lseek(fd, 10, SEEK_SET);
	// write(fd, &write_val, sizeof(write_val));
	off_t offset2 = lseek(fd, 7, SEEK_DATA);

	printf("seek_data:%ld\n", offset2);
}

/*
Output:
(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise$ ./a.out
Writing 0123456789 to 10.text
File cursor at 20
Writing 9876543210 to 10.text
(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise$ cat 10.txt 
012345543210
(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise$ od -c 10.txt
0000000   0   1   2   3   4   5  \0  \0  \0  \0   5   4   3   2   1   0
0000020  \0  \0  \0  \0
0000024


*/