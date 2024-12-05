

### Complete COde
```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef int elemType;

typedef struct node {
    elemType vertex;
    struct node *next;
} Node, *nodePtr;

typedef Node* adjList[MAX];

void initList(adjList L){
    for(int i = 0; i < MAX; i++){
        L[i] = NULL;
    }
}

void insertList(adjList L, int source, elemType vertex ){
    nodePtr newNode = (nodePtr) malloc (sizeof(Node));
    if(newNode != NULL){
        newNode->vertex = vertex;
        newNode->next = NULL;
    }
    nodePtr *trav;
    for(trav = &(L[source]); *trav != NULL; trav = &(*trav)->next){}
    *trav = newNode;
    
    // Mirror
    nodePtr newerNode = (nodePtr) malloc (sizeof(Node));
    if(newerNode != NULL){
        newerNode->vertex = source;
        newerNode->next = NULL;
    }
    for(trav = &(L[vertex]); *trav != NULL; trav = &(*trav)->next){}
    *trav = newerNode;
}

void populateList(adjList L){
    insertList(L, 0, 1);
    insertList(L, 0, 2);
    insertList(L, 1, 2);
    insertList(L, 2, 3);
    insertList(L, 2, 4);
}

void initVisited(int V[]){
    for(int i = 0; i < MAX; i++){
        V[i] = 0;
    }
}

void DFS(adjList L, int V[],int vertex){
    nodePtr trav = L[vertex];
    
    V[vertex] = 1;
    printf("[%d]", vertex);
    
    while(trav != NULL){
        int connectedVertex = trav->vertex;
        if(V[connectedVertex] != 1){
            DFS(L, V, connectedVertex);
        }
        trav = trav->next;
    }
}

int main(void){
    adjList X;
    initList(X);
    populateList(X);
    
    int Visited[MAX];
    initVisited(Visited);
    
    DFS(X, Visited, 1);
    printf("\n");
    
    return 0;
}
```