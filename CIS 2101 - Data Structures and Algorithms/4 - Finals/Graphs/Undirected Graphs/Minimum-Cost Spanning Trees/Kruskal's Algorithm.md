Sadly Python Tutor can't visualize this because it's too long.

### Diagram
![Weighted Undirected Graph](https://raw.githubusercontent.com/Despee2k/NOTES/main/CIS%202101%20-%20Data%20Structures%20and%20Algorithms/Attachments/weighted_undirected_graph.png)

### Complete Code
```c
#include<stdio.h>

#define MAX 6
#define MAX_EDGES 99
#define X 999       // No connection

typedef int Matrix[MAX][MAX];

typedef struct {
    int tail;
    int head;
    int cost;
} Edge;

typedef struct {
  Edge edges[MAX_EDGES];
  int count;
} edgeList;

typedef struct {
  Edge edges[MAX_EDGES];
  int count;
  int totalCost;
} MST;

typedef struct {
    int parent;
    int rank;
} Subset;

edgeList createEdgeList(Matrix M){
    edgeList E;
    E.count = 0;
    
    int i, j;
    int x, y;
    for(i = 0; i < MAX; i++){
        for(j = i + 1; j < MAX; j++){
            if(M[i][j] != X){
                
                // Insert Sorted
                for(x = 0; x < E.count && M[i][j] > E.edges[x].cost; x++){}
                for(y = E.count; y > x; y--){
                    E.edges[y] = E.edges[y - 1];
                }
                E.edges[y] = (Edge){i, j, M[i][j]};
                E.count++;
            }
        }
    }
    
    return E;
}

void displayEdgeList(edgeList E){
    for(int i = 0; i < E.count; i++){
        printf("%d - %d : %d\n", E.edges[i].tail, E.edges[i].head, E.edges[i].cost);
    }
}

int find(Subset *S, int index){
    // Path Compression
    if(S[index].parent != index){
        S[index].parent = find(S, S[index].parent);
    }
    
    return S[index].parent;
}

void combineComponent(Subset S[], int rootX, int rootY){
    if(S[rootX].rank > S[rootY].rank){
        S[rootY].parent = rootX;
    } else if (S[rootY].rank > S[rootX].rank){
        S[rootX].parent = rootY;
    } else {
        S[rootY].parent = rootX;
        S[rootX].rank++;
    }
}

MST MST_Kruskal(Matrix M){
    edgeList E = createEdgeList(M);
    
    Subset S[MAX];
    for(int i = 0; i < MAX; i++){
        S[i].rank = 0;
        S[i].parent = i;
    }
    
    MST MK;
    MK.count = 0;
    MK.totalCost = 0;
    
    for(int i = 0; i < E.count; i++){
        int tail = E.edges[i].tail;
        int head = E.edges[i].head;
        int rootTail = find(S, tail);
        int rootHead = find(S, head);
        
        if(rootTail != rootHead){
            combineComponent(S, rootTail, rootHead);
            MK.edges[MK.count++] = E.edges[i];
            MK.totalCost += E.edges[i].cost;
        }
    }
    
    return MK;
}

void displayMST(MST MK){
    for(int i = 0; i < MK.count; i++){
        printf("%d - %d : %d\n", MK.edges[i].tail, MK.edges[i].head, MK.edges[i].cost);
    }
    printf("COST: %d\n", MK.totalCost);
}

int main(void){
    Matrix M = {
        {0, 1, 5, 4, 6, 5},
        {1, 0, 5, X, X, 5},
        {5, 5, 0, 2, X, X},
        {4, X, 2, 0, 1, X},
        {6, X, X, 1, 0, 3},
        {5, 6, X, X, 3, 0}
    };
    
    MST MK = MST_Kruskal(M);
    displayMST(MK);
    
    return 0;
}
```