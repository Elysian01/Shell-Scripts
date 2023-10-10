/*
============================================================================
Name : 27a.c
Author : Anurag Babal
Description : Write a program to receive messages from the message queue.
    a. with 0 as a flag
Date: 29th Sept, 2023.
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
    key_t key = ftok(".", 2);
    int msgid = msgget(key, 0);

    printf("Enter msg type: ");
    scanf("%d", &mq.mtype);
    msgrcv(msgid, &mq, sizeof(mq.mtext), mq.mtype, 0);
    printf("Message : %s", mq.mtext);

    return 0;
}