```c
#include <stdio.h>

int main(void){
  int given = 16;
  int copy = given;
  int result = 0;
  int FSB = 0;
  int pos = 1;
  
  while (given > 0){
    FSB = (given & 1) * pos;
    result += FSB;
    given >>= 1;
    pos *= 10;
  }
  
  printf("Given: %d\n", copy);
  printf("Result: %d\n", result);
  
  return 0;
}
```

```c
#include <stdio.h>

int main(void){
  int given = 8;

  int MSB;
  for(int i = sizeof(int) * 8-1; i >= 0; i--){
    MSB = 1 << i;
    printf("%d", (given & MSB) > 0);
    if(i % 4 == 0) printf(" ");
  }
}
```

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct node {

} List, *listPtr;

void init(listPtr *L){

}

void insertFirst(listPtr *L, int data){

}

void insertLast(listPtr *L, int data){

}

void deleteElem(listPtr *L, int data){

}

void deleteAllOccur(listPtr *L, int data){

}

void printer(listPtr L){

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

```c
#include <stdio.h>
#include <stdbool.h>

#define MAX 5

typedef struct {

} Queue;

void init(Queue *q);
void Enqueue(Queue *q, int data);
void Dequeue(Queue *q);
int front(Queue q);
bool isEmpty(Queue q);
void printer(Queue q);

int main(void){
  Queue A;
  init(&A);
  printf("Empty: %s\n", (isEmpty(A))? "YES": "NO");
  Dequeue(&A);
  Enqueue(&A, 1);
  Enqueue(&A, 2);
  Enqueue(&A, 3);
  printf("Front: %d\n", front(A));
  printer(A);
  Dequeue(&A);
  printer(A);
  
  return 0;
}

void init(Queue *q){

}

void Enqueue(Queue *q, int data){

}

void Dequeue(Queue *q){

}

void printer(Queue q){

}

int front(Queue q){

}

bool isEmpty(Queue q){

}
```

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
  int data;
  struct node *next;
} List, *listPtr;

typedef struct {

} Queue;

void init(Queue *q);
void Enqueue(Queue *q, int data);
void Dequeue(Queue *q);
int front(Queue q);
bool isEmpty(Queue q);
void printer(Queue q);

int main(void){
  Queue A;
  init(&A);
  printf("Front: %d\n", front(A));
  printf("Queue is empty: %s\n", isEmpty(A) ? "TRUE" : "FALSE");
  Enqueue(&A, 1);
  Enqueue(&A, 2);
  Enqueue(&A, 3);
  printer(A);
  Dequeue(&A);
  printf("Front: %d\n", front(A));
  printer(A);
  
  return 0;
}

void init(Queue *q){

}

void Enqueue(Queue *q, int data){

}

void Dequeue(Queue *q){

}

int front(Queue q){

}

bool isEmpty(Queue q){

}

void printer(Queue q){

}
```

```c
#include <stdio.h>
#include <stdbool.h>

#define MAX 3

typedef struct {

} Stack;

void init(Stack *s);
void push(Stack *s, int data);
void pop(Stack *s);
int top(Stack s);
bool isEmpty(Stack s);
bool isFull(Stack s);
void printer(Stack s);

int main(void){
  Stack A;
  init(&A);
  printf("Empty: %s\n", (isEmpty(A))? "YES" : "NO");
  push(&A, 1);
  push(&A, 2);
  push(&A, 3);
  printf("Full: %s\n", (isFull(A))? "YES" : "NO");
  printf("Top: %d\n", top(A));
  printer(A);
  pop(&A);
  printer(A);
  printf("Full: %s\n", (isFull(A))? "YES" : "NO");

  return 0;
}

void init(Stack *s){

}

void push(Stack *s, int data){

}

void pop(Stack *s){

}

int top(Stack s){

}

bool isEmpty(Stack s){

}

bool isFull(Stack s){

}

void printer(Stack s){

}
```

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int elem;
    struct node *next;
} *Stack;

typedef enum {TRUE, FALSE} Boolean;

int top(Stack *s);
void pop(Stack *s);
void push(Stack *s, int elem);
void initStack(Stack *s);
Boolean isEmpty(Stack *s);
Boolean isFull(Stack *s);

//Boolean printer
void printBoolean(Boolean b);

int main(void){
    Stack X;
    initStack(&X);
    printBoolean(isEmpty(&X));
    pop(&X);
    push(&X, 1);
    push(&X, 2);
    push(&X, 3);
    pop(&X);
    printf("TOP: %d\n", top(&X));
    printBoolean(isFull(&X));
    
    return 0;
}

void initStack(Stack *s){

}

void push(Stack *s, int elem){

}

void pop(Stack *s){

}

int top(Stack *s){

}

Boolean isEmpty(Stack *s){

}

Boolean isFull(Stack *s){
    printf("LINKED LIST WILL NEVER BE FULL\n");
    return FALSE;
}

void printBoolean(Boolean b){

}
```

```c
#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to create a new node
struct ListNode* createNode(int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertLast(struct ListNode** head, int value) {
    struct ListNode* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct ListNode* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to merge two sorted lists
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode *newList = NULL;
  struct ListNode *trav = list1;
    struct ListNode *temp;
    while (list1 != NULL && list2 != NULL) {
      if(newList != NULL){
        for (;newList->next != NULL; newList = newList->next);
      }
        if (list1->val <= list2->val) {
            temp = list1;
            list1 = list1->next;
        }
        else {
            temp = list2;
            list2 = list2->next;
        }
        if(newList != NULL){
            newList->next = temp;
            newList->next->next = NULL;
        }
        else {
          newList = temp;
          newList->next = NULL;
        }
    }
    if (list1 == NULL && list2 != NULL) {
      newList = newList->next;
        newList->next = list2;
    }
    if (list2 == NULL && list1 != NULL) {
      newList = newList->next;
        newList->next = list1;
    }
    return trav;
}

// Function to print the linked list
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    // Create two linked lists A and B
    struct ListNode* A = NULL;
    struct ListNode* B = NULL;

    // Insert elements into list A: 1, 2, 4
    insertLast(&A, 1);
    insertLast(&A, 2);
    insertLast(&A, 4);

    // Insert elements into list B: 1, 3, 4
    insertLast(&B, 1);
    insertLast(&B, 3);
    insertLast(&B, 4);

    // Merge the two lists
    struct ListNode* mergedList = mergeTwoLists(A, B);

    // Print the merged list
    printList(mergedList);

    return 0;
}
 
```