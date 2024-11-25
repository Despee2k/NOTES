[Python Tutor](https://pythontutor.com/c.html#mode=edit)

### Complete Code
```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct node {
    int data;
    struct node *next;
} Node, *nodePtr;

typedef struct {
    nodePtr nodes[MAX];
    int root;
} ListOfChildren;

typedef struct {
    int items[MAX];
    int top;
} Stack;

void initLOC(ListOfChildren *L) {
    for (int i = 0; i < MAX; i++) {
        L->nodes[i] = NULL;
    }
    L->root = 0;        // root is node 0
}

void initStack(Stack *S) {
    S->top = 0;
}

void push(Stack *S, int data) {
    if (S->top < MAX) {
        S->items[S->top++] = data;
    }
}

int pop(Stack *S) {
    if (S->top > 0) {
        return S->items[--S->top];
    }
    return -1;
}

int isEmpty(Stack *S) {
    return S->top == 0;
}

void insertTree(ListOfChildren *L, int data, int parent) {
    nodePtr temp = (nodePtr)malloc(sizeof(Node));
    if (temp != NULL) {
        temp->data = data;
        temp->next = NULL;
    }
    nodePtr *trav;
    for (trav = &(L->nodes[parent]); *trav != NULL; trav = &(*trav)->next);
    *trav = temp;
}

void populateTree(ListOfChildren *L) {
    insertTree(L, 1, 0);
    insertTree(L, 2, 0);
    insertTree(L, 3, 1);
    insertTree(L, 4, 1);
    insertTree(L, 5, 1);
    insertTree(L, 6, 2);
    insertTree(L, 7, 2);
    insertTree(L, 8, 5);
    insertTree(L, 9, 5);
}

void preorder(ListOfChildren *L) {
    Stack S;
    initStack(&S);

    printf("PREORDER: ");

    push(&S, L->root);

    while (!isEmpty(&S)) {
        int current = pop(&S);
        printf("[%d]", current);

        nodePtr child = L->nodes[current];
        nodePtr stackReversal[MAX];
        int index = 0;

        while (child != NULL) {
            stackReversal[index++] = child;
            child = child->next;
        }

        for (int i = index - 1; i >= 0; i--) {
            push(&S, stackReversal[i]->data);
        }
    }

    printf("\n");
}

int main(void) {
    ListOfChildren X;

    initLOC(&X);
    populateTree(&X);
    preorder(&X);

    return 0;
}
```