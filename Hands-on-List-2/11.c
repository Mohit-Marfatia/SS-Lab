/*
============================================================================

Name : 11.c
Author: Mohit Marfatia
Problem: Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
use sigaction system call.
Date: 17th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main() {
    struct sigaction sa;

    sa.sa_handler = SIG_IGN;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask); 

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    printf("SIGINT is currently being ignored. Press Ctrl+C.\n");

    sleep(3);

    sa.sa_handler = SIG_DFL;
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    printf("\nSIGINT has been reset to default behavior. Press Ctrl+C to terminate the program.\n");

    pause();

    return 0;
}

/*
Output:
SIGINT is currently being ignored. Press Ctrl+C.
^C^C^C
SIGINT has been reset to default behavior. Press Ctrl+C to terminate the program.
^C

*/