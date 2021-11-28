#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define SIZE 6

char *args[SIZE];

char **parse_args(char *line) {
	for(int i = 0; i < SIZE; i++) {
		args[i] = strsep(&line, " ");
	}
	return args;
}

int main() {
	char line[] = "ls -a -l -h";
  char ** args = parse_args(line);
	execvp(args[0], args);
  return 0;
}
