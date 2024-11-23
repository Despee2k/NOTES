#include <stdio.h>

#define MAX 8

typedef struct {
    char head;
    char tail;
} data;

typedef struct {
    int adjMatrix[MAX][MAX];
    int edgeCount;
} DAM;

void initMatrix(DAM *A){
    for(int i =0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            A->adjMatrix[i][j] = 0;
        }
    }
    A->edgeCount = 0;
}

void point(DAM *A, data d){
    A->adjMatrix[d.tail - 'A'][d.head - 'A'] = 1;
    A->edgeCount++;
}

void populateMatrix(DAM *A){
    point(A, (data){'A', 'B'});
    point(A, (data){'A', 'H'});
    point(A, (data){'B', 'F'});
    point(A, (data){'C', 'A'});
    point(A, (data){'D', 'E'});
    point(A, (data){'D', 'H'});
    point(A, (data){'E', 'B'});
    point(A, (data){'E', 'H'});
    point(A, (data){'F', 'C'});
    point(A, (data){'G', 'A'});
    point(A, (data){'G', 'C'});
}

int main(void){
    DAM X;
    initMatrix(&X);
    populateMatrix(&X);

    printf("WORKS!\n");
    return 0;
}