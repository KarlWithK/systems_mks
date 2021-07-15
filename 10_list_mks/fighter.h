#ifndef Fighter_LIST_STRUCT
#define Fighter_LIST_STRUCT
struct Fighter {
  char *street_name;
  int powerlevel;
  int times_revieved;
  struct Fighter *next;
};

struct Fighter *create_fighter(char *street_name, int level, int deaths);
struct Fighter *clear_fighter(struct Fighter *fighter_name);
void print_fighter(struct Fighter *street_name);
void change_street_name(struct Fighter *street_name, char *new_steet_name);
void increase_deaths(struct Fighter *street_name);

void print_list(struct Fighter *nodep);
struct Fighter *insert_front(struct Fighter *nodep, char *street_name,
                             int level, int deaths);
struct Fighter *free_list(struct Fighter *nodep);
struct Fighter *remove_node(struct Fighter *nodep, char *popped);

/* struct chain { */
/*   struct node *head; */
/* }; */

/* chain stuff */
/* struct chain *create_chain(); */
/* struct chain *clear_chain(struct chain *chainp); */
/* void print_chain(struct chain *chainp); */
/* void insert(struct chain *chainp, int data); */
/* int get_size(struct chain *chainp); */
#endif /* ifndef LINK_LIST_STRUCT */
