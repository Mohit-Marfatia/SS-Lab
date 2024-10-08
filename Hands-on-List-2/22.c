/*
============================================================================

Name : 22.c
Author: Mohit Marfatia
Problem: Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.
Date: 19th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>

int main() {
    int fd;
    fd_set readSet;
    struct timeval timeout;
    mkfifo("22_fifo", 0666);
    fd = open("22_fifo", O_RDWR);
    FD_ZERO(&readSet);
    FD_SET(fd, &readSet);
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;
    int selectResult = select(fd + 1, &readSet, NULL, NULL, &timeout);
    if(selectResult) {
        char buffer[100];
        ssize_t bytesRead = read(fd, buffer, sizeof(buffer));
        if (bytesRead > 0) {
            buffer[bytesRead] = '\0';  // Null-terminate the string
            printf("Received message: %s\n", buffer);
        } else {
            printf("Error reading data from FIFO.\n");
        }
    } else {
        printf("No data written within 10 seconds.\n");
    }
    char response[] = "Response from Reader!";
    write(fd, response, sizeof(response));
    close(fd);
    unlink("22_fifo");
    return 0;
}

/*
Output:
(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise/Hands-on-List-2$ ./a.out 
Received message: Hello

(base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise/Hands-on-List-2$ ./a.out 
No data written within 10 seconds.

*/