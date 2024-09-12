/*
============================================================================

Name : 20.c
Author: Mohit Marfatia
Problem: Find out the priority of your running program. Modify the priority with nice command.
Date: 30th Aug, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <errno.h>

int main(void){
    	printf("Program 20..\n");
    	int x;

    	x = nice(0);
    	if (x == -1){
        	perror("Error setting priority: ");
    	}
    	else{
        	printf("Current priority of the process is %d..\n", x);
    	}

    	int y;
    	y = nice(5);
    	if (y == -1){
        	perror("Error setting priority: ");
    	}
    	else{
        	printf("Current priority of the process is %d..\n", y);
	}

    	return 0;
}

/*
Output:
Program 20..
Current priority of the process is 0..
Current priority of the process is 5..
*/
