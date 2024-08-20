/*
Name: Mohit Marfatia
Reg No.: MT2024090
Problem: Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl
*/

#include<stdio.h>
#include<fcntl.h>

int main(){
	int fd1 = open("temp_dup.txt", O_CREAT | O_RDWR, 0777);
	int fd_dup = dup(fd1);
	write(fd1, "written using fd1\n", 20);
	write(fd_dup, "written using fd_dup\n", 20);
	printf("fd1: %d, fd_dup: %d\n", fd1, fd_dup);
	close(fd1);
	close(fd_dup);
	int fd2 = open("temp_dup2.txt", O_CREAT | O_RDWR, 0777);
	int fd_dup2 = dup2(fd2, 87);
	write(fd2, "written using fd2\n", 20);
	write(fd_dup2, "written using fd_dup2\n", 20);
	printf("fd2: %d, fd_dup2: %d\n", fd2, fd_dup2);
	close(fd2);
	close(fd_dup2);
	int fd3 = open("temp_fcntl.txt", O_CREAT | O_RDWR, 0777);
	int fd_fcntl = dup2(fd3, F_DUPFD, 0);
	write(fd2, "written using fd2\n", 20);
	write(fd_dup2, "written using fd_fcntl\n", 20);
	printf("fd2: %d, fd_fcntl: %d\n", fd2, fd_fcntl);
	close(fd2);
	close(fd_fcntl);
}
