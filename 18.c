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
    if(fd<0){
        perror("train_record access:");
        close(fd);
    }
    write(fd, &db, sizeof(db));
    return 0;
}