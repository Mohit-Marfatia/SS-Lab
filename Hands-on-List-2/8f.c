/*
============================================================================

Name : 8f.c
Author: Mohit Marfatia
Problem: Write a separate program using signal system call to catch the following signals.
f. SIGVTALRM (use setitimer system call)
Date: 17th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>

void sigvtalrm_handler(int signo) {
    if (signo == SIGVTALRM) {
        printf("Caught SIGVTALRM (setitimer virtual signal)\n");
        exit(EXIT_SUCCESS);
    }
}

int main() {
    signal(SIGVTALRM, sigvtalrm_handler);

    printf("Setting a timer to go off in 2 seconds...\n");
    struct itimerval timer;
    
    timer.it_value.tv_sec = 2; 
    timer.it_value.tv_usec = 0; 
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    if (setitimer(ITIMER_VIRTUAL, &timer, NULL) == -1) {
        perror("setitimer");
        exit(EXIT_FAILURE);
    }

    while(1){
        for(int i =0;i<1000000;i++) {
            // printf("something");
        }
    }

    printf("This line will not be executed.\n");

    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <signal.h>
// #include <unistd.h>
// #include <sys/time.h>

// // Signal handler for SIGVTALRM
// void sigvtalrm_handler(int signo) {
//     if (signo == SIGVTALRM) {
//         printf("Caught SIGVTALRM (Virtual timer alarm)\n");
//         exit(EXIT_SUCCESS);  // Exit the program after catching the signal
//     }
// }

// int main() {
//     // Register signal handler for SIGVTALRM
//     signal(SIGVTALRM, sigvtalrm_handler);

//     // Set up the virtual timer
//     struct itimerval timer;

//     // Configure the timer
//     timer.it_value.tv_sec = 5;  // Initial expiration time (5 seconds)
//     timer.it_value.tv_usec = 0; // Initial expiration time (0 microseconds)
//     timer.it_interval.tv_sec = 0;  // Interval time (0 seconds, timer does not repeat)
//     timer.it_interval.tv_usec = 0; // Interval time (0 microseconds)

//     // Set the timer
//     if (setitimer(ITIMER_VIRTUAL, &timer, NULL) == -1) {
//         perror("setitimer");
//         exit(EXIT_FAILURE);
//     }

//     // Pause the program to wait for the signal
//     // The program will wait until it catches the SIGVTALRM signal
//     printf("Setting a virtual timer to go off in 5 seconds using setitimer...\n");
//     pause();

//     // This line will not be executed
//     printf("This line will not be executed.\n");

//     return 0;
// }

/*
Output:
Setting a timer to go off in 2 seconds...
Caught SIGALRM (setitimer signal)

*/