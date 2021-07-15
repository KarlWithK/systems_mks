#include <stdio.h>

int main() {
  // part 1
  char chr = 'a';
  int x = 6;
  long y = 4;

  // part 2 - addresses are very close to each other
  printf("Part 2\n");
  printf("Value of chr in hex: %p\n", &chr);
  printf("Value of chr in decimal: %ld\n", &chr); // printed out in 0x7ffef8f5673b - 1 byte
  printf("Value of chr in hex: %p\n", &x);
  printf("Value of chr in decimal: %ld\n", &x);
  // printed out in 0x7ffef8f5673c - 4 bytes
  printf("Value of chr in hex: %p\n", &y);
  printf("Value of chr in decimal: %ld\n", &y);
  // printed out in 0x7ffef8f56740

  // part3
  char *cp = &chr;
  int *xp = &x;
  long *yp = &y;

  // part 4
  printf("\n");
  printf("Part 4\n");
  printf("Value in pointer is cp: %c\n", *cp);
  printf("Value in pointer is xp: %d\n", *xp);
  printf("Value in pointer is yp: %ld\n", *yp);

  // part 5
  *cp = 'z';
  *xp = 64;
  *yp = 2;

  printf("\n");
  printf("Part 5\n");
  printf("Value in pointer is cp: %c\n", *cp);
  printf("Value in pointer is xp: %d\n", *xp);
  printf("Value in pointer is yp: %ld\n", *yp);

  // part 6
  unsigned int z = 64993302;
  int *zip = &z;
  char *zcp = &z;

  // part 7
  printf("\n");
  printf("Part 7\n");
  printf("zip: %p and zip points to: %u\n", zip, *zip);
  printf("zcp: %p and zcp points to: %hhu\n", zcp, *zcp);

  // part 8
  printf("\n");
  printf("Part 8\n");
  printf("Value of z in hex: %x\n", z);
  printf("Value of z in decimal: %u\n", z);

  // part 9
  printf("\n");
  printf("Part 9\n");
  printf("Byes of zcp\n");
  int i, j;
  printf("Decimal: ");
  for (i = 0; i < 4; i++) {
    printf("%hhu ", *(zcp + i));
  }
  printf("\n");
  printf("Hex: ");
  for (j = 0; j < 4; j++) {
    printf("%hhx ", *(zcp + j));
  }
  printf("\n");

  // part 10
  printf("\n");
  printf("Part 10\n");
  printf("New zcp: ");
  for (i = 0; i < 4; i++) {
    *(zcp + i) += 1;
    printf("%hhu (dec), %hhx (hexa)\t", *(zcp + i), *(zcp + i));
  }
  printf("\n");

  // part 11
  printf("\n");
  printf("Part 11\n");
  printf("New new zcp: ");
  for (i = 0; i < 4; i++) {
    *(zcp + i) += 16;
    printf("%hhu (dec), %hhx (hexa)\t", *(zcp + i), *(zcp + i));
  }
  printf("\n");
  return 0;
}
