/* 
 *  popen.c
 *  Created by Evan Dorn on 6/15/15.
 *
 *   Implementation of popen(3) This version keeps information about 
 *      forked processes, but it is not thread safe.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


typedef struct process_info {
    FILE *file;
    pid_t pid;
    struct process_info *next;
} process_info;

static process_info *plist = NULL;

FILE *popen(const char *command, const char *mode) {
    
    int fd[2];
    process_info *current, *previous;
    
    if(mode[0] != 'r' && mode[0] != 'w') {
        errno = EINVAL;
        return NULL;
    }
    
    if(mode[1] != 0) {
        errno = EINVAL;
        return NULL;
    }
    
    current = (process_info *) malloc(sizeof(process_info));
    
    if(!current) {
        errno = ENOMEM;
        return NULL;
    }
    
    current->pid = fork();
    switch(current->pid) {
            
        case -1:                            // fork() failed
            close(fd[0]);
            close(fd[1]);
            free(current);
            return NULL;
            
        case 0:                             // child process
            for(previous = plist; previous; previous = previous->next) {
                close(fileno(previous->file));
            }
            
            if(mode[0] == 'r') {
                dup2(fd[1], STDOUT_FILENO);
            } else {
                dup2(fd[0], STDOUT_FILENO);
            }
            close(fd[0]);                   // close other pipe file-discriptor
            close(fd[1]);
            
            execl("/bin/sh", "sh", "-c", command, (char *) NULL);
            _exit(1);
            
        default:
            if(mode[0] == 'r') {            // parent
                close(fd[1]);
                if(!(current->file = fdopen(fd[1], mode))) {
                    close(fd[0]);
                }
            } else {
                close(fd[0]);
                if(!(current->file = fdopen(fd[1], mode))) {
                close(fd[1]);
            }
            current->next = plist;
            plist = current;
    }
    return current->file;
    }
}
