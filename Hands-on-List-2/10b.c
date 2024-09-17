/*
============================================================================

Name : 10b.c
Author: Mohit Marfatia
Problem: Write a separate program using sigaction system call to catch the following signals.
b. SIGINT
Date: 17th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle_sigint(int sig) {
    printf("\nCaught signal %d (SIGINT - Interrupt).\n", sig);
    exit(EXIT_SUCCESS);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = handle_sigint;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    printf("SIGINT handler is set. Press Ctrl+C to trigger the signal.\n");

    pause();
    return 0;
}


/*
Output:
SIGINT handler is set. Press Ctrl+C to trigger the signal.
^C
Caught signal 2 (SIGINT - Interrupt).

*/