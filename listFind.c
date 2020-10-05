#include <stdio.h>

/*
listFind is used for searches for plates
it takes the pointer to the sentinel node for the heashtable, plate, first, last pointers
it returns 1 if entry is found and 0 if not found
*/

#include "header.h"

int listFind(struct node *ll, char *plate, char *first, char *last) {
  int k=0;
  char dbPlate[120];
  ll=ll->next;
  while (ll!=NULL) { // compare plate entry with every plate in cell
    int dbPlateLen=strlen(ll->plate);

    while(k<=dbPlateLen){  
      dbPlate[k]=ll->plate[k];
      k++;
    }
    if (0==strcmp(plate,dbPlate)) {
      first=ll->first;
      last=ll->last;
      ll=ll->next;

      printf("First name: %s\n",first);
      printf("Last name: %s\n",last);

      return 1;
    }
  ll=ll->next;
  k=0;
  }

  return 0;
}
