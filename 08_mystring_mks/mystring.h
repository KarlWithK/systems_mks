#ifndef MYSTRING_H
#define MYSTRING_H

int mystrlen(char *s);
char *mystrcpy(char *s1, char *s2);
char *mystrcat(char *s1, char *s2);
char *mystrncpy(char *s1, char *s2, int size);
char *mystrncat(char *s1, char *s2, int size);
char *mystrchr(char *s, int c);
int mystrcmp(char *s1, char *s2);
char *mystrstr(char *, char *);

#endif
