#include <stdio.h>

/*
listPrint prints out the required format for search results
it takes the pointer to the found record and prints the name
of the record.
*/

#include "header.h"

void listPrint(struct node* ll) {
  ll=ll->next;
  while(ll!=NULL) {
    if (ll->last[0]=='\0') {  // this is the handling for people with one name
      printf("Plate: <%s>   Name: %s\n",ll->plate,ll->first);
    }
    else {  // if person has both first and last name, then print this
      printf("Plate: <%s>   Name: %s, %s\n",ll->plate,ll->last,ll->first);
    }
    ll=ll->next;
  }
}
