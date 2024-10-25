#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>

// Signal handler for SIGPROF
void sigprof_handler(int signo) {
    if (signo == SIGPROF) {
        printf("Caught SIGPROF (Profiling timer alarm)\n");
        exit(EXIT_SUCCESS); 
    }
}

int main() {
    signal(SIGPROF, sigprof_handler);

    struct itimerval timer;

    timer.it_value.tv_sec = 5;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    if (setitimer(ITIMER_PROF, &timer, NULL) == -1) {
        perror("setitimer");
        exit(EXIT_FAILURE);
    }

    printf("Setting a profiling timer to go off in 5 seconds using setitimer...\n");
    pause();

    printf("This line will not be executed.\n");

    return 0;
}
