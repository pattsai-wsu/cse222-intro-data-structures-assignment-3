#include <stdio.h>

/*
listInit initializes the sentinel node and returns
a pointer to it
*/

#include "header.h"

struct node* listInit() {
  struct node *sent;
  sent=malloc(sizeof(struct node));
  sent->next=NULL;

  return(sent);  // returns pointer to sent node
}
