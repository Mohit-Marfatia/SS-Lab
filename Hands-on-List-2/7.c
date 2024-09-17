/*
============================================================================

Name : 7.c
Author: Mohit Marfatia
Problem: Write a simple program to print the created thread ids.
Date: 17th Sept, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* thread_function(void* arg) {
    pthread_t thread_id = pthread_self();
    printf("Thread %d: ID = %lu\n", *(int*)arg, thread_id);
    return NULL;
}

int main() {
    pthread_t threads[3]; 
    int thread_args[3];
    int i;

    for (i = 0; i < 3; i++) {
        thread_args[i] = i + 1;
        if (pthread_create(&threads[i], NULL, thread_function, &thread_args[i]) != 0) {
            perror("Failed to create thread");
            exit(1);
        }
    }

    for (i = 0; i < 3; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("Failed to join thread");
            exit(1);
        }
    }

    printf("All threads finished.\n");

    return 0;
}

/*
Output:
Thread 1: ID = 139790682945216
Thread 2: ID = 139790674552512
Thread 3: ID = 139790666159808
All threads finished.

*/