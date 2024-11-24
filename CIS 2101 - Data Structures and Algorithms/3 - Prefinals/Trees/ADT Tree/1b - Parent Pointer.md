[Python Tutor](https://pythontutor.com/c.html#mode=edit)

###### Complete Code
```c
#include <stdio.h>

#define MAX 10

typedef int parentPointer[MAX];

typedef struct {
    int items[MAX];
    int top;
} Stack;

// NOTES
// -1 means root
// -2 means null

void initStack(Stack *S){
    S->top = 0;
}

void push(Stack *S, int data){
    if(S->top < MAX){
        S->items[S->top++] = data;
    }
}

void pop(Stack *S){
    S->top--;
}

void populateTree(parentPointer A){
    A[0] = -1;
    A[1] = 0;
    A[2] = 0;
    A[3] = 1;
    A[4] = 1;
    A[5] = 1;
    A[6] = 2; 
    A[7] = 2;
    A[8] = 5;
    A[9] = 5;
}

int rightSibling(parentPointer A, int node){
    int parent = A[node];
    
    return (A[node + 1] == parent) ? node + 1 : -2;
}

int leftMostSibling(parentPointer A, int node){
    int i;
    for(i = 0; i < MAX && A[i] != node; i++);
    
    return (i < MAX) ? i : -2;
}

void preorder(parentPointer A){
    int node;
    Stack S;
    
    initStack(&S);
    node = A[0];
    
    printf("PREORDER: ");
    
    while(1){
        if(node != -2){
            if(node != -1) printf("[%d]", node);    // skip displaying root node
            push(&S, node);
            node = leftMostSibling(A, node);
        } else {
            if(S.top == 0) break;
            node = rightSibling(A, S.items[S.top - 1]);
            pop(&S);
        }
    }
    
    printf("\n");
}

int main(void){
    parentPointer X;

    populateTree(X);
    preorder(X);
    
    return 0;
}
```
