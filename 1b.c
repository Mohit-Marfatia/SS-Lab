/*
Name: Mohit Marfatia
Reg. No.: MT2024090
Problem: Create the following types of a files using (i) shell command (ii) system call
b. hard link (link system call)
*/
#include <unistd.h>

int main(void){
	link("./1a.c", "link_example");
	return 0;
}
