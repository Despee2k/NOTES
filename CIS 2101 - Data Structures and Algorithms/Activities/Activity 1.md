###### Linked list definition
```c
typedef struct node {
	int data;
	struct node *next;
} *List;
```
# A. Initialize the list to be empty

### 1. With header cell
```c
List initListWithHeader(){
	List L = malloc(sizeof(struct node));
	L->next = NULL;
	return L;
}
```
### 2. Without header cell
```c
List initListNoHeader(){
	List L = NULL;
	return L;
}
```

# B. Function insertLast()

### 1. List with header cell and using [[Look-ahead technique]]

###### Declaration
```c
void insertLast(List *LL, int val){
  List newNode = malloc (sizeof(NT));
  List trav = (*LL);
  newNode->data = val;
  newNode->next = NULL;
  if((*LL)->next == NULL){
    (*LL)->next = newNode;
  }
  else {
    for(; trav->next != NULL; trav = trav->next);
    trav->next = newNode;
  }
}
```
###### Complete Code
```c
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} *List;

void insertLast(List *LL, int val){
  List newNode = malloc (sizeof(struct node));
  List trav = (*LL);
  newNode->data = val;
  newNode->next = NULL;
  if((*LL)->next == NULL){
    (*LL)->next = newNode;
  }
  else {
    for(; trav->next != NULL; trav = trav->next);
    trav->next = newNode;
  }
}

void printer(List L){
  L = L->next;
  for(;L != NULL; L = L->next) printf("%d->", L->data);
  printf("NULL\n");
}

List initListWithHeader(){
	List L = malloc(sizeof(struct node));
	L->next = NULL;
	return L;
}

int main(void){
  List L = initListWithHeader();
  insertLast(&L, 1);
  insertLast(&L, 2);
  insertLast(&L, 3);
  printer(L);
  
  return 0;
}
```

### 2. Without header cell
#### Version 1 - Using [[Pointer to pointer to node (PPN)]]

###### Declaration
```c
void insertLast(List *LL, int val){
  List *trav = LL;
  for(; (*trav) != NULL; trav = &(*trav)->next);
  List temp = malloc (sizeof(NT));
  if(temp != NULL){
	  temp->data = val;
	  temp->next = NULL;
	  (*trav) = temp;
  }
}
```
###### Complete Code
```c
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} *List;

void insertLast(List *LL, int val){
  List *trav = LL;
  for(; (*trav) != NULL; trav = &(*trav)->next);
  List temp = malloc (sizeof(NT));
  if(temp != NULL){
	  temp->data = val;
	  temp->next = NULL;
	  (*trav) = temp;
  }
}

void printer(List L){
  for(;L != NULL; L = L->next) printf("%d->", L->data);
  printf("NULL\n");
}

List initListNoHeader(){
	List L = NULL;
	return L;
}

int main(void){
  List L = initListNoHeader();
  insertLast(&L, 1);
  insertLast(&L, 2);
  insertLast(&L, 3);
  printer(L);
  return 0;
}
```

#### Version 2 - Using [[Look-ahead technique]]

###### Declaration
```c
void insertLast(List *LL, int val){
  List newNode = malloc (sizeof(struct node));
  List trav = (*LL);
  newNode->data = val;
  newNode->next = NULL;
  if((*LL) == NULL){
    (*LL) = newNode;
  }
  else {
    for(; trav->next != NULL; trav = trav->next);
    trav->next = newNode;
  }
}
```
###### Complete Code
```c
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} *List;

void insertLast(List *LL, int val){
  List newNode = malloc (sizeof(struct node));
  List trav = (*LL);
  newNode->data = val;
  newNode->next = NULL;
  if((*LL) == NULL){
    (*LL) = newNode;
  }
  else {
    for(; trav->next != NULL; trav = trav->next);
    trav->next = newNode;
  }
}

void printer(List L){
  for(;L != NULL; L = L->next) printf("%d->", L->data);
  printf("NULL\n");
}

List initListNoHeader(){
	List L = NULL;
	return L;
}

int main(void){
  List L = initListNoHeader();
  insertLast(&L, 1);
  insertLast(&L, 2);
  insertLast(&L, 3);
  printer(L);
  
  return 0;
}
```

