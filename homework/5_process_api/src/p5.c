#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h> // exit
#include <string.h>
#include <sys/wait.h>
#include <unistd.h> // fork

int main() {

    pid_t rc = fork();
    if (rc < 0) {
        // fork 실패
        fprintf(stderr, "fork failed!\n");
        exit(EXIT_FAILURE);
    } else if (rc == 0) {
        // child
        printf("child's pid = %d\n", (int)getpid());
    } else {
        // parent
        int rc_wait = wait(NULL);
        printf("rc_wait = %d\n", rc_wait);
        printf("parent's pid = %d\n", (int)getpid());
    }
}
