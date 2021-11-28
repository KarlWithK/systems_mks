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
// TODO: rewrite this using modern c
const char connected[] = "Connection established. Status Code [200]";

void setup_handshake() {
  // set up handshake
  printf("[0] Waiting for client...\n");

  // WKP = Well Known Pipe
  mkfifo(WKP, PERMS);
  char p_name[BUF_SIZE];
  int fd = open(WKP, O_RDONLY);
  if (fd == -1) {
    printf("Error opening WKP. %s\n", strerror(errno));
    exit(-1);
  }
  int r_status = read(fd, p_name, sizeof(p_name));
  if (r_status == -1) {
    printf("Error reading from WKP. %s\n", strerror(errno));
    unlink(WKP);
    exit(-1);
  }
  unlink(WKP);
  printf("[2] connecting with %s...\n", p_name);

  /// Server tries to connect to client
  int p_connect = open(p_name, O_WRONLY);
  if (p_connect == -1) {
    printf("Error connecting with client. %s\n", strerror(errno));
    exit(-1);
  }
  int w_status = write(p_connect, connected, sizeof(connected));
  if (w_status == -1) {
    printf("Error writing to client. %s\n", strerror(errno));
    exit(-1);
  }

  /// Server receives client's message, and handshake is complete
  char handshake_confirm[256];
  int h_status = read(fd, handshake_confirm, sizeof(handshake_confirm));
  if (h_status == -1) {
    printf("Error reading confirmation from client. %s\n", strerror(errno));
    exit(-1);
  }
  printf("[4] Acknowledgement from client received: \"%s\"\n",
         handshake_confirm);
  close(fd);
}

static void sighandler(int signo) {
  if (signo == SIGPIPE) {
    printf(
        "Client disconnected. Setting up new handshake for next client...\n");
    setup_handshake();
  }
  if (signo == SIGINT) {
    printf("Connection ended.");
    unlink(WKP);
    unlink(SERVER);
    unlink(CLIENT);
    exit(0);
  }
}

// rot 13
void rot13(char *input) {
  int len = strlen(input);
  char current;
  for (int i = 0; i < len; i++) {
    current = input[i];
    if ('a' <= current && current <= 'z') {
      current = (((current - 'a') + 13) % 26) + 'a';
    } else if ('A' <= current && current <= 'Z') {
      current = (((current - 'A') + 13) % 26) + 'A';
    }
    input[i] = current;
  }
}

int main() {
  setup_handshake();
  mkfifo(SERVER, PERMS);
  mkfifo(CLIENT, PERMS);
  signal(SIGINT, sighandler);
  signal(SIGPIPE, sighandler);
  char buffer[BUF_SIZE];
  int link;

  while (1) {
    sleep(3);
    link = open(SERVER, O_RDONLY);
    read(link, buffer, BUF_SIZE);
    if (!strcmp(buffer, "quit")) {
        printf("Connection ended.");
        break;
    }
    close(link);
    printf("Recieved msg: %s", buffer);
    rot13(buffer);
    printf("Message sent: %s", buffer);
    link = open(CLIENT, O_WRONLY);
    write(link, buffer, sizeof(buffer));
    close(link);
  }

  remove(CLIENT);
  remove(SERVER);
  return 0;
}
