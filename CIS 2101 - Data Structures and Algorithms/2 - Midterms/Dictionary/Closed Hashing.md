###### Definition
```c
#define DELETED '@'
#define EMPTY '*'
#define MAX 10

typedef char closedH[MAX];
```

###### Diagram


###### Functions
1. `Hash()`
2. `initDict()`
3. `displayDict()`
4. `insert()`
5. `deleteElem()`
6. `isMember()`

###### Complete Code
```c
#include <stdio.h>
#include <stdbool.h>

#define DELETED '@'
#define EMPTY '*'
#define MAX 10

typedef char closedH[MAX];

int Hash(char data);
void initDict(closedH A);
void displayDict(closedH A);
void insert(closedH A, char data);
void deleteElem(closedH A, char data);
bool isMember(closedH A, char data);

int main(void){
    closedH A;
    initDict(A);  
    
    insert(A, 'a');  
    insert(A, 'A');  
    insert(A, 'B');  
    insert(A, 'W');  
    
    displayDict(A);  
    printf("%c isMember? %s\n", 'A', (isMember(A, 'A')) ? "TRUE" : "FALSE");  
    deleteElem(A, 'A');   
    printf("%c isMember? %s\n", 'A', (isMember(A, 'A')) ? "TRUE" : "FALSE");  
    displayDict(A);  
    
    return 0;
}

int Hash(char data){
    return data % MAX;    
}

void initDict(closedH A){
    for(int i = 0; i < MAX; i++){
        A[i] = EMPTY;
    }    
}

void displayDict(closedH A){
    printf("==DICTIONARY==\n");
    for(int i = 0; i < MAX; i++){
        if(A[i] != EMPTY && A[i] != DELETED){
            printf("[%d] %c\n", i, A[i]);
        }
    }
    printf("\n");
}

void insert(closedH A, char data){
    int hashVal = Hash(data);
    int i;
    for(i = 0;
        A[hashVal] != EMPTY && A[hashVal] != data && i < MAX;
        i++, hashVal = (hashVal + 1) % MAX);
    if(i < MAX && A[hashVal != data]){
        A[hashVal] = data;
    }
}

void deleteElem(closedH A, char data){
    int hashVal = Hash(data);
    int i;
    for(i = 0;
        A[hashVal] != data && A[hashVal] != EMPTY && i < MAX;
        i++, hashVal = (hashVal + 1) % MAX);
    if(i < MAX){
        A[hashVal] = DELETED;
    }
}

bool isMember(closedH A, char data){
    int hashVal = Hash(data);
    int i;
    for(i = 0;
        A[hashVal] != data && A[hashVal] != EMPTY && i < MAX;
        i++, hashVal = (hashVal + 1) % MAX);
    return (A[hashVal] == data)? true : false;
}
```