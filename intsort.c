# include<stdio.h>
# include <stdlib.h>
#include "intsort.h"

int main(){
  printf("type some integers ending with -1: \n");
  IntNode *header;
  header = NULL;

  while(1){
    int nextInt;
    scanf("%d", &nextInt);
    if (nextInt == -1){ //scan input values until we reach -1
      break;
    }
    if (header == NULL){ //create the first node
      header = createNode(nextInt);
      continue;
    }
    insert(header, nextInt);
  }
  printAll(header);
}

IntNode * createNode(int val){
  IntNode * newNode;
  newNode = malloc(sizeof(IntNode)); //allocate the space needed
  newNode-> item = val; //give node current value
  newNode-> next = NULL;
  return newNode;
}

void insert(IntNode *header, int val){
  IntNode *present = header;
  if (val < present->item){
    int temp = present->item;
    present->item = val;
    IntNode *newNode = createNode(temp);
    newNode->next = present->next;
    present->next = newNode;
  }
  else{
    while (present-> next != NULL && present->next->item < val){
      present = present->next;
    }
    IntNode *newNode = createNode(val);
    newNode->next = present->next;
    present->next = newNode;
  }
}

void printAll(IntNode * header){
  IntNode *present = header;
  printf("yeezey sorted looking like: \n");
  while (present != NULL){
    printf(" %d ", present->item);
    present = present->next;
  }
  printf("\n");
}
