/*
============================================================================

Name : 32a.c
Author: Mohit Marfatia
Problem: Write a program to implement semaphore to protect any critical section.
a. rewrite the ticket number creation program using semaphore
Date: 20th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <string.h>
#include <errno.h>
#include "definition.h"

int main() {
    TicketDatabase db;
    int fd;
    sem_t *sem;

    sem = sem_open("ticket_semaphore", O_CREAT, 0666, 1);
    fd = open("tickets.txt", O_RDWR | O_CREAT, 0666);
    printf("Waiting to acquire semaphore...\n");
    sem_wait(sem);

    // Critical section:
    lseek(fd, 0, SEEK_SET);
    read(fd, &db, sizeof(db));
    printf("Previously booked ticket num is %d\n", db.ticket_num);
    printf("Press enter to book the ticket\n");
    getchar();
    db.ticket_num += 1;
    printf("Booking ticket num %d\n", db.ticket_num);
    lseek(fd, 0, SEEK_SET);
    write(fd, &db, sizeof(db));
    sem_post(sem); // Signal the semaphore (increment it)

    printf("Ticket Booked successfully!\n");

    close(fd);
    sem_close(sem);
    return 0;
}

/*
Output:
Waiting to acquire semaphore...
Previously booked ticket num is 11
Press enter to book the ticket

Booking ticket num 12
Ticket Booked successfully!

*/