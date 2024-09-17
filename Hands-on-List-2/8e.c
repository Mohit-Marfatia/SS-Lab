/*
============================================================================

Name : 8e.c
Author: Mohit Marfatia
Problem: Write a separate program using signal system call to catch the following signals.
e. SIGALRM (use setitimer system call)
Date: 17th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>

void sigvtalrm_handler(int signo) {
    if (signo == SIGALRM) {
        printf("Caught SIGALRM (setitimer signal)\n");
        exit(EXIT_SUCCESS);
    }
}

int main() {
    signal(SIGALRM, sigvtalrm_handler);

    printf("Setting a timer to go off in 2 seconds...\n");
    struct itimerval timer;
    
    timer.it_value.tv_sec = 2; 
    timer.it_value.tv_usec = 0; 

    if (setitimer(ITIMER_REAL, &timer, NULL) == -1) {
        perror("setitimer");
        exit(EXIT_FAILURE);
    }

    pause();

    printf("This line will not be executed.\n");

    return 0;
}

/*
Output:
Setting a timer to go off in 2 seconds...
Caught SIGALRM (setitimer signal)

*/