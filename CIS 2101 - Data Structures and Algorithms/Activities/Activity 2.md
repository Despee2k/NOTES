### Find Middle
Write the code of the function that will return the given middle element of the given linked list. Return a dummy value if list is empty.
###### Conditions
1. 1 traversal only
2. 1 return statement only
3. Assume elements are positive integers

### Answer:
###### Declaration
```c
int findMid(List L){
  List slow = L;
  List fast = L;
  if(slow == NULL) slow = -1; //Dummy value
  while(fast != NULL && fast->next != NULL){
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow->data;
}
```

###### Complete Code
```c
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} NT, *List;

void insertLast(List *L, int val){
  List *trav = L;
  List temp = malloc(sizeof(NT));
  for(; (*trav) != NULL; trav = &(*trav)->next);
  if(temp != NULL){
    temp->next = NULL;
    temp->data = val;
    (*trav) = temp;
    }
}

int findMid(List L){
  List slow = L;
  List fast = L;
  if(slow == NULL) slow = -1; //Dummy value
  while(fast != NULL && fast->next != NULL){
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow->data;
}

int main(void){
  List L = NULL;
  insertLast(&L, 1);
  insertLast(&L, 2);
  insertLast(&L, 3);
  insertLast(&L, 4); //Comment this out to make list "odd"
  printf("Middle: %d", findMid(L));
  
  return 0;
}
```

### Date Answered: 21/08/2024
