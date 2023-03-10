#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h> // exit
#include <string.h>
#include <sys/wait.h>
#include <unistd.h> // fork

int main() {

    int x = 100;

    pid_t rc = fork();
    if (rc < 0) {
        // fork 실패
        fprintf(stderr, "fork failed!\n");
        exit(EXIT_FAILURE);
    } else if (rc == 0) {
        // child
        printf("child rc  = %d\n", rc);
        printf("child pid = %d\n", getpid());
        printf("child  -> %d\n", x);
        x--;
        printf("child  -> %d\n", x);
    } else {
        // parent
        printf("parent rc = %d\n", rc);
        printf("parent pid = %d\n", getpid());
        printf("parent -> %d\n", x);
        x++;
        printf("parent -> %d\n", x);
    }
}
