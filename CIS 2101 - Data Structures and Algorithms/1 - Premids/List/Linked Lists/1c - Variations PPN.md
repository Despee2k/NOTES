Variations of each function implemented using pointer to pointer to node (PPN) List Implementation

[Python Tutor](https://pythontutor.com/c.html#mode=edit)

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} List, *listPtr;

void init(listPtr *L){
  *L = NULL;
}

void insertFirst(listPtr *L, int data){
  listPtr newNode = (listPtr) malloc (sizeof(List));
  if(newNode != NULL){
    newNode->data = data;
  }
  if(*L != NULL){
    newNode->next = *L;
  }
  else newNode->next = NULL;
  *L = newNode;
}

void insertLast(listPtr *L, int data){
  listPtr newNode = (listPtr) malloc (sizeof(List));
  if(newNode != NULL){
    newNode->data = data;
    newNode->next = NULL;
  }
  listPtr *trav;
  for(trav = L; *trav != NULL; trav = &(*trav)->next);
  *trav = newNode;
}

void deleteElem(listPtr *L, int data){
  listPtr *trav;
  listPtr temp;
  for(trav = L; *trav != NULL && (*trav)->data != data; trav = &(*trav)->next);
  if(*trav != NULL){
    temp = *trav;
    *trav = temp->next;
    free(temp);
  }
}

void deleteAllOccur(listPtr *L, int data){
  listPtr *trav;
  listPtr temp;
  for(trav = L; *trav != NULL; ){
    if((*trav)->data == data){
      temp = *trav;
      *trav = temp->next;
      free(temp);
    }
    else trav = &(*trav)->next;
  }
}

void printer(listPtr L){
  for(; L != NULL; L = L->next){
    printf("%d->", L->data);
  }
  printf("NULL\n");
}

int main(void){
  listPtr A;
  init(&A);
  insertFirst(&A, 2);
  insertFirst(&A, 1);
  insertFirst(&A, 1);
  insertFirst(&A, 2);
  // insertFirst(&A, 2);
  // insertLast(&A, 3);
  printer(A);
  deleteAllOccur(&A, 1);
  printer(A);
  return 0;
}
```