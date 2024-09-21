/*
============================================================================

Name : 33a.c
Author: Mohit Marfatia
Problem: Write a program to communicate between two machines using socket.
Date: 20th Sept, 2024.
============================================================================
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main() {
    struct sockaddr_in server, client;   
    int sd, sz, nsd;
    char buffer[100];
    sd = socket(AF_UNIX, SOCK_STREAM, 0);

    server.sin_family = AF_UNIX;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(5055);

    bind(sd, (void *)(&server), sizeof(server));

    listen(sd, 5);
    sz = sizeof(client);
    nsd = accept(sd, (void *)(&client), &sz);
    read(nsd, buffer, sizeof(buffer));
    printf("Message from Client: %s\n", buffer);
    printf("Sending ACK to Client: %s\n", buffer);
    write(nsd, "ACK from Server\n", 17);

    return 0;
}

/*
Output:

*/