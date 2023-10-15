/*
============================================================================
Name : 26.c
Author : Abhishek Gupta
Description : Write a program to send messages to the message queue. Check $ipcs -q
Date: 13th Oct, 2023
============================================================================
*/

#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    struct msg
    {
        long mtype;
        char mtext[20];
    } mq;
    key_t key = ftok(".", 2);
    int msgid = msgget(key, 0);
    printf("Key: 0x%0x, msg-id: %d\n", key, msgid);
    printf("Enter msg type: ");
    scanf("%ld", &mq.mtype);
    fflush(stdin);
    printf("Enter message: ");
    scanf("%[^\n]", mq.mtext);
    int size = strlen(mq.mtext);
    msgsnd(msgid, &mq, size + 1, 0);

    return 0;
}