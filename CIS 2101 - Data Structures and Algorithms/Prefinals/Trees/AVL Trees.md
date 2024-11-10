###### Definition
```c
typedef struct node {
    int data;
    struct node *right;
    struct node *left;
} AVL;
```

###### Diagram


###### Functions


###### Complete Code
```c
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *right;
    struct node *left;
} *AVL;

void initAVL(AVL *a);
void insertAVL(AVL *a, int data); // with balancing already
int getHeight(AVL a, int *h, char dir);

int main(void){
    AVL x;
    initAVL(&x);
    insertAVL(&x, 1);
    insertAVL(&x, 2);
    insertAVL(&x, 3);
}

void initAVL(AVL *a){
    *a = NULL;
}

void insertAVL(AVL *a, int data){
    AVL temp = malloc(sizeof(struct node));
    if(temp != NULL){
        temp->right = NULL;
        temp->left = NULL;
        temp->data = data;
    }
    
    AVL *trav;
    for(trav = a; (*trav) != NULL; trav = &(*trav)->right);
    (*trav) = temp;
    
    int hr = 0, hl = 0;
    getHeight((*a)->right, &hr, 'r');
    getHeight((*a)->left, &hl, 'l');
    
    int bf = hr - hl;
    if(bf == 2){
        trav = a;
        AVL trav2 = *a;
        trav = &(*trav)->right;
        (*trav)->left = *a;
        *a = *trav;
        trav2->right = trav2->left;
    }
}

int getHeight(AVL a, int *h, char dir){
    if(a != NULL){
        if(dir == 'r'){
            getHeight(a->right, h, dir);
        } else {
            getHeight(a->left, h, dir);
        }
        (*h)++;
    }
}
```
