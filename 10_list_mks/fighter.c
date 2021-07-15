#include "fighter.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Fighter *create_fighter(char *street_name, int level, int deaths) {
  struct Fighter *mars = malloc(sizeof(struct Fighter));
  // Pointing to a char pointer so have to use this function below
  mars->street_name = strdup(street_name);
  mars->powerlevel = level;
  mars->times_revieved = deaths;
  mars->next = NULL;
  return mars;
}

struct Fighter *clear_fighter(struct Fighter *fighter_name) {
  free(fighter_name->street_name);
  free(fighter_name);
  return NULL;
}

void print_fighter(struct Fighter *street_name) {
  printf("Fighter's street name: %s, powerlevel: %d, times killed: %d",
         street_name->street_name, street_name->powerlevel,
         street_name->times_revieved);
}

void change_street_name(struct Fighter *street_name, char *new_steet_name) {
  street_name->street_name = strdup(new_steet_name);
}

void increase_deaths(struct Fighter *street_name) {
  street_name->times_revieved++;
}

void print_list(struct Fighter *nodep) {
  printf("[");
  while (nodep) {
    print_fighter(nodep);
    printf(", ");
    nodep = nodep->next;
  }
  printf("]\n");
}

struct Fighter *free_list(struct Fighter *nodep) {
  struct Fighter *curr = nodep;
  while (curr) {
    curr = curr->next;
    clear_fighter(nodep);
    nodep = curr;
  }
  return nodep;
}

struct Fighter *insert_front(struct Fighter *nodep, char *street_name,
                             int level, int deaths) {

  struct Fighter *new_node = create_fighter(street_name, level, deaths);
  new_node->next = nodep;
  return new_node;
}

struct Fighter *remove_node(struct Fighter *nodep, char *popped) {
  if (!strcmp(nodep->street_name, popped)) {
    struct Fighter *temp = nodep->next;
    nodep = temp;
    return nodep;
  }
  struct Fighter *prev = nodep, *curr = nodep->next;
  while (curr) {
    if (!strcmp(curr->street_name, popped)) {
      prev->next = curr->next;
      clear_fighter(curr);
      return nodep;
    }
    prev = curr;
    curr = curr->next;
  }
  return nodep;
}
