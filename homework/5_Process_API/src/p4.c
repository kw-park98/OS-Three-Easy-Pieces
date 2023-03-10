#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h> // exit
#include <string.h>
#include <sys/wait.h>
#include <unistd.h> // fork

int main() {
    printf("hello world (pid:%d)\n", (int)getpid());
    pid_t rc = fork();
    if (rc < 0) {
        // fork 실패
        fprintf(stderr, "fork failed!\n");
        exit(EXIT_FAILURE);
    } else if (rc == 0) {
        // child
        printf("hello child (pid:%d)\n", (int)getpid());
        char *path = strdup("/bin/ls");
        char *myargs[2];
        myargs[0] = strdup("/bin/ls");
        myargs[1] = NULL;
        
        // execv(path, myargs);
        // execl(path, myargs[0], myargs[1]);
        
        char *env[2];
        env[0] = "env_hi";
        env[1] = "env_bye";
        execle(path, myargs[0], myargs[1], env);
        
        // char *relative_path = strdup("ls");
        // char *relative_myargs[2];
        // relative_myargs[0] = strdup("ls");
        // relative_myargs[1] = NULL;
        // execlp(relative_path, relative_myargs[0], relative_myargs[1]);
        
        printf("this shouldn’t print out\n");
    } else {
        // parent
        int rc_wait = wait(NULL);
        printf("hello, I am parent of %d (rc_wait:%d) (pid:%d)\n", rc, rc_wait,
               (int)getpid());
    }
}
