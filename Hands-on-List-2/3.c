/*
============================================================================
Name : 3.c
Author : Mohit Marfatia
Description : Write a program to set (any one) system resource limit. Use setrlimit system call.
Date: 12th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

void print_nice_limit() {
    struct rlimit limit;
    
    if (getrlimit(RLIMIT_NICE, &limit) == 0) {
        printf("Current RLIMIT_NICE limits: Soft limit: %ld | Hard limit: %ld\n", 
               (long)limit.rlim_cur, (long)limit.rlim_max);
    } else {
        perror("getrlimit");
    }
}

int main() {
    struct rlimit new_limit;
    
    printf("Before setting new RLIMIT_NICE limit:\n");
    print_nice_limit();
    
    new_limit.rlim_cur = 10;
    new_limit.rlim_max = 10; 
    
    if (setrlimit(RLIMIT_NICE, &new_limit) != 0) {
        perror("setrlimit");
        return 1;
    }
    
    printf("After setting new RLIMIT_NICE limit:\n");
    print_nice_limit();

    int current_nice = getpriority(PRIO_PROCESS, 0);
    if (current_nice == -1 && errno != 0) {
        perror("getpriority");
        return 1;
    }
    
    printf("Current process nice value: %d\n", current_nice);

    printf("Attempting to change nice value by 6...\n");
    int result = nice(6);
    
    if (result == -1 && errno != 0) {
        printf("Error changing nice value: %s\n", strerror(errno));
    } else {
        printf("Nice value changed successfully. New nice value: %d\n", getpriority(PRIO_PROCESS, 0));
    }

    current_nice = getpriority(PRIO_PROCESS, 0);
    if (current_nice == -1 && errno != 0) {
        perror("getpriority");
        return 1;
    }
    
    printf("Current process nice value: %d\n", current_nice);

    printf("Attempting to change nice value by 5...\n");
     result = nice(5);
    
    if (result == -1 && errno != 0) {
        printf("Error changing nice value: %s\n", strerror(errno));
    } else {
        printf("Nice value changed successfully. New nice value: %d\n", getpriority(PRIO_PROCESS, 0));
    }
    
    return 0;
}

