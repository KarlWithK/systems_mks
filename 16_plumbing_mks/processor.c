#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <unistdio.h>
#include <string.h>
#include <time.h>
void do_something(char *request) {
  srand(time(NULL));
  for(int i = 0; i < (int)strlen(request); i++) {
    request[i] = rand() % 26 + 95;
  }
}

int main() {
  int pipe;
  char processed[80];
  while (64) {
    pipe = open("request", O_RDONLY);
    read(pipe, processed, sizeof(processed) - 1);
    close(pipe);
    /* printf("%lu\n", sizeof(processed)); */
    do_something(processed);
    /* printf("%lu\n", sizeof(processed)); */
    pipe = open("response", O_WRONLY);
    write(pipe, processed, sizeof(processed) - 1);
    close(pipe);
  }
  return 0;
}
