[Python Tutor](https://pythontutor.com/c.html#mode=edit)

### Complete Code
```c
#include <stdio.h>

#define MAX (sizeof(char) * 8)

typedef unsigned char SET;

void init(SET *S);
void displayBitPattern(SET S);
void insert(SET *S, int data);
void deleteElem(SET *S, int data);

int main(void){
    SET A;
    init(&A);
    insert(&A, 0);
    insert(&A, 1);
    insert(&A, 3);
    insert(&A, 2);
    insert(&A, 4);
    insert(&A, 7);
    displayBitPattern(A);
    deleteElem(&A, 2);
    displayBitPattern(A);
    
    return 0;
}

void init(SET *S){
    *S = 0;
}

void insert(SET *S, int data){
    if(data >= 0 && data < sizeof(MAX)){
        *S |= 1 << data;
    }
}

void deleteElem(SET *S, int data){
    if(data >= 0 && data < sizeof(MAX)){
        *S &= ~(1 << data);
    }
}

void displayBitPattern(SET S){
    int mask = 1 << (MAX - 1);
    for(int i = 0; i < MAX; i++, mask >>= 1){
        printf("%d", (S & mask) > 0);
        if (i % 4 == 3 && i != MAX - 1) printf(" ");
    }
    printf("\n");
}
```


