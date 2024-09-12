/*
============================================================================

Name : 16.c
Author: Mohit Marfatia
Problem: Write a program to perform mandatory locking.
a. Implement write lock
Date: 29th Aug, 2024.
============================================================================
*/

#include<fcntl.h>
#include<stdio.h>

int main(){
	struct flock lock;
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;

	int fd = open("16temp.txt", O_RDWR | O_CREAT, 0660);
	if(fd<0){
		printf("Error opening the file\n");
	}

	printf("Waiting to implement write lock\n");
	int setLock = fcntl(fd, F_SETLKW, &lock);
	if(setLock<0){
		printf("Error in setting write lock\n");
		close(fd);
	}
	printf("Implementing write lock...\n Press enter to unlock and come out of critical section!");
	getchar();

	lock.l_type = F_UNLCK;
	setLock = fcntl(fd, F_SETLK, &lock);
	if(setLock<0){
		printf("Error in unlocking\n");
		close(fd);
	}
	printf("Successfully unlocked and out of critical section!\n");

	close(fd);
	return 0;
}

/*
Enter into critical section:

Output in Terminal 1:
Waiting to implement write lock
Implementing write lock...
 Press enter to unlock and come out of critical section!

Output in Terminal 2:
Waiting to implement write lock

Exiting critical section:

Output in Terminal 1:
Waiting to implement write lock
Implementing write lock...
 Press enter to unlock and come out of critical section!
Successfully unlocked and out of critical section!

Output in Terminal 2:
Waiting to implement write lock
Implementing write lock...
 Press enter to unlock and come out of critical section!

*/
