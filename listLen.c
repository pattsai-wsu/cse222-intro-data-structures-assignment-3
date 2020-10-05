#include <stdio.h>

/*
listLen counts the number of entries for each cell
it takes the cell pointer and returns the number of entries
*/

#include "header.h"

int listLen(struct node *ll) {
  int count=0;
  ll=ll->next;
  while(ll!=NULL){
    count++;
    ll=ll->next;
  }
return (count);  // return the count of entries
}
