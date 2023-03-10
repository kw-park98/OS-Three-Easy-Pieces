#include <fcntl.h>
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

#define MAX_LOOPS 500000

int main() {
    struct timeval start_time, end_time;
    int loops = MAX_LOOPS;

    /**
     * system call measure
     */
    char *syscall_txt = "mesure_syscall.txt";
    int fd = open(syscall_txt, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
    gettimeofday(&start_time, NULL);
    for (int i = 0; i < loops; ++i)
        read(fd, NULL, 0);
    gettimeofday(&end_time, NULL);
    float total_syscall_time =
        (float)(end_time.tv_sec * 1000000 + end_time.tv_usec -
                (start_time.tv_sec * 1000000 + start_time.tv_usec));
    printf("system call: %f microseconds\n", total_syscall_time / loops);
    close(fd);
    remove(syscall_txt);

    /**
     * context switch measure
     */

    pid_t pid = fork();
    if (pid < 0) {
        // fork 실패
        fprintf(stderr, "fork failed!\n");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // child

    } else {
        // parent
    }

    return 0;
}