#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define FILE "Handler.txt"

static void sighandlerint(int signo) {
  if (signo == SIGINT) {
    int fd = open(FILE, O_APPEND | O_WRONLY | O_CREAT, 0644);
    if (fd == -1) {
      printf("errno: %d - %s\n", errno, strerror(errno));
      exit(1);
    }
    char msg[] = "What if I get into College?...jk...unless?\n";
    write(fd, msg, sizeof(msg) - 1); // need to make sure the size is correct
    close(fd);
    exit(0);
  }
}

static void sighandlerusr(int signo) {
  if (signo == SIGUSR1) {
    printf("Parent's PID%d\n", getppid());
  }
}

int main() {
  signal(SIGINT, sighandlerint);
  signal(SIGUSR1, sighandlerusr);
  while (64) {
    printf("PID of the program: %d\n", getpid());
    sleep(1);
  }
  return 0;
}
