#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h> // exit
#include <string.h>
#include <sys/wait.h>
#include <unistd.h> // fork

#define READ 0
#define WRITE 1

// child1's STDOUT ==> child2's STDIN

int main() {
    int fd[2];
    if (pipe(fd) < 0) {
        fprintf(stderr, "pipe failed!\n");
        exit(EXIT_FAILURE);
    }
    pid_t rc1 = fork();
    if (rc1 < 0) {
        // fork 실패
        fprintf(stderr, "fork failed!\n");
        exit(EXIT_FAILURE);
    } else if (rc1 == 0) {
        // child1
        close(fd[READ]);
        dup2(fd[WRITE], STDOUT_FILENO);
        char *path = strdup("/bin/df");
        char *myargs[2];
        myargs[0] = strdup("/bin/df");
        myargs[1] = NULL;
        execv(path, myargs);
    } else {
        // parent
        pid_t rc2 = fork();
        if (rc2 < 0) {
            // fork 실패
            fprintf(stderr, "fork failed!\n");
            exit(EXIT_FAILURE);
        } else if (rc2 == 0) {
            // child2
            dup2(STDOUT_FILENO, fd[WRITE]);
            dup2(fd[READ], STDIN_FILENO);
            // execlp("wc", "wc", "-l", NULL);
            execlp("wc", "wc", NULL);
        } else {
            // parent
            wait(NULL);
        }
    }
}
