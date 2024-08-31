/*
============================================================================
Name : 1c.c
Author : Mohit Marfatia
Description : Create the following types of a files using (i) shell command (ii) system call
c. FIFO (mkfifo Library Function or mknod system call)
Date: 8th Aug, 2024.
============================================================================
*/

#include<fcntl.h>
int main() {
	mknod("./1c_fifo", S_IFIFO | 0744, 0);
}

/*
Output:
prwxr--r-- 1 mohit-marfatia mohit-marfatia      0 Aug 22 08:41 1c_fifo|

*/
