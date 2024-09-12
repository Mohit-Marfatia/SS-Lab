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
    for(int i = 0; i < 3; i++){
        db[i].train_num = i+i;
        db[i].ticket_count = 0;
    }
    int fd = open("train_records.txt", O_RDWR | O_CREAT, 0666);
    perror("open fd:");
    if(fd<0){
        perror("train_record access:");
        close(fd);
    }
    write(fd, &db, sizeof(db));
    perror("write:");
    return 0;
}

/*
Output:
open fd:: Success
write:: Success

*/