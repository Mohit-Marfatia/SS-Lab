/*
============================================================================

Name : 10a.c
Author: Mohit Marfatia
Problem: Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV
Date: 17th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle_sigsegv(int sig) {
    printf("Caught signal %d (Segmentation Fault).\n", sig);
    exit(EXIT_FAILURE);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = handle_sigsegv;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);

    if (sigaction(SIGSEGV, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    printf("SIGSEGV handler is set. Causing segmentation fault...\n");

    int *ptr = NULL;
    *ptr = 42;

    return 0;
}

/*
Output:
SIGSEGV handler is set. Causing segmentation fault...
Caught signal 11 (Segmentation Fault).

*/