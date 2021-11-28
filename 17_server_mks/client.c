#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#define WKP "./wkp"
#define SERVER "./processor"
#define CLIENT "./controller"
#define PERMS 0664
#define BUF_SIZE 256

const char confirm[] = "ACK";

static void sighandler(int signo) {
  if (signo == SIGINT) {
    printf("Connection ended.");
    exit(0);
  }
}

void handshake() {
  // private FIFO Name
  char wkp[BUF_SIZE];
  sprintf(wkp, "%d", getpid());

  // Client sends name
  printf("[1] Sending name..\n");
  int fd = open(WKP, O_WRONLY);
  if (fd == -1) {
    printf("Error opening WKP. %s\n", strerror(errno));
    exit(-1);
  }

  // writes name to wkp
  int w_status = write(fd, wkp, sizeof(wkp));
  if (w_status == -1) {
    printf("Error writing to FIFO. %s\n", strerror(errno));
    exit(-1);
  }

  // clients receives sserver's message
  mkfifo(wkp, PERMS);
  int connection = open(wkp, sizeof(wkp));
  char response[BUF_SIZE];
  int r_status = read(connection, response, sizeof(response));
  if (r_status == -1) {
    printf("Error reading from server. %s\n", strerror(errno));
    exit(-1);
  }

  unlink(wkp);
  printf("[3] Acknowledgement from server received: \"%s\"\n", response);

  w_status = write(fd, confirm, sizeof(confirm));
  if (w_status == -1) {
    printf("Error writing to server. %s\n", strerror(errno));
    exit(-1);
  }
  close(fd);
  close(connection);
}

int main() {
  handshake();
  signal(SIGINT, sighandler);
  char buffer[BUF_SIZE];
  int link;

  while (1) {
    printf("Send rot13 message: ");
    fgets(buffer, BUF_SIZE, stdin);
    link = open(SERVER, O_WRONLY);
    if (!strcmp(buffer, "quit")) {
      printf("Connection ended");
      break;
    }
    write(link, buffer, sizeof(buffer));
    close(link);
    link = open(CLIENT, O_RDONLY);
    read(link, buffer, sizeof(buffer));
    close(link);
    printf("%s", buffer);
  }
  return 0;
}
