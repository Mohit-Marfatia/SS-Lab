/*
============================================================================

Name : 19d.c
Author: Mohit Marfatia
Problem: Create a FIFO file by
d. mknod system call
Date: 18th Sept, 2024.
============================================================================
*/
#include<sys/stat.h>

int main() {
	mknod("./19d_fifo", S_IFIFO | 0744, 0);
}

/*
Output:
ls -l 19d_fifo 
prwxr--r-- 1 mohit-marfatia mohit-marfatia 0 Sep 19 09:12 19d_fifo

*/