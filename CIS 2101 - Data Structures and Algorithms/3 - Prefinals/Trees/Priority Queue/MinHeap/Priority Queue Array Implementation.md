###### Definition
```c
#define MAX 10

typedef struct {
    int arr[MAX];
    int last;
} PriorityQueue;
```

###### Diagram


###### Functions
1. `initPQ`
2. `insertPQ`
3. `deleteMin`

###### Complete Code
```c
#include <stdio.h>

#define MAX 10

typedef struct {
    int arr[MAX];
    int last;
} PriorityQueue;

// NOTES
// left child calc = 2i + 1
// right child calc = 2i + 2
// parent calc = (i - 1) / 2

void initPQ(PriorityQueue *pq){
    pq->last = -1;
}

void insertPQ(PriorityQueue *A, int data){
    if(A->last < MAX){
        A->arr[++A->last] = data;
        int i = A->last;
        int parent = (i - 1) / 2;
        
        while(A->arr[i] < A->arr[parent]){
            int temp = A->arr[i];
            A->arr[i] = A->arr[parent];
            A->arr[parent] = temp;
            
            i = parent;
            parent = (i - 1) / 2;
        }
    }
}

// deleteMin would change if used in heapsort

int deleteMin(PriorityQueue *A){
    int min = -1;
    
    if(A->last > -1){
        min = A->arr[0];
        A->arr[0] = A->arr[A->last--];
        int i = 0;
        int j;

        while(i < A->last){
            if(A->arr[2 * i + 1] < A->arr[2 * i + 2] || 2 * i + 1 == A->last){
                j = 2 * i + 1;                          // left child
            } else {
                j = 2 * i + 2;                          // left child
            }  
            
            if(j <= A->last && A->arr[i] > A->arr[j]){
                int temp = A->arr[i];
                A->arr[i] = A->arr[j];
                A->arr[j] = temp;
                
                i = j;
            } else i = A->last;
        }
    }
    
    return min;
}


int main(void){
    PriorityQueue X;
    
    initPQ(&X);
    insertPQ(&X, 5);
    insertPQ(&X, 2);
    insertPQ(&X, 6);
    insertPQ(&X, 4);
    insertPQ(&X, 1);
    
    printf("MIN: %d\n", deleteMin(&X));
    printf("MIN: %d\n", deleteMin(&X));
    printf("MIN: %d\n", deleteMin(&X));
    printf("MIN: %d\n", deleteMin(&X));
    printf("MIN: %d\n", deleteMin(&X));
    printf("MIN: %d\n", deleteMin(&X));
    
    return 0;
}  
```
