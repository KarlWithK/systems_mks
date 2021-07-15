#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define FILE "/dev/random"

int get_random() {
  int fd;
  fd = open(FILE, O_RDONLY);
  if (fd == -1) {
    printf("Error opening file: %s\n", strerror(errno));
    return -1;
  }
  int random_num, check;
  check = read(fd, &random_num, sizeof(random_num));
  close(fd);
  if (check == -1) {
    printf("Error reading file: %s\n", strerror(errno));
    return -1;
  }
  return random_num;
}

int main() {
  int ray[10], arr[10], i, fd, w_check, r_check;
  printf("%s\n", "Generating random numbers:");
  for (i = 0; i < 10; ++i) {
    ray[i] = get_random();
    printf("\trandom %d: %d\n", i, ray[i]);
  }
  printf("%s\n", "Writing numbers to file...");
  fd = open("nums", O_CREAT | O_WRONLY, 0664);
  if (fd == -1) {
    printf("Error opening file: %s\n", strerror(errno));
    return -1;
  }
  w_check = write(fd, ray, sizeof(ray));
  if (w_check == -1) {
    printf("Error writing file: %s\n", strerror(errno));
    return -1;
  }
  close(fd);
  printf("%s\n", "Reading numbers from file...");
  fd = open("nums", O_RDONLY);
  if (fd == -1) {
    printf("Error opening file: %s\n", strerror(errno));
    return -1;
  }
  r_check = read(fd, arr, sizeof(arr));
  if (r_check == -1) {
    printf("Error reading file: %s\n", strerror(errno));
    return -1;
  }
  printf("%s\n", "Verification that written values were the same:");
  for (i = 0; i < 10; ++i) {
    printf("\trandom %d: %d\n", i, arr[i]);
  }
  close(fd);
  return 0;
}
