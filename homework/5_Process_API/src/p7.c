#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h> // exit
#include <string.h>
#include <sys/wait.h>
#include <unistd.h> // fork

int main() {
    // close(STDOUT_FILENO);
    pid_t rc = fork();
    // close(STDOUT_FILENO);
    if (rc < 0) {
        // fork 실패
        fprintf(stderr, "fork failed!\n");
        exit(EXIT_FAILURE);
    } else if (rc == 0) {
        // child
        // close(STDOUT_FILENO);
        printf("hello child!\n");
    } else {
        // parent
        // close(STDOUT_FILENO);
        wait(NULL);
        printf("hello parent!\n");
    }
}
