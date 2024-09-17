/*
============================================================================

Name : 10b.c
Author: Mohit Marfatia
Problem: Write a separate program using sigaction system call to catch the following signals.
c. SIGFPE
Date: 17th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle_sigfpe(int sig) {
    printf("Caught signal %d (SIGFPE - Floating Point Exception).\n", sig);
    exit(EXIT_FAILURE); 
}

int main() {
    struct sigaction sa;
    sa.sa_handler = handle_sigfpe;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);

    if (sigaction(SIGFPE, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    printf("SIGFPE handler is set. Causing a floating-point exception (division by zero)...\n");

    int x = 1;
    int y = 0;
    int z = x / y;

    return 0;
}

/*
Output:
SIGFPE handler is set. Causing a floating-point exception (division by zero)...
Caught signal 8 (SIGFPE - Floating Point Exception).

*/