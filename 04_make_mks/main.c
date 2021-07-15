#include "euler.h"
#include <stdio.h>

int main() {
  int x1 = 1000, x2 = 21, x3 = 101;
  printf("Sum is %d\n", multiples_15(x1));
  printf("Smallest positive number is %d\n", smallest_multiple(x2));
  printf("The difference of squares is: %d\n", sum_square_difference(x3));

  return 0;
}
