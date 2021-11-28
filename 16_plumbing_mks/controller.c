#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <unistdio.h>
static void sighandler(int signo) {
  if (signo == SIGINT) {
    remove("request");
    remove("response");
    /* printf("ENDING PROGRAM\n"); */
    exit(0);
  }
}

int main() {
  signal(SIGINT, sighandler);
  int pipe;
  char request[80], response[80];
  mkfifo("request", 0666);
  mkfifo("response", 0666);
  while (64) {
    printf("Input something less than 80 chars: ");
    fgets(request, sizeof(request) - 1, stdin);
    pipe = open("request", O_WRONLY);
    write(pipe, request, sizeof(request) - 1);
    close(pipe);

    pipe = open("response", O_RDONLY);
    read(pipe, response, sizeof(request) - 1);
    printf("Response: %s\n", response);
    close(pipe);
  }
  return 0;
}
