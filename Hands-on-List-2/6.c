/*
============================================================================

Name : 6.c
Author: Mohit Marfatia
Problem: Write a simple program to create three threads.
Date: 17th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* thread_function(void* arg) {
    int thread_num = *(int*)arg;
    printf("Hello from thread %d\n", thread_num);
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
Hello from thread 1
Hello from thread 2
Hello from thread 3
All threads finished.

*/