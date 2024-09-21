/*
============================================================================

Name : 34a.c
Author: Mohit Marfatia
Problem: Write a program to create a concurrent server.
a. use fork
Date: 21st Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>
#include <stdbool.h>
#include <string.h>

int main() {
    int serverSD, clientSD;
    struct sockaddr_in server, client;

    serverSD = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSD == -1) {
        perror("Socket creation failed");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(5306);
    server.sin_addr.s_addr = INADDR_ANY;

    bind(serverSD, (void *)&server, sizeof(server));
    listen(serverSD, 5);          

    printf("Server is listening on port 5306...\n");

    while (1) {
        int clientSz = sizeof(client);
        // printf("client %d \n",serverSD);
        clientSD = accept(serverSD, (void *)&client, &clientSz);
        perror("accept client working:");
        if (clientSD == -1) {
            perror("problem establishing connection failed");
            exit(0);
        }
        else {
            if (fork() == 0) {
                printf("client here %d \n",clientSD);
                char buffer[1024];
                int bytesRead = read(clientSD, &buffer, sizeof(buffer));
                buffer[bytesRead] = '\0';
                printf("Message from client: %s \n", buffer);
                write(clientSD, "Thank you", strlen("Thank you"));
            }
            else {
                close(clientSD);
            }
        }
    }

    close(serverSD);

    return 0;
}

/*
base) mohit-marfatia@mohit-marfatia:~/College/Software-Systems/exercise/Hands-on-List-2$ ./a.out
Server is listening on port 5306...
accept client working:: Success
client here 4 
Message from client: hello server!
 
accept client working:: Success
client here 4 
Message from client: hello server!
 
*/