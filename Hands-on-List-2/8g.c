#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>

// Signal handler for SIGPROF
void sigprof_handler(int signo) {
    if (signo == SIGPROF) {
        printf("Caught SIGPROF (Profiling timer alarm)\n");
        exit(EXIT_SUCCESS);  // Exit the program after catching the signal
    }
}

int main() {
    // Register signal handler for SIGPROF
    signal(SIGPROF, sigprof_handler);

    // Set up the profiling timer
    struct itimerval timer;

    // Configure the timer
    timer.it_value.tv_sec = 5;  // Initial expiration time (5 seconds)
    timer.it_value.tv_usec = 0; // Initial expiration time (0 microseconds)
    timer.it_interval.tv_sec = 0;  // Interval time (0 seconds, timer does not repeat)
    timer.it_interval.tv_usec = 0; // Interval time (0 microseconds)

    // Set the timer
    if (setitimer(ITIMER_PROF, &timer, NULL) == -1) {
        perror("setitimer");
        exit(EXIT_FAILURE);
    }

    // Pause the program to wait for the signal
    // The program will wait until it catches the SIGPROF signal
    printf("Setting a profiling timer to go off in 5 seconds using setitimer...\n");
    pause();

    // This line will not be executed
    printf("This line will not be executed.\n");

    return 0;
}
