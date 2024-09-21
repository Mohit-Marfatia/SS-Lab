/*
============================================================================
Name : 3.c
Author : Mohit Marfatia
Description : Write a program to set (any one) system resource limit. Use setrlimit system call.
Date: 12th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>

void set_cpu_time_limit(int seconds) {
    struct rlimit limit;
    
    limit.rlim_cur = seconds;  // Soft limit
    limit.rlim_max = seconds;  // Hard limit
    
    if (setrlimit(RLIMIT_CPU, &limit) == -1) {
        perror("Error setting CPU time limit");
        exit(1);
    }
    printf("CPU time limit set to %d seconds\n", seconds);
}

int main() {
    set_cpu_time_limit(10);
    
    printf("Process is running... (it will be terminated after 10 seconds)\n");
    while (1) {
        for (long i = 0; i < 1000000000; i++) {
            // Busy loop to consume CPU time
        }
    }

    return 0;
}

/*
Output:
CPU time limit set to 10 seconds
Process is running... (it will be terminated after 10 seconds)
Killed

*/