# C. Function deleteElem()

### 1. List without header cell using [[Pointer to pointer to node (PPN)]] 

###### Declaration
```c
void deleteElem(List *LL, int val){
  List temp;
  List *trav = LL;
  for(; (*trav) != NULL && (*trav)->data != val; trav = &(*trav)->next);
  if((*trav) == NULL) printf("%d does not exist!\n", val);
  else {
    temp = (*trav);
    *trav = (*trav)->next;
    free(temp);
    printf("Deleted %d!\n", val);
  }
}
```
###### Complete Code
```c
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} *List;

void insertLast(List *LL, int val){
  List *trav = LL;
  List temp = malloc (sizeof(struct node));
  temp->data = val;
  temp->next = NULL;
  if((*trav) == NULL) (*trav) = temp;
  else {
    for(; (*trav) != NULL; trav = &(*trav)->next);
    (*trav) = temp;
  }
}

void deleteElem(List *LL, int val){
  List temp;
  List *trav = LL;
  for(; (*trav) != NULL && (*trav)->data != val; trav = &(*trav)->next);
  if((*trav) == NULL) printf("%d does not exist!\n", val);
  else {
    temp = (*trav);
    *trav = (*trav)->next;
    free(temp);
    printf("Deleted %d!\n", val);
  }
}

void printer(List L){
  for(;L != NULL; L = L->next) printf("%d->", L->data);
  printf("NULL\n");
}

List initListNoHeader(){
	List L = NULL;
	return L;
}

int main(void){
  List L = initListNoHeader();
  insertLast(&L, 1);
  insertLast(&L, 2);
  insertLast(&L, 3);
  printer(L);
  deleteElem(&L, 2);
  deleteElem(&L, 2);
  printer(L);
  return 0;
}
```
### 2. List without header cell using [[Look-ahead technique]]

###### Declaration
```c
void deleteElem(List *LL, int val){
  List curr = (*LL);
  List trav = (*LL);
  for(; trav->next != NULL && trav->data != val; trav = trav->next){
    if(curr != trav) curr = curr->next;
  }
  if(trav->next == NULL) printf("%d does not exist!\n", val);
  else {
    curr->next = trav->next;
    free(trav);
    printf("Deleted %d!\n", val);
  }
}
```
###### Complete Code
```c
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} *List;

void insertLast(List *LL, int val){
  List newNode = malloc (sizeof(struct node));
  List trav = (*LL);
  newNode->data = val;
  newNode->next = NULL;
  if((*LL) == NULL){
    (*LL) = newNode;
  }
  else {
    for(; trav->next != NULL; trav = trav->next);
    trav->next = newNode;
  }
}

void deleteElem(List *LL, int val){
  List curr = (*LL);
  List trav = (*LL);
  for(; trav->next != NULL && trav->data != val; trav = trav->next){
    if(curr != trav) curr = curr->next;
  }
  if(trav->next == NULL) printf("%d does not exist!\n", val);
  else {
    curr->next = trav->next;
    free(trav);
    printf("Deleted %d!\n", val);
  }
}

void printer(List L){
  for(;L != NULL; L = L->next) printf("%d->", L->data);
  printf("NULL\n");
}

List initListNoHeader(){
    List L = NULL;
    return L;
}

int main(void){
  List L = initListNoHeader();
  insertLast(&L, 1);
  insertLast(&L, 2);
  insertLast(&L, 3);
  printer(L);
  deleteElem(&L, 2);
  deleteElem(&L, 2);
  printer(L);
  return 0;
}
```

### Date Answered: 19/08/2024

TODO: Fix look-ahead technique