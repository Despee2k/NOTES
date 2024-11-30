[Python Tutor](https://pythontutor.com/c.html#mode=edit)

### Diagram
![ALT](https://raw.githubusercontent.com/Despee2k/NOTES/main/CIS%202101%20-%20Data%20Structures%20and%20Algorithms/Attachments/INSERTNAME)

### Complete Code
```c
#include <stdio.h>
#include <stdlib.h>

typedef int elemType;

typedef struct node {
    elemType data;
    struct node *next;
} Node, *nodePtr;

void initList(nodePtr *L){
    *L = NULL;
}

void insertElem(nodePtr *L, elemType data){
    nodePtr temp = (nodePtr) malloc (sizeof(Node));
    if(temp != NULL){
        temp->next = NULL;
        temp->data = data;
    }
    nodePtr *trav;
    for(trav = L; *trav != NULL; trav = &(*trav)->next){}
    *trav = temp;
}

void deleteELem(nodePtr *L, elemType target){
    nodePtr *trav;
    for(trav = L; *trav != NULL && (*trav)->data != target; trav = &(*trav)->next){}
    if(*trav != NULL){
        nodePtr temp = *trav;
        *trav = temp->next;
        free(temp);
    }
}

void makeNull(nodePtr *L) {
    nodePtr trav;
    for (trav = *L, temp; trav != NULL; trav = temp){
        temp = trav->next;
        free(trav);
    }
    *L = NULL;
}

void printList(nodePtr L){
    nodePtr trav;
    for(trav = L; trav != NULL; trav = trav->next){
        printf("%d", trav->data);
        if(trav->next != NULL) printf(" -> ");
    }
    printf("\n");
}

int main(void){
    nodePtr X;
    initList(&X);
    
    insertElem(&X, 1);
    insertElem(&X, 2);
    insertElem(&X, 3);
    printList(X);
    deleteELem(&X, 1);
    printList(X);
    
    void makeNull(&X);
    
    return 0;
}
```