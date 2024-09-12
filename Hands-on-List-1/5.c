/*
============================================================================
Name : 5.c
Author : Mohit Marfatia
Description : Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd
Date: 8th Aug, 2024.
============================================================================
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

/*
Output:
(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise$ ./a.out &
[1] 11376
(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise$ ls -l /proc/11376/fd
total 0
lrwx------ 1 mohit-marfatia mohit-marfatia 64 Sep  7 15:18 0 -> /dev/pts/0
lrwx------ 1 mohit-marfatia mohit-marfatia 64 Sep  7 15:18 1 -> /dev/pts/0
lrwx------ 1 mohit-marfatia mohit-marfatia 64 Sep  7 15:18 2 -> /dev/pts/0
l-wx------ 1 mohit-marfatia mohit-marfatia 64 Sep  7 15:18 3 -> /home/mohit-marfatia/College/Software-Systems/exercise/file0
l-wx------ 1 mohit-marfatia mohit-marfatia 64 Sep  7 15:18 4 -> /home/mohit-marfatia/College/Software-Systems/exercise/file1
l-wx------ 1 mohit-marfatia mohit-marfatia 64 Sep  7 15:18 5 -> /home/mohit-marfatia/College/Software-Systems/exercise/file2
l-wx------ 1 mohit-marfatia mohit-marfatia 64 Sep  7 15:18 6 -> /home/mohit-marfatia/College/Software-Systems/exercise/file3
l-wx------ 1 mohit-marfatia mohit-marfatia 64 Sep  7 15:18 7 -> /home/mohit-marfatia/College/Software-Systems/exercise/file4


*/