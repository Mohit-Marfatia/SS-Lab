/*
============================================================================
Name : 1b.c
Author : Mohit Marfatia
Description : Create the following types of a files using (i) shell command (ii) system call
b. hard link (link system call)
Date: 8th Aug, 2024.
============================================================================
*/

#include <unistd.h>

int main(void){
	link("./1a.c", "link_example");
	return 0;
}

/*
Output:
6031851 -rw-rw-r-- 2 mohit-marfatia mohit-marfatia    539 Aug 31 17:14 1a.c
6031851 -rw-rw-r-- 2 mohit-marfatia mohit-marfatia    539 Aug 31 17:14 link_example

*/
