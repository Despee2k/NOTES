#include <stdio.h>
#include <limits.h>

#define MAX 8
#define INF INT_MAX

typedef struct {
    char head;
    char tail;
    int weight;
} data;

typedef struct {
    int adjMatrix[MAX][MAX];
    int edgeCount;
} DAM;

void initMatrix(DAM *A){
    for(int i =0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            A->adjMatrix[i][j] = (i == j) ? 0 : INF;
        }
    }
    A->edgeCount = 0;
}

void point(DAM *A, data d){
    A->adjMatrix[d.tail - 'A'][d.head - 'A'] = d.weight;
    A->edgeCount++;
}

void populateMatrix(DAM *A){
    point(A, (data){'A', 'B', 55});
    point(A, (data){'A', 'H', 10});
    point(A, (data){'B', 'F', 20});
    point(A, (data){'C', 'A', 75});
    point(A, (data){'D', 'E', 100});
    point(A, (data){'D', 'H', 15});
    point(A, (data){'E', 'B', 5});
    point(A, (data){'E', 'H', 60});
    point(A, (data){'F', 'C', 80});
    point(A, (data){'G', 'A', 115});
    point(A, (data){'G', 'C', 45});
}

int main(void){
    DAM X;
    initMatrix(&X);
    populateMatrix(&X);

    printf("WORKS!\n");
    return 0;
}