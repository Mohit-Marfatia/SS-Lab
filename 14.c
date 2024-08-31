/*
============================================================================
Name : 14.c
Author : Mohit Marfatia
Description : Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.
Date: 22nd Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<sys/stat.h>
#include<stdlib.h>

void print_file_type(struct stat *fileStat){
	switch(fileStat->st_mode & S_IFMT) {
		case S_IFBLK: 
			printf("block device\n");
			break;
		case S_IFCHR:
			printf("character device\n");
			break;
		case S_IFDIR:
			printf("directory\n");
			break;
		case S_IFIFO:
			printf("FIFO/pipe\n");
			break;
		case S_IFLNK:
			printf("symlink\n");
			break;
		case S_IFREG:
			printf("regular file\n");
			break;
		case S_IFSOCK:
			printf("socket\n");
			break;
		default:
			printf("unknown?\n");
			break;
	}
}

int main(int argc, char *argv[]){
	struct stat fileStat;
	if(argc !=2){
		fprintf(stderr, "Input a file");
		exit(EXIT_FAILURE);
	}
	
	lstat(argv[1], &fileStat);

	printf("File type:  ");
	print_file_type(&fileStat);
}

/*
Output:
(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise$ ./a.out 1c_fifo 
File type:  FIFO/pipe

*/