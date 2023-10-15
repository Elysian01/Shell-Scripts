/*
============================================================================
Name : 28.c
Author : Abhishek Gupta
Description : Write a program to change the exiting message queue permission.
                (use msqid_ds structure)
Date: 12th Oct, 2023.
============================================================================
*/

#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <time.h>

int main(void)
{
    key_t key = ftok(".", 2);
    int msgid = msgget(key, IPC_CREAT | 0666);
    struct msqid_ds ds;
    msgctl(msgid, IPC_STAT, &ds);

    printf("Access permission before exit: %o\n", ds.msg_perm.mode);
    ds.msg_perm.mode = 0644;
    getchar();
    msgctl(msgid, IPC_SET, &ds);
    msgctl(msgid, IPC_RMID, &ds);
    printf("Access permission after exit: %o\n", ds.msg_perm.mode);

    return 0;
}