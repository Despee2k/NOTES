Variations of each function implemented using version 1 of List Array Implementation.

[Python Tutor](https://pythontutor.com/c.html#mode=edit)

```c
#include <stdio.h>

#define MAX 10

typedef int elemType;

typedef struct {
    elemType elems[MAX];
    int last;
} List, *listPtr;

void initList(listPtr L){
    L->last = -1;
}

void insertLast(listPtr L, int data){
    if(L->last < MAX - 1){
        L->elems[++L->last] = data;
    }    
}

void insertFirst(listPtr L, int data){
    if(L->last < MAX - 1){
        int i;
        for(i = ++L->last; i > 0; i--){
            L->elems[i] = L->elems[i - 1];
        }
        L->elems[i] = data;
    }    
}

void insertSorted(listPtr L, int data){
    if(L->last < MAX - 1){
        int i, j;
        int count = ++L->last;
        for(i = 0; i < count && data > L->elems[i]; i++){}
        for(j = count; j > i; j--){
            L->elems[j] = L->elems[j - 1];
        }
        L->elems[j] = data;
    }    
}

void insertLastUnique(listPtr L, int data){
    if(L->last < MAX - 1){
        int i;
        int count = L->last + 1;
        for(i = 0; i < count && L->elems[i] != data; i++){}
        if (i == count) L->elems[++L->last] = data;
    }
}

void deleteElem(listPtr L, int target){
    if(L->last > -1){
        int i, j;
        int count = L->last + 1;
        for(i = 0; i < count && L->elems[i] != target; i++){}
        
        if(i < count){
            count = L->last--;        
            for(j = i; j < count; j++){
                L->elems[j] = L->elems[j + 1];
            }
        }
    }    
}

void deleteAllOccur(listPtr L, int target){
    if(L->last > -1){
        int count = L->last + 1;
        for(int i = 0; i < count; i++){
            if(L->elems[i] == target){
                for(int j = i; j < count; j++){
                    L->elems[j] = L->elems[j + 1];
                }
                L->last--;
            }
        }
    }
}

void printList(List L){
    int count = L.last + 1;
    for(int i = 0; i < count; i++){
        printf("[%d]", L.elems[i]);
    }
    
    printf("\n");
    printf("Last: %d\n", L.last);
}

int main(void){
    List X;
    initList(&X);
    insertLast(&X, 3);
    insertFirst(&X, 5);
    insertSorted(&X, 4);
    insertSorted(&X, 3);
    insertLastUnique(&X, 3);
    printList(X);
    deleteElem(&X, 1);
    deleteElem(&X, 1);
    deleteAllOccur(&X, 3);
    deleteAllOccur(&X, 3);
    printList(X);
}
```
