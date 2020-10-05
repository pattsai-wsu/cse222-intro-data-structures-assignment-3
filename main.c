#include <stdio.h>

/*
NAME: Patrick Tsai
CLASS: CSE 222 M-F 10 AM
DATE DUE: 2/14/2020 8:00 AM
ASSIGNMENT: PA3

SYNOPSIS - This is a program that hashes license plate numbers, and saves them in cells depending on the hash size. The program can search, print out the number of entries in each cell, and display the entire database or a listing of the entries within the cell.

I've added handling for entries for people with only one name. Their single name must be in the first name position for it to work.
*/

#include "header.h"

int main(int argc, char** argv) {
  int i, hashSize, usrNum,returnVal,dumpNum, returnValTemp;
  char c, usrIn[120], temp[120], badTemp[120];
  char plate[120],first[120],last[120],end;

  if (argc==2 || argc==3) {

  if (argc==2) {
    hashSize=100;        // if no hashsize specified use 100
  }

  if (argc==3) {
    returnVal=sscanf(argv[2], "%d%s", &hashSize, badTemp);
    if (returnVal!=1) {
      printf("ERROR: %s is not a valid integer\n", argv[2]);    //  error if user enters something after the number for hashsize on the command line
      exit(1);
    }
    if (hashSize<1) {
      printf("ERROR: %s is not a valid integer\n", argv[2]);     // error if user enters a negative value or 0 for hashsize
      exit(1);
    }
  }

  hashEntry *hashTable;
  hashTable=hashInit(hashSize);

  FILE *fptr;            // pointer for file, and file handling below
  fptr=fopen(argv[1],"r");
  databaseHandler(fptr,hashTable,plate,first,last);
  fclose(fptr);

  printf("Enter a command or plate: ");
  while(fgets(temp, 120, stdin)!=NULL) {
    sscanf(temp,"%s",usrIn);
    if (sscanf(temp, "*DUMP %d%s", &dumpNum, badTemp)==1){
      if (temp[5]!=' ') {
        printf("ERROR: usage, use space between *DUMP and [number]\n");  // error for not entering a space after *DUMP
        printf("Enter a command or plate: ");
      }
      else {
        if (dumpNum >=0 && dumpNum < hashSize) {
          hashDump(hashTable, dumpNum);
        }
        else {
          printf("ERROR: number invalid\n");              // error handling if dump number is larger than hashsize or if smaller than 0
          printf("Enter a command or plate: ");
        }
      }
    }
    else if (sscanf(temp, "*DUMP %d%s", &dumpNum, badTemp)==2){
      printf("ERROR: *DUMP num[%s] is not valid\n",badTemp);    // error handling for dump if string is added after number
      printf("Enter a command or plate: ");
    }
    else if (strcmp(temp,"*DUMP\n")==0){
      dumpNum=-1;
      hashDump(hashTable, dumpNum);
    }
    else if (0==strcmp(usrIn,"*LOAD")) {       // load action
      hashLoad(hashTable);
    }
    else {
      int inputLen=strlen(usrIn);        // search functionality - occurs if dump or load is not called
      usrIn[inputLen]='\0';
      int k=0;
      while(k<inputLen){
        plate[k]=usrIn[k];
        k++;
      }
      plate[k]='\0';
      int returnHashFind=hashFind(hashTable,plate,first,last);
      if (returnHashFind==0) {
        printf("Plate not found\n");
        printf("Enter a command or plate: ");
      }
    }
  }

  hashFree(hashTable);

  }
  else {
    printf("ERROR: program usage\n");   // if user does not enter 2 or 3 commmand line arguments then exit
    exit(1);
  }

  printf("\n"); 

return 0;
}
