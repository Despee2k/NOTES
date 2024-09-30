###### Stacks Linked List Definition
```c
typedef struct node {
    int elem;
    struct node *next;
} *Stack;
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
    (*s) = NULL;
}

void push(Stack *s, int elem){
    Stack newNode = malloc(sizeof(struct node));
    if(newNode != NULL){
        newNode->elem = elem;
    }
    newNode->next = ((*s) != NULL) ? (*s) : NULL;
    (*s) = newNode;
}

void pop(Stack *s){
    if((*s) != NULL){
        Stack temp = (*s);
        (*s) = temp->next;
        free(temp);
    }
    else printf("EMPTY!\n");
}

int top(Stack *s){
    return (*s)->elem;
}

Boolean isEmpty(Stack *s){
    return ((*s) == NULL) ? TRUE : FALSE;
}

Boolean isFull(Stack *s){
    printf("LINKED LIST WILL NEVER BE FULL\n");
    return FALSE;
}

void printBoolean(Boolean b){
    printf("%s\n", (b == TRUE) ? "TRUE" : "FALSE");
}
```