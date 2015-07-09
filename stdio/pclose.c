/*
 *  pclose.c
 *  Created by Evan Dorn on 6/15/15.
 *
 *   Implementation of pclose(3) This version keeps information about
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

int pclose(FILE *file) {

    process_info *last, *current;
    int status;
    pid_t pid;
    
    // search for an entry in the list of open pipes
    
    for(last = NULL, current = plist; current; last = current, current = current->next) {
        if(current->file == file) {
            break;
        }
    }
    if(!current) {
        errno = EINVAL;
        return -1;
    }
    
    // remove entry from the list
    
    if(last) {
        last->next = current->next;
    } else {
        plist = current->next;
    }
    
    // close the stream and wait for process to terminate
    
    fclose(file);
    do {
        pid = waitpid(current->pid, &status, 0);
    } while(pid == -1 && errno == EINTR);
    
    // release the entry for the closed pipe
    
    free(current);
    
    if(WIFEXITED(status)) {
        return WEXITSTATUS(status);
    }
    errno = ECHILD;
    return -1;
}

