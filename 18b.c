/*
============================================================================

Name : 18.c
Author: Mohit Marfatia
Problem: Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.
Date: 30th Aug, 2024.
============================================================================
*/



#include<stdio.h>
#include<fcntl.h>
#include "definition.h"

int main(){
    TrainDatabase db;
    int fd = open("train_records.txt", O_RDWR | O_CREAT, 0666);
    if(fd<0){
        perror("train_record access:");
        close(fd);
    }
    int choice;
    printf("Press 1 to book ticket or 2 to see the booked tickets:\n");
    scanf("%d", &choice);
    if(choice == 2){
        int trainNo;
        printf("Enter train no(1,2,3):\n");
        scanf("%d", &trainNo);
        struct flock lock;
        lock.l_type = F_RDLCK;
        lock.l_whence = SEEK_SET;
        lock.l_start = (trainNo-1)*sizeof(db);
        lock.l_len = sizeof(db);
        lock.l_pid = getpid();

        printf("Waiting for read lock:\n");
        int readLock = fcntl(fd, F_SETLKW, &lock);
        if(readLock<0){
            perror("read lock:");
            close(fd);
        }
        lseek(fd, (trainNo-1)*sizeof(db), SEEK_SET);
        read(fd, &db, sizeof(db));
        printf("Train no: %d Tickets booked: %d\n", trainNo, db[trainNo-1].ticket_count);

        lock.l_type = F_UNLCK;
        readLock = fcntl(fd, F_SETLK, &lock);
        if(readLock<0){
            perror("read unlock:");
            close(fd);
        }

    } else {
        int trainNo;
        printf("Enter train no(1,2,3):\n");
        scanf("%d", &trainNo);
        int choice;
        struct flock lock;
        lock.l_type = F_WRLCK;
        lock.l_whence = SEEK_SET;
        lock.l_start = (trainNo-1)*sizeof(db);
        lock.l_len = sizeof(db);
        lock.l_pid = getpid();

        printf("Waiting for write lock:\n");
        int writeLock = fcntl(fd, F_SETLKW, &lock);
        if(writeLock<0){
            perror("write lock:");
            close(fd);
        }

        lseek(fd, (trainNo-1)*sizeof(db), SEEK_SET);
        perror("lseek:");
        read(fd, &db, sizeof(db));
        perror("read:");
        printf("Train no: %d Tickets booked: %d\n", trainNo, db[trainNo-1].ticket_count);
        printf("Press enter to book ticket in train %d", trainNo);
        getchar();
        getchar();

        db[trainNo-1].ticket_count += 1;
        lseek(fd, -1*sizeof(db), SEEK_CUR);   
        int writeOpr = write(fd, &db, sizeof(db));
        if(writeOpr<0){
            perror("write operation:");
            close(fd);
        }

        lock.l_type = F_UNLCK;
        writeLock = fcntl(fd, F_SETLK, &lock);
        if(writeLock<0){
            perror("write unlock:");
            close(fd);
        }
        printf("Ticket Booked\n");
    }
    return 0;
}

/*
Output:
//Write
Press 1 to book ticket or 2 to see the booked tickets:
1
Enter train no(1,2,3):
3
Waiting for write lock:
lseek:: Success
read:: Success
Train no: 3 Tickets booked: 0
Press enter to book ticket in train 3
Ticket Booked

//Read
Press 1 to book ticket or 2 to see the booked tickets:
2
Enter train no(1,2,3):
2
Waiting for read lock:
Train no: 2 Tickets booked: 1

*/