/*
============================================================================

Name : 21.c
Author: Mohit Marfatia
Problem: Write two programs so that both can communicate by FIFO -Use two way communication.
Date: 18th Sept, 2024.
============================================================================
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>


int main() {
    char message[100];
    char received[100];
    int fd;

    mkfifo("myfifo", 0666);

    while (1) {
        fd = open("myfifo" ,O_WRONLY);
        if (fd == -1) {
            perror("Error opening FIFO for writing");
            return 1;
        }

        printf("21 a taking message: ");
        fgets(message, sizeof(message), stdin);
        write(fd, message, strlen(message) + 1);  
        close(fd);  

      
        fd = open("myfifo", O_RDONLY);
        if (fd == -1) {
            perror("Error opening FIFO for reading");
            return 1;
        }

        read(fd, received, sizeof(received));  // Read message from FIFO
        printf("Received from Program 21b: %s\n", received);
        close(fd);  // Close after reading
    }

    return 0;
}
/*
Output: 
21 a taking message: hi
Received from Program 21b: hello

21 a taking message: bye from a
Received from Program 21b: bye from b



*/