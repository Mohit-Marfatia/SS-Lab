/*
============================================================================

Name : 33b.c
Author: Mohit Marfatia
Problem: Write a program to communicate between two machines using socket.
Date: 20th Sept, 2024.
============================================================================
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main() {
    struct sockaddr_in server;   
    int sd;
    char buffer[100];
    sd = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(5308);

    connect(sd, (void *)(&server), sizeof(server));
    write(sd, "hello server!\n", 14);
    read(sd, &buffer, sizeof(buffer));
    printf("Message from Server: %s\n", buffer);

    return 0;
}