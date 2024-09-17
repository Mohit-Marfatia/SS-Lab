/*
============================================================================

Name : 8c.c
Author: Mohit Marfatia
Problem: Write a separate program using signal system call to catch the following signals.
c. SIGFPE
Date: 17th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <fenv.h>

void sigfpe_handler(int signo) {

        printf("Caught SIGFPE (Floating point exception)\n");
        exit(EXIT_FAILURE);

}

int main() {
    signal(SIGFPE, sigfpe_handler);

    printf("Triggering SIGFPE...\n");

    int a = 1;
    int b = 0;
    int result = a / b;

    printf("Result: %d\n", result);

    return 0;
}



/*
Output:
Triggering SIGFPE...
Caught SIGFPE (Floating point exception)


*/