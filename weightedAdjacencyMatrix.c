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

int main(void){
    DAM XXX;
    initMatrix(&XXX);
    
    point(&XXX, (data){'A', 'B', 55});
    point(&XXX, (data){'A', 'H', 10});
    point(&XXX, (data){'B', 'F', 20});
    point(&XXX, (data){'C', 'A', 75});
    point(&XXX, (data){'D', 'E', 100});
    point(&XXX, (data){'D', 'H', 15});
    point(&XXX, (data){'E', 'B', 5});
    point(&XXX, (data){'E', 'H', 60});
    point(&XXX, (data){'F', 'C', 80});
    point(&XXX, (data){'G', 'A', 115});
    point(&XXX, (data){'G', 'C', 45});

    printf("WORKS!\n");
    return 0;
}
