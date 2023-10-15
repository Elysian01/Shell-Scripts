/*
============================================================================
Name : 25.c
Author : Abhishek Gupta
Description : Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
                a. access permission
                b. uid, gid
                c. time of last message sent and received
                d. time of last change in the message queue
                d. size of the queue
                f. number of messages in the queue
                g. maximum number of bytes allowed
                h. pid of the msgsnd and msgrcv
Date: 14th Oct, 2023.
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
    struct ipc_perm perm = ds.msg_perm;

    printf("Access permission: %o\n", perm.mode);
    printf("UID: %d\n", perm.uid);
    printf("GID: %d\n", perm.gid);
    printf("Time of last message send: %s", ctime(&ds.msg_stime));
    printf("Time of last message receive: %s", ctime(&ds.msg_rtime));
    printf("Time of last change in the message queue: %s", ctime(&ds.msg_ctime));
    printf("Number of messages in queue: %ld\n", ds.msg_qnum);
    printf("Maximum number of bytes allowed: %ld\n", ds.msg_qbytes);
    printf("PID of msgsnd: %d\n", ds.msg_lspid);
    printf("PID of msgrcv: %d\n", ds.msg_lrpid);

    return 0;
}