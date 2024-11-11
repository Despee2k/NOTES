###### Queue Linked List Definition
```c
typedef struct node {
	int data;
	struct node *next;
} List, *listPtr;

typedef struct {
	listPtr front;
	listPtr rear;
} Queue;
```

###### Diagram


###### Functions
1. `init()` - initializes the queue to be empty
2. `Enqueue()` - inserts an element into the rear
3. `Dequeue()` - deletes an element in the front
4. `front()` - returns the data in the front
5. `isEmpty()` - checks to see if the queue is empty

###### Complete Code
```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
  int data;
  struct node *next;
} List, *listPtr;

typedef struct {
  listPtr front;
  listPtr rear;
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
  q->front = NULL;
  q->rear = NULL;
}

void Enqueue(Queue *q, int data){
  listPtr newNode = (listPtr) malloc (sizeof(List));
  if(newNode != NULL){
    newNode->data = data;
    newNode->next = NULL;
  }
  if(q->front == NULL){
    q->front = newNode;
  }
  else q->rear->next = newNode;
  q->rear = newNode;
}

void Dequeue(Queue *q){
  if(q->front != NULL){
    listPtr temp = q->front;
    q->front = temp->next;
    free(temp);
    
    if(q->front == NULL){
      q->rear = NULL;
    }
  }
}

int front(Queue q){
  int temp = -1;
  
  if(q.front != NULL){
    temp = q.front->data;
  }
  
  return temp;
}

bool isEmpty(Queue q){
  return (q.front == NULL)? true : false;
}

void printer(Queue q){
  for(;q.front != NULL; q.front = q.front->next){
    printf("%d->", q.front->data);
  }
  printf("NULL\n");
}
```


