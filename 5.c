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
(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise$ cat /proc/11376/fd
cat: /proc/11376/fd: Is a directory

-rwxr--r-- 1 mohit-marfatia mohit-marfatia      0 Aug  8 22:49  file0*
-rwxr--r-- 1 mohit-marfatia mohit-marfatia      0 Aug  8 22:49  file1*
-rwxr--r-- 1 mohit-marfatia mohit-marfatia      0 Aug  8 22:49  file2*
-rwxr--r-- 1 mohit-marfatia mohit-marfatia      0 Aug  8 22:49  file3*
-rwxr--r-- 1 mohit-marfatia mohit-marfatia      0 Aug  8 22:49  file4*

*/