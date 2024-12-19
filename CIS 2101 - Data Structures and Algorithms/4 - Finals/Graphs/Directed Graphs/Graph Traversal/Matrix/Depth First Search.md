[Python Tutor](https://pythontutor.com/c.html#mode=edit)

### Diagram
![ALT](https://raw.githubusercontent.com/Despee2k/NOTES/main/CIS%202101%20-%20Data%20Structures%20and%20Algorithms/Attachments/INSERTNAME)

### Complete Code
```c
#include <stdio.h>

#define MAX 5
#define DIAGONAL '\\'
#define EMPTY '*'

typedef char Matrix[MAX][MAX];

typedef int Visited[MAX];

// NOTES
// 1 - Visited
// 0 - NOT visited

void initMatrix(Matrix M){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            M[i][j] = (i == j) ? DIAGONAL : EMPTY;
        }
    }
}

void initVisited(Visited V){
    for(int i = 0; i < MAX; i++){
        V[i] = 0;
    }
}

void point(Matrix M, char tail, char head){
    M[tail - 'A'][head - 'A'] = head;
}

void populateMatrix(Matrix M){
    point(M, 'A', 'B');
    point(M, 'B', 'C');
    point(M, 'B', 'D');
    point(M, 'C', 'A');
    point(M, 'D', 'A');
    point(M, 'D', 'C');
    point(M, 'E', 'B');
    point(M, 'E', 'D');
}

void DFS(Matrix M, Visited V,char start){
    V[start - 'A'] = 1;
    printf("%c -> ", start);
    for(int i = 0; i < MAX; i++){
        if(M[start - 'A'][i] != EMPTY && M[start - 'A'][i] != DIAGONAL && V[i] == 0){
            DFS(M, V, i + 'A');
        }
    }
    for(int i = 0; i < MAX; i++){       // For any vertices that can no longer be accessed
        if(V[i] == 0) DFS(M, V, i + 'A');
    }
}

void initDFS(Matrix M, char start){
    Visited V;
    initVisited(V);
    
    DFS(M, V, start);
    printf("NULL\n");
}

int main(void){
    Matrix X;
    initMatrix(X);
    populateMatrix(X);
    
    initDFS(X, 'A');
    initDFS(X, 'E');
    
    return 0;
}
```