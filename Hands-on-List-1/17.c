/*
============================================================================

Name : 17.c
Author: Mohit Marfatia
Problem: Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
Date: 30th Aug, 2024.
============================================================================
*/


#include<stdio.h>
#include<fcntl.h>
#include "definition.h"

int main(){
	TicketDatabase db;
	int fd;
	fd = open("tickets.txt", O_RDWR | O_CREAT, 0666);
	perror("fd:");
	db.ticket_num = 10;
	write(fd, &db, sizeof(db));
	perror("write:");
	close(fd);
	return 0;
}

/*
Output: 
fd:: Success
write:: Success

*/