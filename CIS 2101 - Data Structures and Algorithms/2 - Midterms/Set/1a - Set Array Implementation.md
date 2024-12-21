[Python Tutor](https://pythontutor.com/c.html#mode=edit)

### Complete Code
```c
#include <stdio.h>

#define MAX 10

// NOTES
// MAX of A and B will be MAX / 2 which is 5

typedef int object;

typedef struct {
    object set[MAX];
    int size;
} SET;

SET Union(SET A, SET B);
SET Intersection(SET A, SET B);
SET Difference(SET A, SET B);
void printSet(SET S);

int main(void){
    SET A = {{1, 4, 7}, 3};
    SET B = {{6, 7, 3, 9}, 4};
    SET C = Union(A, B);
    printSet(C);
    SET D = Intersection(A, B);
    printSet(D);
    SET E = Difference(A, B);
    printSet(E);
    
    return 0;
}

SET Union(SET A, SET B){
    SET C = A;
    for(int i = 0; i < B.size; i++){
        int j;
        for(j = 0; j < C.size && B.set[i] != C.set[j]; j++);
        if(j == C.size) C.set[C.size++] = B.set[i];
    }
    return C;
}

SET Intersection(SET A, SET B){
    SET C = {{}, 0};
    for(int i = 0; i < A.size; i++){
        int j;
        for(j = 0; j < B.size && A.set[i] != B.set[j]; j++);
        if(j < B.size) C.set[C.size++] = A.set[i];
    }
    return C;
}

SET Difference(SET A, SET B){
    SET C = {{}, 0};
    for(int i = 0; i < A.size; i++){
        int j;
        for(j = 0; j < B.size && A.set[i] != B.set[j]; j++);
        if(j == B.size) C.set[C.size++] = A.set[i];
    }
    return C;
}

void printSet(SET S){
    printf("{ ");
    for(int i; i < S.size; i++){
        printf("%d ", S.set[i]);
    }
    printf("}\n");
}
```