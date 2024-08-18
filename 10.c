#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
	int fd = creat("10.text", O_RDWR);
	char temp[10] = "0123456789";
	printf("Writing %s to 10.text", temp);
	write(fd, temp, 10);
	off_t offset = lseek(fd, 10, SEEK_CUR); 
	printf("File cursor at %d", offset);
	char temp2[10] = "9876543210";
	printf("Writing %s to 10.text", temp2);
	write(fd, temp, 10);
	close(fd);
}
