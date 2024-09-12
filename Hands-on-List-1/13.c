/*
============================================================================
Name : 13.c
Author : Mohit Marfatia
Description : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 21st Aug, 2024.
============================================================================
*/


#include<stdio.h>
#include<stdlib.h>
#include<sys/select.h>

int main() {
	struct timeval tout;
	fd_set readfds;
	int retval;

	FD_ZERO(&readfds);
	FD_SET(0, &readfds);

	tout.tv_sec = 10;
	tout.tv_usec = 0;

	retval = select(1, &readfds, NULL, NULL, &tout);

	if(retval == -1) perror("select()");
	else if(retval == 0) printf("No data entered within 10 secs. \n");
	else printf("Data available now.");

}

/*
Output: 
(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise$ ./a.out
No data entered within 10 secs. 
(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise$ ./a.out
a
Data available now.
*/