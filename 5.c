/*
Name: Mohit Marfatia
Reg. No.: MT2024090
Problem: Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd
*/

#include<stdio.h>
#include<fcntl.h>

int main(void){
	char filename[6];
	for(int i = 0; i < 5; ++i){
		snprintf(filename, sizeof(filename), "file%d", i);
		int fd = creat(filename, 0744);
		if(fd == -1) perror("error: ");
	}
	while(1);
}
