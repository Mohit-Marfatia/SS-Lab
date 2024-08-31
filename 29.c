#include <stdio.h>
#include <sched.h>
#include <stdlib.h>

int main() {
    pid_t pid = getpid();
    switch (sched_getscheduler(pid)) {
        case SCHED_FIFO:
            printf("Scheduling Policy is FIFO.\n");
            break;
        case SCHED_RR:
            printf("Schedulung Policy is RR.\n");
            break;
        case SCHED_OTHER:
            printf("Some other Scheduling Policy.\n");
            break;
        default:
            printf("Unknow Policy.\n");
            break;
    }
    struct sched_param schedParam;
    schedParam.sched_priority = 99;
    if (sched_setscheduler(pid, SCHED_FIFO, &schedParam) == -1){
        printf("There is some error modifying the scheduling policy.\n");
        exit(1);
    }
    printf("Scheduling Policy has been modified to FIFO.\n");
    sleep(2);
    switch (sched_getscheduler(pid)) {
        case SCHED_FIFO:
            printf("Scheduling Policy is FIFO.\n");
            break;
        case SCHED_RR:
            printf("Schedulung Policy is RR.\n");
            break;
        case SCHED_OTHER:
            printf("Some other Scheduling Policy.\n");
            break;
        default:
            printf("Unknow Policy.\n");
            break;
    }
    return 0;
}

/*
Output:
[sudo] password for mohit-marfatia: 
Some other Scheduling Policy.
Scheduling Policy has been modified to FIFO.
Scheduling Policy is FIFO.
*/