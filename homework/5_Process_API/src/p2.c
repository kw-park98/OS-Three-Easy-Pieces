#include <stdio.h>
#include <stdlib.h> // exit
#include <sys/wait.h>
#include <unistd.h> // fork
#include <fcntl.h>
#include <string.h>

int main() {
    int fd = open("./p2.output", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
    pid_t rc = fork();
    if (rc < 0) {
        // fork 실패
        fprintf(stderr, "fork failed!\n");
        exit(EXIT_FAILURE);
    } else if (rc == 0) {
        // parent
        char *parent_buf = "hello1\n";
        write(fd, parent_buf, strlen(parent_buf));
    } else {
        // child
        char *child_buf = "hello2\n";
        write(fd, child_buf, strlen(child_buf));
    }
}
