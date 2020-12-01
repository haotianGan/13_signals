#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>


static void sighandler(int signo) {
    if (signo == SIGUSR1) {
      printf("\nRecieved SIGUSR1 signal. Parent ID is: %d\n", getppid());
    }
    if (signo == SIGINT) {
        FILE *fp = fopen("./output.txt", "w+");
        fprintf(fp, "The program was terminated because it recieved a SIGINT signal.");
        fclose(fp);
        exit(0);
    }
}
int main() {
    signal(SIGUSR1, sighandler);
    signal(SIGINT, sighandler);
    while (1) {
        sleep(1);
        printf("Process with ID: [%d] is currently running.\n", getpid());
    }
}
