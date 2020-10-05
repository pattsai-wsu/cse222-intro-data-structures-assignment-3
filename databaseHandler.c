#include <stdio.h>

/*
databaseHandler parses through the database and creates strings
to pass to plate, first, last

this uses what we learning in the parsing program from cse224
*/

#include "header.h"

void databaseHandler(FILE *fptr, hashEntry *hashTable, char *plate, char *first, char *last) {
  char c;
  int total,length=0,i;
  while(1) {
    i=0;
    c=fgetc(fptr);
    if(c==EOF){   // parses file till EOF
      break;
    }
    else {
      while(c!=' '){
          plate[i]=c;
          i++;
          c=fgetc(fptr);
      }
      plate[i]='\0';

      i=0;
      c=fgetc(fptr);
      while(c!=' '){
          first[i]=c;
          i++;
          c=fgetc(fptr);
      }
      first[i]='\0';

      i=0; 
      c=fgetc(fptr);
      while(c!='\n'){
          last[i]=c;
          i++;
          c=fgetc(fptr);
      }
      last[i]='\0';

     hashAdd(hashTable, plate, first, last);  // sends strings to hashAdd

     i=0;                        // renews strings for processing again
     length=strlen(plate);
       while(i<=length){
         plate[i]='\0';
         i++;  
       }
     i=0;
     length=strlen(first);
       while(i<=length){
         first[i]='\0';
         i++;  
       }
     i=0;
     length=strlen(last);
       while(i<=length){
         last[i]='\0';
         i++;  
       }
    }
  }
}
