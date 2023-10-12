/*
============================================================================
Name : 33b.c
Author : Abhishek Gupta
Description : Write a program to communicate between two machines using socket.
Date: 12th Oct, 2023
============================================================================
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(void)
{
    struct sockaddr_in server;
    int sd = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(33546);
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    printf("Waiting for server...\n");
    connect(sd, (struct sockaddr *)&server, sizeof(server));
    printf("Connected to server\n");

    int buff[80];
    write(sd, "Hello\n", 6);
    read(sd, buff, sizeof(buff));
    printf("Message from Server: %s\n", buff);

    return 0;
}