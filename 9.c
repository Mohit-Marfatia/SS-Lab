/*
Name: Mohit Marfatia
Reg. No.: MT2024090
Problem: Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {

	struct stat fileStats;
	if (stat(argv[1], &fileStats) == -1) {
               perror("stat");
               exit(EXIT_FAILURE);
           }


	printf("inode: %ld\n", fileStats.st_ino);
	printf("number of hard links: %ld\n", fileStats.st_nlink);
	printf("uid: %u\n", fileStats.st_uid);
	printf("gid: %d\n", fileStats.st_gid);
	printf("size: %ld bytes\n", fileStats.st_size);
	printf("block size: %ld bytes\n", fileStats.st_blksize);
	printf("number of blocks: %ld\n", fileStats.st_blocks);;
	printf("time of last access: %s", ctime(&fileStats.st_atime));
	printf("time of last modification: %s", ctime(&fileStats.st_mtime));
	printf("time of last change: %s", ctime(&fileStats.st_ctime));

	return 0;
}
