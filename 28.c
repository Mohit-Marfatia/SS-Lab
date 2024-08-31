/*
============================================================================

Name : 28.c
Author: Mohit Marfatia
Problem: Write a program to get maximum and minimum real time priority.
Date: 31st Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <sched.h>

int main() {
    int max_priority_fifo, min_priority_fifo;

    max_priority_fifo = sched_get_priority_max(SCHED_FIFO);
    min_priority_fifo = sched_get_priority_min(SCHED_FIFO);

    printf("Real-time Priority Ranges:\n");
    printf("SCHED_FIFO: Max Priority = %d, Min Priority = %d\n", max_priority_fifo, min_priority_fifo);


    int max_priority_rr, min_priority_rr;
    max_priority_rr = sched_get_priority_max(SCHED_RR);
    min_priority_rr = sched_get_priority_min(SCHED_RR);

    printf("SCHED_RR:   Max Priority = %d, Min Priority = %d\n", max_priority_rr, min_priority_rr);

    return 0;
}

/*
Output:
Real-time Priority Ranges:
SCHED_FIFO: Max Priority = 99, Min Priority = 1
SCHED_RR:   Max Priority = 99, Min Priority = 1
*/