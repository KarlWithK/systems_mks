#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  srand(time(NULL));
  printf("Forking is cool\n");
  int f, r, child, stat;
  f = fork();
  if (!f) {
    r = (rand() % 9) + 2;
    printf("Child1: PID %d\n", getpid());
    sleep(r);
    printf("Child1 done\n");
  } else {
    printf("Parent's PID %d\n", getpid());
    child = fork();
    if (!child) {
      r = (rand() % 9) + 2;
      printf("Child2: PID %d\n", getpid());
      sleep(r);
      printf("Child2 done\n");
    }
    wait(&stat);
    printf("Child done | Time taken: %d\nParent done.\n", WEXITSTATUS(stat));
  }
  return 0;
}
