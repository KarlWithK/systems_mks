#include "mystring.h"
#include <stdio.h>

int mystrlen(char *s) {
  int len = 0;
  /* s[len] = *(s + len) */
  while (s[len]) {
    len++;
  }
  return len;
}

char *mystrcpy(char *s1, char *s2) {
  // assumes s2 ends with a '\0'
  int len = 0;
  while (s2[len]) {
    s1[len] = s2[len];
    len++;
  }
  s1[len] = '\0';
  return s1;
}

// hello -> goolo

char *mystrncpy(char *s1, char *s2, int size) {
  int len;
  while (len < size && s2[len]) {
    s1[len] = s2[len];
    len++;
  }
  for (; len < size; len++) {
    s1[len] = '\0';
  }
  return s1;
}

char *mystrcat(char *s1, char *s2) {
  int len = 0, starting_index = mystrlen(s1);
  while (s2[len]) {
    s1[starting_index + len] = s2[len];
    len++;
  }
  s2[starting_index + len] = '\0';
  return s1;
}

char *mystrncat(char *s1, char *s2, int size) {
  int len = 0, starting_index = mystrlen(s1);
  while (len < size && s2[len]) {
    s1[starting_index + len] = s2[len];
    len++;
  }
  s2[starting_index + len] = '\0';
  return s1;
}

char *mystrchr(char *s, int c) {
  int len;
  for (len = 0; len <= mystrlen(s); len++) {
    if (*(s + len) == c)
      return s + len;
  }
  return NULL;
}

int mystrcmp(char *s1, char *s2) {
  while (*s1 || *s2) {
    if (*s1 < *s2)
      return -1;
    if (*s1 > *s2)
      return 1;
    s1++;
    s2++;
  }
  return 0;
}
