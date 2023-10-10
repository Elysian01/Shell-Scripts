/*
============================================================================
Name : 29.c
Author : Anurag Babal
Description : Write a program to remove the message queue.
Date: 19th Sept, 2023.
============================================================================
*/

#include<unistd.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>

int main(void) {
    struct msg {
        int mtype;
        char mtext[20];
    } mq;
    key_t key = ftok(".", 1);
    int msgid = msgget(key, 0);

    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}