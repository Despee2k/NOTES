###### Stacks Array Definition
```c
typedef struct {
  int elem[MAX];
  int top;
} Stack;
```

###### Diagram


###### Functions
1. `init()` - initializes the stack to be empty
2. `push()` - pushes element at the top of the stack
3. `pop()` - pops the element at the top of the stack
4. `top()` - returns the element at the top of the stack
5. `isEmpty()` - checks to see if stack is empty
6. `isFull()` - checks to see if stack is full

###### Complete Code
```c
#include <stdio.h>
#include <stdbool.h>

#define MAX 3

typedef struct {
  int elem[MAX];
  int top;
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
  s->top = 0;
}

void push(Stack *s, int data){
  if(s->top < MAX){
    s->elem[s->top++] = data;
  }
  else printf("FULL!\n");
}

void pop(Stack *s){
  if(s->top > 0){
    s->top--;
  }
  else printf("EMPTY!\n");
}

int top(Stack s){
  return (s.top > 0)? s.elem[s.top-1]: -1;
}

bool isEmpty(Stack s){
  return (s.top == 0)? true : false;
}

bool isFull(Stack s){
  return (s.top == MAX)? true : false;
}

void printer(Stack s){
  int count = s.top;
  for(int i = 0; i < count; i++){
    printf("[%d]", top(s));
    pop(&s);
  }
  printf("\n");
}
```
