[Python Tutor](https://pythontutor.com/c.html#mode=edit)

### Diagram
![Directed Graph Diagram](https://raw.githubusercontent.com/Despee2k/NOTES/main/CIS%202101%20-%20Data%20Structures%20and%20Algorithms/Attachments/2_DirectedGraph.png)

### List Diagram
![List Representation](https://raw.githubusercontent.com/Despee2k/NOTES/main/CIS%202101%20-%20Data%20Structures%20and%20Algorithms/Attachments/6_AdjacencyList.png)

### Complete Code
```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct node {
    int vertex;
    struct node *next;
} Edge, *edgePtr;

typedef edgePtr AdjacencyList[MAX];

void initList(AdjacencyList L){
    for(int i = 0; i < MAX; i++){
        L[i] = NULL;
    }
}

void point(AdjacencyList L, int tail, int head){
    edgePtr newEdge = (edgePtr) malloc (sizeof(Edge));
    if(newEdge != NULL){
        newEdge->vertex = head;
        newEdge->next = NULL;
    }
    edgePtr *trav;
    for(trav = &L[tail]; *trav != NULL; trav = &(*trav)->next){}
    *trav = newEdge;
}

void populateList(AdjacencyList L){
    point(L, 0, 1);
    point(L, 0, 3);
    point(L, 0, 4);
    point(L, 1, 2);
    point(L, 2, 0);
    point(L, 2, 4);
    point(L, 3, 2);
    point(L, 3, 4);
}

void displayArcs(AdjacencyList L){
    for(int i = 0; i < MAX; i++){
        edgePtr trav;
        for(trav = L[i]; trav != NULL; trav = trav->next){
            printf("%d -> %d\n", i, trav->vertex);
        }
    }
}

int main(void){
    AdjacencyList X;
    initList(X);
    populateList(X);
    displayArcs(X);
    
    return 0;
}
```