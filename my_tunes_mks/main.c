#include "shux.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int *arr, int left, int middle, int right) {
  int i, lo = 0, hi = 0;
  int l_size = middle - left + 1;
  int r_size = right - middle;
  int lvec[l_size], rvec[r_size];

  for (i = 0; i < l_size; i++) {
    lvec[i] = arr[left + i];
    /* printf("left[%d]: %d\n", i, lvec[i]); */
  }
  for (i = 0; i < r_size; i++) {
    rvec[i] = arr[middle + 1 + i];
    /* printf("right[%d]: %d\n", i, rvec[i]); */
  }

  i = left;

  while (lo < l_size && hi < r_size) {
    if (lvec[lo] < rvec[hi]) {
      arr[i] = lvec[lo];
      lo++;
    } else {
      arr[i] = rvec[hi];
      hi++;
    }
    i++;
  }

  for (; i < (right + 1); ++i) {
    if (hi != r_size) {
      arr[i] = rvec[hi];
      hi++;
    } else {
      arr[i] = lvec[lo];
      lo++;
    }
  }
}
void merge_sort(int *arr, int left, int right) {
  if (left < right) {
    int middle = (right + left) / 2;

    merge_sort(arr, left, middle);
    merge_sort(arr, middle + 1, right);

    merge(arr, left, middle, right);
  }
}

int main() {
  srand(time(NULL));
  int arr[10];
  int i;
  int arr_size = sizeof(arr) / sizeof(arr[0]);
  for (i = 0; i < 10; i++) {
    arr[i] = rand() % 23;
    printf("arr[%d]: %d\n", i, arr[i]);
  }
  merge_sort(arr, 0, arr_size - 1);
  for (i = 0; i < 10; i++) {
    printf("sort[%d]: %d\n", i, arr[i]);
  }
  return 0;
}

/* int main() { */
/*      struct song *shux[27]; */
/*      for(int i = 0; i < 27; i++) { */
/*              shux[i] = NULL; */
/*      } */
/*      shux[0] = new_song("ATM", "JCole"); */
/*      print_list(shux[0]); */
/*      struct song *free = free_list(shux[0]); */
/*      return 0; */
/* } */
