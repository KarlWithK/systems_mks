#include "funs.h"
#include <stdio.h>
#include <string.h>

int main() {
  int arr[5], ray[5], i;
  float result;
  printf("part 1\n");
  for (i = 0; i < 5; i++) {
    *(arr + i) = i * 5;
    /* printf("arr[%d] equals to %d\n", i, *(arr + i)); */
  }
  result = average(arr, 5);
  printf("%f\n", result);
  printf("part 2\n");
  copy(arr, ray, 5);
  for (i = 0; i < 5; i++) {
    printf("ray[%d] equals to %d\n", i, *(ray + i));
  }

  printf("part 3\n");
  char s[] = "karl";
  int x = len(s);
  printf("%d\n", x);

  printf("part 4\n");
  char cpy[5], cat[9] = "Mr. ";
  strncpy(cpy, s, x);
  printf("%s\n",
         cpy); // even when I copy five values it still works. If I make
               // chars with 4 bytes if gives me an overflow not good.
  strncat(cat, cpy, x);
  printf("%s\n", cat);
  int cmp = strcmp(cat, cpy); // ascii comparison A is lower than a
  printf("%d\n", cmp);
  char *cp = strchr(cat, 'k'), *lcp = strrchr(cat, 'r');
  printf("cp is %p and lcp is %p\n", cp, lcp);
  *cp = 'C';
  printf("%s\n", cat);
  *lcp = 'a'; // like kal el? superman
  printf("%s\n", cat);

  return 0;
}
