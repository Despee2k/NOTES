###### Definition
```c
#define MAX 10

typedef struct{
    int arr[MAX];
    int lastIdx;
} POT;
```

###### Diagram


###### Functions
1. `initPOT()` - initializes the partially ordered tree to te empty
2. `getParent()` - get the parent index of the child index, this works for both left and right child because of integer division
3. `insertPOT()` - insert element into the tree while satisfying POT properties

###### Complete Code
```c
/////////////////////////////
// MIN HEAP IMPLEMENTATION //
/////////////////////////////

#include <stdio.h>

#define MAX 10

typedef struct {
    int arr[MAX];
    int lastIdx;
} POT;

void initPOT(POT *p);
int getParent(int idx);
void insertPOT(POT *p, int data);


int main(void){
    POT p;
    initPOT(&p);
    insertPOT(&p, 5);
    insertPOT(&p, 3);
    insertPOT(&p, 6);
    insertPOT(&p, 1);

    return 0;
}

void initPOT(POT *p){
    p->lastIdx = 0;
}

int getParent(int idx){
    return (idx - 1) / 2;
}

void insertPOT(POT *p, int data){
    if(p->lastIdx < MAX){
        p->arr[p->lastIdx++] = data;

        for(int i = p->lastIdx - 1; i > 0 && data < p->arr[getParent(i)]; i = getParent(i)){
            int temp = p->arr[getParent(i)];
            p->arr[getParent(i)] = p->arr[i];
            p->arr[i] = temp;
        }
    }
}
```