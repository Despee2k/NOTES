###### Definition
```c
#define MAX 10  

typedef struct node {  
    int data;  
    struct node *next;    
} List;  
  
typedef List *openH[MAX];
```

###### Diagram


###### Functions
1. `Hash()`
2. `initDict()`
3. `displayDict()`
4. `insertLast()`
5. `deleteElem()`
6. `isMember()`

###### Complete Code
```c
#include <stdio.h>  
#include <stdbool.h>  
#include <stdlib.h>  
  
#define MAX 10  

typedef struct node {  
    int data;  
    struct node *next;    
} List;  
  
typedef List *openH[MAX];  

int Hash(int data);
void initDict(openH A);
void displayDict(openH A);
void insertLast(openH A, int data);
void deleteElem(openH A, int data);
bool isMember(openH A, int data);
  
int main(void) {  
    openH A;  
    initDict(A);  
    
    insertLast(A, 1);  
    insertLast(A, 17);  
    insertLast(A, 21);  
    insertLast(A, 8);  
    
    displayDict(A);  
    printf("%d isMember? %s\n", 17, (isMember(A, 17)) ? "TRUE" : "FALSE");  
    deleteElem(A, 17);   
    printf("%d isMember? %s\n", 17, (isMember(A, 17)) ? "TRUE" : "FALSE");  
    displayDict(A);  
    
    return 0;  
}

int Hash(int data) {  
    return data % MAX;  
}  

void initDict(openH A) {  
    for(int i = 0; i < MAX; i++) {  
        A[i] = NULL;  
    }  
}  

void displayDict(openH A) {
    printf("==DICTIONARY==\n");
    for(int i = 0; i < MAX; i++) {  
        if(A[i] != NULL) {  
            printf("[%d] ", i);  
            List *trav = A[i];  
            for(; trav != NULL; trav = trav->next) {  
                printf("%d->", trav->data);  
            }  
            printf("NULL\n");  
        }  
    }  
}  

void insertLast(openH A, int data) {  
    int hashVal = Hash(data);  
      
    List *newNode = (List *) malloc(sizeof(List));  
    if(newNode != NULL) {  
        newNode->data = data;  
        newNode->next = NULL;  
    }  
    
    List **trav;  
    for(trav = &(A[hashVal]); *trav != NULL; trav = &(*trav)->next);  
    *trav = newNode;  
}  

void deleteElem(openH A, int data) {  
    int hashVal = Hash(data);  
    List **trav;  
    for(trav = &(A[hashVal]); *trav != NULL && (*trav)->data != data; trav = &(*trav)->next);  
    if(*trav != NULL) {  
        List *temp = *trav;  
        *trav = temp->next;  
        free(temp);  
    }  
}  

bool isMember(openH A, int data) {  
    int hashVal = Hash(data);  
    List **trav;  
    for(trav = &(A[hashVal]); *trav != NULL && (*trav)->data != data; trav = &(*trav)->next);  
    return (*trav != NULL) ? true : false;  
}
```


