/*
============================================================================
Name : 33a.c
Author : Anurag Babal
Description : Write a program to communicate between two machines using socket.
Date: 20th Sept, 2023.
============================================================================
*/

#include<unistd.h>
#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main(void) {
    struct sockaddr_in server, client;
    int sd = socket(AF_INET, SOCK_STREAM, 0);
    
    server.sin_family = AF_INET;
    server.sin_port = htons(33546);
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    bind(sd, (struct sockaddr*) &server, sizeof(server));

    listen(sd, 5);
    printf("Waiting for client...\n");
    int size = sizeof(client);
    int nsd = accept(sd, (struct sockaddr*) &client, &size);

    printf("Client connected\n");
    int buff[80];
    read(nsd, buff, sizeof(buff));
    printf("Message from client: %s\n", buff);
    write(nsd, "ACK\n", 4);

    return 0;
}