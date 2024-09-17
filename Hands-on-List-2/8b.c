/*
============================================================================

Name : 8b.c
Author: Mohit Marfatia
Problem: Write a separate program using signal system call to catch the following signals.
b. SIGINT
Date: 17th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigint_handler(int signo) {
    if (signo == SIGINT) {
        printf("\nCaught SIGINT (Interrupt from keyboard - Ctrl + C)\n");
        exit(EXIT_SUCCESS);
    }
}

int main() {
    signal(SIGINT, sigint_handler);

    printf("Program is running. Press Ctrl + C to trigger SIGINT...\n");

    for(;;);

    return 0;
}


/*
Output:
Triggering segmentation fault...
Program is running. Press Ctrl + C to trigger SIGINT...
^C
Caught SIGINT (Interrupt from keyboard - Ctrl + C)


*/