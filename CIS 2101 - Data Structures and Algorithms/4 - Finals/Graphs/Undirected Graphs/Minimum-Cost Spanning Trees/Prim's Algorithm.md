Sadly Python Tutor can't visualize this because it has too many steps, refer to [[PRIM'S PSEUDOCODE]] for the process.

### Diagram
![ALT](https://raw.githubusercontent.com/Despee2k/NOTES/main/CIS%202101%20-%20Data%20Structures%20and%20Algorithms/Attachments/NAME)

This Prim's Algorithm was implemented with the use of [[1 - SET CONCEPTS|SETS]] and SET FUNCTIONS.

### Complete Code
```c
#include <stdio.h>

#define MAX 6
#define INF 999

typedef struct {
    int items[MAX];
    int count;
} SET;

typedef int Matrix[MAX][MAX];

typedef struct {
    Matrix mp;
    int cost;
} Prims;

void initMatrix(Matrix M){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            M[i][j] = (i == j) ? 0 : INF;
        }
    }
}

void initPrims(Prims *P){
    P->cost = 0;
    initMatrix(P->mp);
}

void initSet(SET *S){
    S->count = 0;
}

void populateAllVertices(SET *V){
    for(int i = 0; i < MAX; i++){
        V->items[V->count++] = i;
    }
}

void insertSet(SET *S, int data){
    if(S->count < MAX){
        S->items[S->count++] = data;
    }
}

SET difference(SET A, SET B){
    SET C = {{}, 0};
    for(int i = 0; i < A.count; i++){
        int j;
        for(j = 0; j < B.count && A.items[i] != B.items[j]; j++){}
        
        if(j == B.count) insertSet(&C, A.items[i]);
    }
    
    return C;
}

void point(Matrix M, int tail, int head, int weight){
    M[tail][head] = weight;
    M[head][tail] = weight;
}

void populateMatrix(Matrix M){
    point(M, 0, 1, 1);
    point(M, 0, 2, 5);
    point(M, 0, 3, 4);
    point(M, 0, 4, 6);
    point(M, 0, 5, 5);
    point(M, 1, 2, 5);
    point(M, 1, 5, 6);
    point(M, 2, 3, 2);
    point(M, 3, 4, 1);
    point(M, 4, 5, 3);
}

void PrimsAlgo(Matrix M, Prims *P, SET V, int start){
    SET U;
    initSet(&U);
    insertSet(&U, start);
    
    SET diff;
    initSet(&diff);
    
    while(U.count < MAX){
        int min = INF;
        int minIndex1;
        int minIndex2;
        
        diff = difference(V, U);
        
        for(int i = 0; i < U.count; i++){
            for(int j = 0; j < diff.count; j++){
                if(M[U.items[i]][diff.items[j]] < min){
                    min = M[U.items[i]][diff.items[j]];
                    minIndex1 = U.items[i];
                    minIndex2 = diff.items[j];
                }
            }
        }
        
        insertSet(&U, minIndex2);
        P->cost += min;
        P->mp[minIndex1][minIndex2] = min;
        P->mp[minIndex2][minIndex1] = min;
    }
}

void displayPrimsMatrix(const Prims P) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            printf("[%4d]", P.mp[i][j]);
            if (j < MAX - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    printf("COST: %d\n", P.cost);
}

int main(void){
    Matrix X;
    initMatrix(X);
    populateMatrix(X);
    
    SET allVertices;
    initSet(&allVertices);
    populateAllVertices(&allVertices);
    
    Prims Y;
    initPrims(&Y);
    
    PrimsAlgo(X, &Y, allVertices, 0);
    displayPrimsMatrix(Y);
    
    
    return 0;
}
```