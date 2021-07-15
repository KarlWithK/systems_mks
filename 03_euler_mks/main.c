#include <math.h>
#include <stdio.h>

int multiples_15() {
  int x = 2, result = 0;
  while (x < 1000) {
    if (x % 5 == 0 || x % 3 == 0) {
      result += x;
    }
    x++;
  }
  printf("Sum is %d\n", result);
  return 0;
}

int smallest_multiple() {
  unsigned long num = 2520, fix = 2520;
  int current_num = 11;
  while (current_num < 21) {
    if (num % current_num == 0) {
      fix = num;
      current_num++;
    } else {
      num += fix;
    }
  }
  printf("Smallest positive number is %ld\n", num);
  return 0;
}

int sum_square_difference() {
  long result = 0, num = 1;
  while (num < 101) {
    result += pow(num, 3) - pow(num, 2);
    num++;
  }
  printf("The difference of squares is: %ld\n", result);
  return 0;
}

int main() {
  multiples_15();
  smallest_multiple();
  sum_square_difference();
  return 0;
}
