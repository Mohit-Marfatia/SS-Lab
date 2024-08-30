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
