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