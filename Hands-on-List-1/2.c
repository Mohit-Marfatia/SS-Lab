/*
============================================================================
Name : 2.c
Author : Mohit Marfatia
Description : Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
identify all the process related information in the corresponding proc directory.
Date: 8th Aug, 2024.
============================================================================
*/

//#include<stdio.h>

int main(){
	for(;;){}
}

/*
Output:
(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise$ ./a.out &
[1] 10454
(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise$ cat /proc/10454/status
Name:	a.out
Umask:	0002
State:	R (running)
Tgid:	10454
Ngid:	0
Pid:	10454
PPid:	7383

*/
