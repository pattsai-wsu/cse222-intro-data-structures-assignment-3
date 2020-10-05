#include <stdio.h>

/*
listAdd is used for adding entries to the list.
it take a pointer to the hashtable sentinal, the plate, first and last pointers
it returns nothing.
*/

#include "header.h"

void listAdd(struct node* sent,char *plate,char *first,char *last) {
  struct node *temp;
  temp=malloc(sizeof(struct node));   //  creates the temp node
  temp->next=sent->next;
  sent->next=temp;

  int plateLen=strlen(plate);
  if (plateLen==0) {  // if a database file has a null entry where a plate should be it ERRORs to exit
    printf("ERROR: database invalid - plate of 0 length exists\n");
    exit(1);
  }
  temp->plate=malloc(strlen(plate)+1);
  strcpy(temp->plate,plate);  // copies contents to field

  temp->first=malloc(strlen(first)+1);
  strcpy(temp->first,first); // copies contents to field
  if (temp->first[0]==' ' || temp->first[0]=='\n') {  // if a db file does not have a valid name to go with a plate, it Errors to exit
    printf("ERROR: database invalid - entry with no name associated  exists\n");
    exit(1);
  }

  temp->last=malloc(strlen(last)+1);
  strcpy(temp->last,last); // copies contents to field

return;
}
