#include<stdio.h>
#include<fcntl.h>

int main(){
	struct flock lock;
	lock.l_type = F_RDLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;

	int fd = open("16temp.txt", O_RDONLY);
	if(fd<0){
		perror("error opening the file");
	}

	printf("Waiting to implement read lock...\n");
	int setLock = fcntl(fd, F_SETLKW, &lock);
	if(setLock<0){
		perror("error setting read lock\n");
		close(fd);
	}

	printf("Implementing Read Lock...\n Press enter to unlock and come out of critical section!\n");
	getchar();
	lock.l_type = F_UNLCK;
	setLock = fcntl(fd, F_SETLK, &lock);
	if(setLock<0){
		perror("Error unlocking file\n");
		close(fd);
	}
	printf("Successfully read and out of critical section!\n");

	close(fd);
	return 0;
}
