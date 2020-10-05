#include <stdio.h>

/*
This file handles all the hash functionality. It is characterized by the Global hashsize variable.
hash functions include:
 - hashInit, initializes list table - takes hashsize returns table
 - hashFunction, calculates the hash number - takes hashsize and plate pointer returns hash number
 - hashAdd, adds entries to list - takes hashTable, plate, first, last
 - hashFind, used for searches -  takes hashTable, plate, first, last
 - hashLoad, used for displaying the cell counts - takes hashTable
 - hashDump, used for printing of either whole database, or cell from database - takes hashtable and cell number
*/

#include "header.h"

int hashSize;

hashEntry* hashInit(int hashSizeInit) {
  int i=0;
  hashSize=hashSizeInit;

  hashEntry*table=malloc(hashSize*(sizeof(struct node)));  // initiates size of hash table

  while (i<hashSize) {
    table[i]=listInit();
    i++;
  }
  return(table);   // returns hash table
}

int hashFunction(int hashSize, char *plate) {
  int i=0, sum=0, hashNumber,plateInput;
  int length=strlen(plate);
  while (i<length) {
    plateInput=plate[i];
    hashNumber=((i+5)*plateInput);  // hash equation
    sum=sum+hashNumber;
    i++;
  }
  sum=sum%hashSize;

  return sum;        // returns hash number
}

void hashAdd(hashEntry *hashTable, char *plate,char *first,char *last) {
  int hashNumber;
  struct node *ll;
  hashNumber=hashFunction(hashSize,plate);
  ll=hashTable[hashNumber];    // associates the correct hash cell for entry
  listAdd(ll,plate,first,last);
}

int hashFind(hashEntry *hashTable, char *plate, char *first, char *last) {
  int returnVal;
  struct node *ll;
  int hashNumber=hashFunction(hashSize,plate);
  ll=hashTable[hashNumber];
  returnVal=listFind(ll, plate, first, last);  // search function
  if (returnVal==1){
    printf("Enter a command or plate: ");
    return 1;   //  returns 1 if found
  }
  else {
    return 0;  // returns 0 if not found
  }
}

void hashLoad(hashEntry *hashTable) {
  int i=0,listCellLength;
  while (i<hashSize) {
    listCellLength=listLen(hashTable[i]);
    printf("Entry %d: length=%d\n",i,listCellLength);  // prints the count for hash table cells
    i++;
  }
  printf("Enter a command or plate: ");
return;
}

void hashDump(hashEntry *hashTable, int cellNum) {
  struct node *ll;
  int i=0;
  if (cellNum==-1) {  // prints out all of the database
    while(i<hashSize){
      printf("Contents of cell %d\n",i);
      ll=hashTable[i];
      listPrint(ll);
      printf("--------------------------------------\n");
      i++;
    }
  }
  else {    //  prints out a certain cell of the database
    printf("Contents of cell %d\n",cellNum);
    ll=hashTable[cellNum];
    listPrint(ll);
    printf("--------------------------------------\n");
  }
  printf("Enter a command or plate: ");
return;
}

void hashFree(hashEntry *hashTable) {
  struct node *ll;
  int i=0;
  while (i<hashSize) {
    ll=hashTable[i];
    listFree(ll);
//    free(hashTable[i]);
    i++;
  }
  free(hashTable);
}
