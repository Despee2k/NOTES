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

int main(void){
    DAM XXX;
    initMatrix(&XXX);
    
    point(&XXX, (data){'A', 'B'});
    point(&XXX, (data){'A', 'H'});
    point(&XXX, (data){'B', 'F'});
    point(&XXX, (data){'C', 'A'});
    point(&XXX, (data){'D', 'E'});
    point(&XXX, (data){'D', 'H'});
    point(&XXX, (data){'E', 'B'});
    point(&XXX, (data){'E', 'H'});
    point(&XXX, (data){'F', 'C'});
    point(&XXX, (data){'G', 'A'});
    point(&XXX, (data){'G', 'C'});

    printf("WORKS!\n");
    return 0;
}
