###### Array Definition
```c
typedef struct {
	int *elemPtr;
	int count;
	int arrSize;
} List;
```

###### Diagram
![Array Imp 3|300](../Attachments/ArrImp3.png)

###### Functions
1. `initList()` - initializes the list to be empty.
2. `insertLast()` - inserts an element at the last position in the list
3. `deleteElem()` - deletes a given element if it exists in the list

###### Complete Code
```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 3

typedef struct {
	int *elemPtr;
	int count;
	int arrSize;
} List;

void initList(List *A);
void insertLast(List *A, int val);
void deleteElem(List *A, int val);
void printer(List A);

int main(void){
  List L;
  initList(&L);
  insertLast(&L, 1);
  insertLast(&L, 2);
  insertLast(&L, 3);
  printer(L);
  insertLast(&L, 4);
  printer(L);
  deleteElem(&L, 4);
  printer(L);
  return 0;
}

void printer(List A){
	int i;
  for(i = 0; i < A.count; i++) printf("%d. [%d]\n", i+1, A.elemPtr[i]);
  printf("Arr size: %d\nArr count: %d\n", A.arrSize, A.count);
  printf("\n");
}

void initList(List *A){
  A->elemPtr = malloc (MAX * sizeof(int));
  A->count = 0;
  A->arrSize = MAX;
}

void insertLast(List *A, int val){
  if(A->count < MAX){
    A->elemPtr[A->count++] = val;
  }
  else {
    A->elemPtr = realloc(A->elemPtr, (MAX * 2) * sizeof(int));
    A->elemPtr[A->count++] = val;
    A->arrSize *= 2;
  }
}

void deleteElem(List *A, int val){
  int i;
  for(i = 0; i < A->count && A->elemPtr[i] != val; i++);
  if(i < A->count){
    A->count--;
    for(int j = i; j < A->count; j++){
      A->elemPtr[j] = A->elemPtr[j+1];
    }
  }
  if(A->count <= (A->arrSize / 2)){
    A->elemPtr = realloc(A->elemPtr, (MAX / 2) * sizeof(int));
    A->arrSize /= 2;
  }
}
```

###### Complete Code with Position Functions
```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 3

typedef struct {
	int *elemPtr;
	int count;
	int arrSize;
} List;

//Position functions
typedef int Position;
void initList(List *A);
void insertWithPos(List *A, Position pos, int val);
void deleteWithPos(List *A, Position pos);
Position locate(List * A, int val);
int retrieve(List *A, Position pos);
void makeNull(List *A);
void printer(List A);

int main(void){
  List L;
  initList(&L);
  insertWithPos(&L, 1, 1);
  insertWithPos(&L, 2, 2);
  insertWithPos(&L, 3, 3);
  printer(L);
  insertWithPos(&L, 4, 4);
  printer(L);
  printf("Retrive: %d\n", retrieve(&L, 1));
  
  return 0;
}

void printer(List A){
	int i;
  for(i = 0; i < A.count; i++) printf("%d. [%d]\n", i+1, A.elemPtr[i]);
  printf("Arr size: %d\nArr count: %d\n", A.arrSize, A.count);
  printf("\n");
}

void initList(List *A){
  A->elemPtr = malloc (MAX * sizeof(int));
  A->count = 0;
  A->arrSize = MAX;
}

void insertWithPos(List *A, Position pos, int val){
  if(A->count < A->arrSize){
    A->elemPtr[--pos] = val;
    A->count++;
  }
  else {
    A->elemPtr = realloc(A->elemPtr, (A->arrSize * 2) * sizeof(int));
    A->elemPtr[--pos] = val;
    A->count++;
    A->arrSize *= 2;
  }
}

void deleteWithPos(List *A, Position pos){
  if(A->elemPtr[--pos]){
    A->elemPtr[pos] = -1;
  }
}

Position locate(List * A, int val){
  int i;
  for(i = 0; i < A->count && A->elemPtr[i] != val; i++);
  if(i == A->count){
    i = -1;
  }
  return i;
}

int retrieve(List *A, Position pos){
  if(pos <= A->count){
    return A->elemPtr[pos-1];
  }
}
void makeNull(List *A){
  A->count = 0;
}
```