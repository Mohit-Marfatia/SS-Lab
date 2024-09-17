/*
============================================================================
Name : 1a.c
Author : Mohit Marfatia
Description : Write a separate program (for each time domain) to set a interval timer in 10sec and 10 micro second
b. ITIMER_VIRTUAL
Date: 12th Sept, 2024.
============================================================================
*/

#include<stdio.h>
#include<sys/time.h>
#include<signal.h>

void timerHandler(){
    printf("Timer has expired.\n");
}

int main(void) {
    struct itimerval timer;
	signal(SIGALRM, timerHandler);

    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 0;

    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 0;

    int setITimer = setitimer(ITIMER_VIRTUAL, &timer, NULL);
    if(setITimer == -1){
        perror("Set ITIMER_VIRTUAL:");
    }

    while(1);
	return 0;
}

/*
Output:
Virtual timer expired

*/