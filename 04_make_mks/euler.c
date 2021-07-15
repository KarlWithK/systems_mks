#include "euler.h"
#include <math.h>

int multiples_15(int limit) {
  int x, result = 0;
  for (x = 2; x < limit; ++x) {
    if (x % 5 == 0 || x % 3 == 0) {
      result += x;
    }
  }
  return result;
}

int smallest_multiple(int limit) {
  unsigned int num = 2520, fix = 2520;
  int current_num = 11;
  while (current_num < limit) {
    if (num % current_num == 0) {
      fix = num;
      current_num++;
    } else {
      num += fix;
    }
  }
  return num;
}

int sum_square_difference(int limit) {
  long result = 0;
  int num;
  for (num = 1; num < limit; ++num) {
    result += pow(num, 3) - pow(num, 2);
  }
  return result;
}
