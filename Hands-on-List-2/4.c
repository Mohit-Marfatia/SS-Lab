/*
============================================================================

Name : 4.c
Author: Mohit Marfatia
Problem: Write a program to measure how much time is taken to execute 100 getppid ( ) system call. Use time stamp counter.
Date: 14th Sept, 2024.
============================================================================
*/



#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>

unsigned long long rdtsc() {
    unsigned long long dst;
    __asm__ __volatile__ ("rdtsc":"=A" (dst));
}

int main(void){
    int i, nano;
    unsigned long long int start, end;
    start = rdtsc();
    for(int i=0; i<100; i++){
        getppid();
    }
    end = rdtsc();
    nano = (end-start)/2.09;
    printf("The function takes %d nano sec \n", nano);
    return 0;
}

/*
Output:
The function takes 263766 nano sec 

*/