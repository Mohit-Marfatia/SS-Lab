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

    // Create the FIFO if it does not exist
    mkfifo("myfifo", 0666);

    while (1) {
        // Program 2 reads from FIFO
        fd = open("myfifo", O_RDONLY);
        if (fd == -1) {
            perror("Error opening FIFO for reading");
            return 1;
        }

        read(fd, received, sizeof(received));  
        printf("Received from Program 21a: %s\n", received);
        close(fd);  

        fd = open("myfifo", O_WRONLY);
        if (fd == -1) {
            perror("Error opening FIFO for writing");
            return 1;
        }

        printf("22b enter message: ");
        fgets(message, sizeof(message), stdin);
        write(fd, message, strlen(message) + 1);  
        close(fd);  
    }

    return 0;
}
/*
Output:
Received from Program 21a: hi

22b enter message: hello
Received from Program 21a: bye from a

22b enter message: bye from b

^C

*/