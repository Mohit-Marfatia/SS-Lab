/*
============================================================================

Name : 8d.c
Author: Mohit Marfatia
Problem: Write a separate program using signal system call to catch the following signals.
d. SIGALRM (use alarm system call)
Date: 17th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigvtalrm_handler(int signo) {
    if (signo == SIGALRM) {
        printf("Caught SIGALRM (Alarm signal)\n");
        exit(EXIT_SUCCESS);
    }
}

int main() {
    signal(SIGALRM, sigvtalrm_handler);

    printf("Setting an alarm to go off in 2 seconds...\n");
    alarm(2);

    pause();

    printf("This line will not be executed.\n");

    return 0;
}

/*
Output:
Setting an alarm to go off in 2 seconds...
Caught SIGALRM (Alarm signal)

*/