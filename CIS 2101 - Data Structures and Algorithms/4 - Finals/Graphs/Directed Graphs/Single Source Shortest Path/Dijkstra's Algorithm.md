Sadly Python Tutor can't visualize this because it has too many steps, refer to [[DIJKSTRA PSEUDOCODE]] for the process.

### Diagram
![Weighted Directed Graph](https://raw.githubusercontent.com/Despee2k/NOTES/main/CIS%202101%20-%20Data%20Structures%20and%20Algorithms/Attachments/3_WeightedDirectedGraph.png)

This Dijkstra's Algorithm was implemented with the use of [[1 - SET CONCEPTS|SETS]] and SET FUNCTIONS.

### Complete Code
```c
#include <stdio.h>
//#include <limits.h>       // don't use this for Dijkstra

#define MAX 5
//#define INF INT_MAX       // this fucked me up LMAO
#define INF 1000

typedef struct {
    int items[MAX];
    int count;
} SET;

// Directed Graph 
typedef int adjMatrix[MAX][MAX];

void initMatrix(adjMatrix M){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            M[i][j] = (i == j)? 0 : INF;
        }
    }
}

void populateMatrix(adjMatrix M){
    M[0][1] = 10; 
    M[0][3] = 30; 
    M[0][4] = 100;
    M[1][2] = 50; 
    M[2][0] = 20;
    M[2][4] = 10;
    M[3][2] = 20; 
    M[3][4] = 60;
}

void initSet(SET *S){
    S->count = 0;
}

void insertSet(SET *S, int data){
    if(S->count < MAX){
        S->items[S->count++] = data;
    }
}

void populateAllVertices(SET *V){
    for(int i = 0; i < MAX; i++){
        insertSet(V, i);
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

int getMin(int a, int b){
    return (a > b)? b : a;
}

void DijkstraAlgo(adjMatrix M, SET *d, SET V){
    // 0 to every other vertex
    SET S;
    initSet(&S);
    
    insertSet(&S, 0);
    insertSet(d, 0);       // distance from 0 to itself is 0
    
    for(int i = 1; i < MAX; i++){
        insertSet(d, M[0][i]);
    }
    
    int count = MAX - 1;
    for(int j = 1; j < count; j++){
        int min = INF;
        int w;
        SET diff = difference(V, S);
        for(int i = 0; i < diff.count; i++){
            if(d->items[diff.items[i]] < min){
                min = d->items[diff.items[i]];
                w = diff.items[i];
            }
        }
        insertSet(&S, w);
        
        diff = difference(V, S);
        for(int i = 0; i < diff.count; i++){
            int v = diff.items[i];
            d->items[v] = getMin(d->items[v], (d->items[w] + M[w][v]));
        }
    }
}

void displayDijkstra(SET d){
    printf("DIJKSTRA: \n");
    for(int i = 0; i < MAX; i++){
        printf("[%d]", d.items[i]);
    }
    printf("\n");
}

int main(void){
    adjMatrix X;
    initMatrix(X);
    populateMatrix(X);
    
    SET dijkstra;
    initSet(&dijkstra);
    
    SET allVertices;
    initSet(&allVertices);
    populateAllVertices(&allVertices);
    
    DijkstraAlgo(X, &dijkstra, allVertices);
    displayDijkstra(dijkstra);
    
    return 0;
}
```