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


#include<fcntl.h>
#include<stdio.h>
#include "definition.h"

int main(){
	TicketDatabase db;
	int fd = open("tickets.txt", O_RDWR | O_CREAT, 0666);
	if(fd<0){
		perror("Error opening the file ");
	}
	struct flock lock;
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;

	printf("Waiting to implement write lock\n");

	int writeLock = fcntl(fd, F_SETLKW, &lock);
	if(writeLock<0){
		perror("Error setting the write lock");
		close(fd);
	}
	printf("Write lock implemented, press enter to book ticket");
	getchar();

	lseek(fd, -1 * sizeof(db), SEEK_SET);
	read(fd, &db, sizeof(db));
	printf("previously booked ticket num is %d\n Now incrementing...", db.ticket_num);

	db.ticket_num += 1;
	printf("booking ticket num %d\n", db.ticket_num);
	lseek(fd, -1 * sizeof(db), SEEK_CUR);
	write(fd, &db, sizeof(db));

	lock.l_type = F_UNLCK;
	writeLock = fcntl(fd, F_SETLK, &lock);
	if(writeLock<0){
		perror("error unlocking ");
		close(fd);
	}
	printf("Ticket Booked\n");
	close(fd);
	return 0;
}

/*
Output:
Waiting to implement write lock
Write lock implemented, press enter to book ticket
previously booked ticket num is 10
 Now incrementing...booking ticket num 11
Ticket Booked

*/