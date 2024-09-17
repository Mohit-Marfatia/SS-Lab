/*
============================================================================

Name : 8a.c
Author: Mohit Marfatia
Problem: Write a separate program using signal system call to catch the following signals.
a. SIGSEGV
Date: 17th Sept, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigsegv_handler(int signo) {
    if (signo == SIGSEGV) {
        printf("Caught SIGSEGV (Segmentation fault)\n");
        exit(EXIT_FAILURE);
    }
}

int main() {
    signal(SIGSEGV, sigsegv_handler);

    printf("Triggering segmentation fault...\n");

    int *ptr = NULL;
    *ptr = 42;

    printf("This line will not be executed.\n");

    return 0;
}

/*
Output:
Triggering segmentation fault...
Caught SIGSEGV (Segmentation fault)

*/