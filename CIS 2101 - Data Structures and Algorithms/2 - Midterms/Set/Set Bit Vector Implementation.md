###### Definition
```c
typedef int SET[MAX];
```

###### Diagram


###### Functions
1. `Union`
2. `Intersection`
3. `Difference`

###### Complete Code
```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef int SET[MAX];

SET* Union(SET A, SET B);
SET* Intersection(SET A, SET B);
SET* Difference(SET A, SET B);
void printer(SET S);

int main(void){
    SET A = {1, 0, 1, 0, 1};
    SET B = {0, 1, 0, 0, 0};
    
    SET *C = Union(A, B);
    SET *D = Intersection(A, B);
    printer(*C);
    printer(*D);
    SET *E = Difference(B, A);
    printer(*E);
    
    return 0;
}

SET* Union(SET A, SET B){
    SET *C = (SET *) malloc (sizeof(SET));
    for(int i = 0; i < MAX; i++){
        (*C)[i] = A[i] | B[i];
    }
    return C;
}

SET* Intersection(SET A, SET B){
    SET *C = (SET *) malloc (sizeof(SET));
    for(int i = 0; i < MAX; i++){
        (*C)[i] = A[i] & B[i];
        
    }
    return C;
}

SET* Difference(SET A, SET B){
    SET *C = (SET *) malloc (sizeof(SET));
    for(int i = 0; i < MAX; i++){
        (*C)[i] = A[i] & (~B[i]);
    }
    return C;
}

void printer(SET S){
    printf("{ ");
    for(int i = 0; i < MAX; i++){
        if(S[i] == 1){
            printf("%d ", i);
        }
    }
    printf("}\n");
}
```


