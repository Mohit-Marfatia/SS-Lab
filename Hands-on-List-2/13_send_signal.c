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

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Give pid");
        exit(1);
    }

    pid_t pid = atoi(argv[1]);

    printf("Sending SIGSTOP to process %d\n", pid);
    kill(pid, SIGSTOP);

    sleep(5);

    printf("Sending SIGCONT to process %d\n", pid);
    kill(pid, SIGCONT);

    sleep(5);

    printf("Sending SIGKILL to process %d\n", pid);
    kill(pid, SIGKILL);

    return 0;
}

/*
Output:
Sending SIGSTOP to process 10869
Sending SIGCONT to process 10869
Sending SIGKILL to process 10869

*/