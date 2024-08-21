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
