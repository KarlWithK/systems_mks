#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int d_size;
  DIR *current_dir;
  if (argv[1]) {
    current_dir = opendir(argv[1]);
  } else {
    char buffer[100];
    printf("Enter a directory: ");
    fgets(buffer, sizeof(buffer), stdin);
    strtok(buffer, "\n"); // remove the "\n" at the end
    current_dir = opendir(buffer);
  }
  struct dirent *curr = readdir(current_dir);
  /* printf("Statistics for directory: %s\n", "."); */
  while (curr) {
    if (curr->d_type == 4) { // check if it is a dir
      printf("Directory\t%s\n", curr->d_name);
    }
    curr = readdir(current_dir);
  }
  struct stat sb;
  rewinddir(current_dir); // reset pointer
  curr = readdir(current_dir);
  while (curr) {
    if (curr->d_type == 8) { // check if it is a file
      printf("File\t\t%s\n", curr->d_name);
      stat(curr->d_name, &sb);
      d_size += sb.st_size;
    }
    curr = readdir(current_dir);
  }
  printf("Total Size of Files: %d\n", d_size);
  closedir(current_dir);
  return 0;
}
