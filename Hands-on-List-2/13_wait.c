/*
============================================================================

Name : 13.c
Author: Mohit Marfatia
Problem: Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
Date: 18th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int signal) {
    if (signal == SIGUSR1) {
        printf("Caught SIGUSR1 signal\n");
    } else if (signal == SIGSTOP) {
        printf("Attempt to catch SIGSTOP (this won't work)\n");
    }
}

int main() {
    signal(SIGUSR1, signal_handler);
    printf("PID of this process: %d\n", getpid());

    while (1) {
        printf("Waiting for signals...\n");
        sleep(3);
    }

    return 0;
}

/*
Output:
PID of this process: 10869
Waiting for signals...
Waiting for signals...
Waiting for signals...
Waiting for signals...
Waiting for signals...
Waiting for signals...
Waiting for signals...

[1]+  Stopped                 ./a.out
(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise/Hands-on-List-2$ Waiting for signals...
Waiting for signals...

*/