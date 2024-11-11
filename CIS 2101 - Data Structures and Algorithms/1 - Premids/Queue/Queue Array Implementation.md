###### Queue Array Definition
```c
#define MAX 5;

typedef struct {
	int elem[MAX];
	int front;
	int rear;
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
#include <stdbool.h>

#define MAX 5

typedef struct {
  int elem[MAX];
  int front;
  int rear;
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
  q->front = 0;
  q->rear = -1;
}

void Enqueue(Queue *q, int data){
  if(q->rear < MAX-1){
    q->elem[++q->rear] = data;
  }
  else printf("FULL!\n");
}

void Dequeue(Queue *q){
  if(q->rear != -1){
    int count = q->rear;
    for(int i = 0; i < count; i++){
      q->elem[i] = q->elem[i+1];
    }
    q->rear--;
  }
  else printf("EMPTY!\n");
}

void printer(Queue q){
  int count = q.rear + 1;
  for(int i = 0; i < count; i++){
    printf("[%d]", q.elem[i]);
  }
  printf("\n");
}

int front(Queue q){
  return (isEmpty(q))? -1 : q.elem[q.front];  
}

bool isEmpty(Queue q){
  return (q.rear == -1)? true : false;
}
```
