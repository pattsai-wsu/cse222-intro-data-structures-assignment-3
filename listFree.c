#include <stdio.h>

/*
listFree frees up all the malloc'd memory
have to go through all the times the program created a field with malloc
*/

#include "header.h"

void listFree(struct node *ll) {
  struct node *previous;
  struct node *current;

  previous=ll;
  current=ll->next;

  while (current != NULL) {
    free(previous->plate);
    free(previous->first);
    free(previous->last);
    free(previous);
    previous=current;
    current=current->next;
  }
  free(previous->plate);
  free(previous->first);
  free(previous->last);
  free(previous);
}
