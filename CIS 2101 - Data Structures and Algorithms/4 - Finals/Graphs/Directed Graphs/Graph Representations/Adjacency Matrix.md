[Python Tutor](https://pythontutor.com/c.html#mode=edit)

### Diagram
![Directed Graph Diagram](https://raw.githubusercontent.com/Despee2k/NOTES/main/CIS%202101%20-%20Data%20Structures%20and%20Algorithms/Attachments/2_DirectedGraph.png)

### Matrix Diagram
![Matrix Representation](https://raw.githubusercontent.com/Despee2k/NOTES/main/CIS%202101%20-%20Data%20Structures%20and%20Algorithms/Attachments/5_AdjacencyMatrix.png)

### Complete Code
```c
#include <stdio.h>

#define MAX 5

// NOTES
// 1 - there exists a directed edge from row vertex to column vertex
// 0 - no such edge exists

typedef int AdjacencyMatrix[MAX][MAX];

void initMatrix(AdjacencyMatrix M){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            M[i][j] = 0;
        }
    }
}

void point(AdjacencyMatrix M, int i, int j){
    if(i >= 0 && i < MAX && j >= 0 && j < MAX){
        M[i][j] = 1;
    }
}

void populateMatrix(AdjacencyMatrix M){
    point(M, 0, 1);
    point(M, 0, 3);
    point(M, 0, 4);
    point(M, 1, 2);
    point(M, 2, 0);
    point(M, 2, 4);
    point(M, 3, 2);
    point(M, 3, 4);
}

void displayMatrix(AdjacencyMatrix M){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            printf("[%d]", M[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void displayArcs(AdjacencyMatrix M){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            if(M[i][j] == 1){
                printf("%d -> %d\n", i, j);
            }
        }
    }
}

int main(void){
    AdjacencyMatrix X;
    initMatrix(X);
    populateMatrix(X);
    
    displayMatrix(X);
    displayArcs(X);
    
    return 0;
}
```