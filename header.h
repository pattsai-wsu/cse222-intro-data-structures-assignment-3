#include <stdlib.h>
#include <math.h>
#include <string.h>

struct node {
  char *plate;
  char *first;
  char *last;
  int hashNumber;
  struct node *next;
};

typedef struct node* hashEntry;

hashEntry* hashInit(int);
struct node* listInit();
void databaseHandler(FILE*, hashEntry*, char*, char*, char*);
void hashAdd(hashEntry*, char*, char*, char*);
void listAdd(struct node*,char*,char*,char*);  
int hashFunction(int hashSize, char *);
int hashFind(hashEntry*, char*, char*, char*);
int listFind(struct node*, char*, char*, char*);
void hashDump(hashEntry*, int);
void listPrint(struct node*);
void hashLoad(hashEntry*);
int listLen(struct node*);
void hashFree(hashEntry*);
void listFree(struct node*);
