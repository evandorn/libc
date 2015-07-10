/*

    Created by Evan Dorn on 7/10/15
 
   SYNOPSIS
    #include <sys/wait.h>
 
    pid_t waitpid(pid_t pid, int *stat_loc, int options);

*/

int waitpid(pid_t pid, int *stat_loc, int options) {

    for(;;) {
        int wpid = wait(stat_loc);
        if(wpid == pid || wpid == -1) {
            return wpid;
        }
    }
}
