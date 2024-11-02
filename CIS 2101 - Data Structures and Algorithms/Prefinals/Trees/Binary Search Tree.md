###### Definition
```c
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
} Tree, *treePtr;
```

###### Diagram


###### Functions
1. `initTree()` -
2. `insertTree()` -
3. `deleteTree()` -
4. `isMember()` -
5. `inorder()` -
6. `preorder()` -
7. `postorder()` -

###### Complete Code
```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
} Tree, *treePtr;

void initTree(treePtr *root);
void insertTree(treePtr *root, int data);
void deleteTree(treePtr *root, int data);
bool isMember(treePtr root, int data);
void inorder(treePtr root);
void preorder(treePtr root);
void postorder(treePtr root);

int main(void){
    treePtr BT;
    
    initTree(&BT);
    insertTree(&BT, 7);
    insertTree(&BT, 5);
    insertTree(&BT, 4);
    insertTree(&BT, 6);
    deleteTree(&BT, 5);
    int member = 6;
    printf("%d isMember? %s\n", member, (isMember(BT, member)?"TRUE":"FALSE"));
    printf("INORDER:\n");
    inorder(BT);
    printf("\n");
    printf("POSTORDER:\n");
    postorder(BT);
    printf("\n");
    printf("PREORDER\n");
    preorder(BT);
    printf("\n");

    return 0;
}

void initTree(treePtr *root){
    *root = NULL;
}

void insertTree(treePtr *root, int data){
    treePtr newNode = malloc(sizeof(Tree));
    if(newNode != NULL){
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->data = data;
        treePtr *trav;
        for(trav = root; *trav != NULL && (*trav)->data != data;){
            trav = (data < (*trav)->data)? &(*trav)->left : &(*trav)->right;
        }
        if(*trav == NULL){
            *trav = newNode;
        }
    }
}

void deleteTree(treePtr *root, int data){
    treePtr *trav;
    for(trav = root; *trav != NULL && (*trav)->data != data;){
        trav = (data > (*trav)->data)? &(*trav)->right : &(*trav)->left;
    }
    if(*trav != NULL){
    treePtr temp = *trav;
        if((*trav)->left != NULL && (*trav)->right != NULL){
            treePtr *minTrav;
            for(minTrav = &(*trav)->right; (*minTrav)->left != NULL; minTrav = &(*minTrav)->left);
            (*trav)->data = (*minTrav)->data;
            temp = *minTrav;
            *minTrav = temp->right;
        }
        else *trav = (temp->right == NULL)? temp->left : temp->right;
        free(temp);
    }
}

bool isMember(treePtr root, int data){
    treePtr trav;
    for(trav = root; trav != NULL && trav->data != data;){
        trav = (data > trav->data)? trav->right : trav->left;
    }
    return (trav != NULL)? true : false;
}

void inorder(treePtr root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(treePtr root){
    if(root != NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(treePtr root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
```
