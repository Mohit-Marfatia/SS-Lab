/*
============================================================================
Name : 2.c
Author : Mohit Marfatia
Description : Write a program to print the system resource limits. Use getrlimit system call.
Date: 14th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

void printLimit(char* name, int resource) {
    struct rlimit limit;
    
    if (getrlimit(resource, &limit) == 0) {
        printf("%-20s | Soft limit: %lu | Hard limit: %lu\n", name, (unsigned long) limit.rlim_cur, (unsigned long) limit.rlim_max);
    } else {
        perror("getrlimit");
    }
}

int main() {
    printf("Resource limits:\n\n");
    
    printLimit("CPU time", RLIMIT_CPU);
    printLimit("File size", RLIMIT_FSIZE);
    printLimit("Data size", RLIMIT_DATA);
    printLimit("Stack size", RLIMIT_STACK);
    printLimit("Core file size", RLIMIT_CORE);
    printLimit("Resident set size", RLIMIT_RSS);
    printLimit("Open files", RLIMIT_NOFILE);
    printLimit("Locked memory", RLIMIT_MEMLOCK);
    printLimit("Address space", RLIMIT_AS);
    printLimit("Number of processes", RLIMIT_NPROC);
    printLimit("File locks", RLIMIT_LOCKS);
    printLimit("Pending signals", RLIMIT_SIGPENDING);
    printLimit("Message queue size", RLIMIT_MSGQUEUE);
    printLimit("Nice priority", RLIMIT_NICE);
    printLimit("Real-time priority", RLIMIT_RTPRIO);
    printLimit("Real-time timeout", RLIMIT_RTTIME);

    return 0;
}


/*
Output:
Resource limits:

CPU time             | Soft limit: 18446744073709551615 | Hard limit: 18446744073709551615
File size            | Soft limit: 18446744073709551615 | Hard limit: 18446744073709551615
Data size            | Soft limit: 18446744073709551615 | Hard limit: 18446744073709551615
Stack size           | Soft limit: 8388608 | Hard limit: 18446744073709551615
Core file size       | Soft limit: 0 | Hard limit: 18446744073709551615
Resident set size    | Soft limit: 18446744073709551615 | Hard limit: 18446744073709551615
Open files           | Soft limit: 1024 | Hard limit: 1048576
Locked memory        | Soft limit: 2075697152 | Hard limit: 2075697152
Address space        | Soft limit: 18446744073709551615 | Hard limit: 18446744073709551615
Number of processes  | Soft limit: 63052 | Hard limit: 63052
File locks           | Soft limit: 18446744073709551615 | Hard limit: 18446744073709551615
Pending signals      | Soft limit: 63052 | Hard limit: 63052
Message queue size   | Soft limit: 819200 | Hard limit: 819200
Nice priority        | Soft limit: 0 | Hard limit: 0
Real-time priority   | Soft limit: 0 | Hard limit: 0
Real-time timeout    | Soft limit: 18446744073709551615 | Hard limit: 18446744073709551615

*/