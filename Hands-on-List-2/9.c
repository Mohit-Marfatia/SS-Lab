/*
============================================================================

Name : 9.c
Author: Mohit Marfatia
Problem: Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
signal - Use signal system call.
Date: 17th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sig_handler(int signo){
    printf("SIGINT number: %d\n", signo);
}

int main(void){
    signal(SIGINT, sig_handler);
    printf("Catching SIGINT\n");
    sleep(3);
    printf("No SIGINT within 3 secs\n");

    printf("Ignoring SIGINT for the next 3 secs\n");
    signal(SIGINT, SIG_IGN);
    sleep(3);

    printf("\nDefault action restored\n");
    signal(SIGINT, SIG_DFL);
    sleep(3);
    printf("No SIGINT withing 3 secs\n");

    return 0;
}

/*
Output:
Catching SIGINT
No SIGINT within 3 secs
Ignoring SIGINT for the next 3 secs
^C^C^C^C^C^C
Default action restored
^C

*/