[Python Tutor](https://pythontutor.com/c.html#mode=edit)

### Diagram
![ALT](https://raw.githubusercontent.com/Despee2k/NOTES/main/CIS%202101%20-%20Data%20Structures%20and%20Algorithms/Attachments/INSERTNAME)

###### Complete Code
```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
  int *elemPtr;
  int count;
  int arrSize;
} List, *listPtr;

void initList(listPtr *L) {
  *L = (listPtr)malloc(sizeof(List));
  (*L)->elemPtr = malloc(MAX * sizeof(int));
  (*L)->count = 0;
  (*L)->arrSize = MAX;
}

void insertList(listPtr *L, int val) {
  if ((*L)->count < (*L)->arrSize) {
    (*L)->elemPtr[(*L)->count++] = val;
  } else {
    (*L)->elemPtr = realloc((*L)->elemPtr, ((*L)->arrSize * 2) * sizeof(int));
    (*L)->elemPtr[(*L)->count++] = val;
    (*L)->arrSize *= 2;
  }
}

void deleteElem(listPtr *L, int val) {
  int i;
  for (i = 0; i < (*L)->count && (*L)->elemPtr[i] != val; i++);
  if (i < (*L)->count) {
    (*L)->count--;
    for (int j = i; j < (*L)->count; j++) {
      (*L)->elemPtr[j] = (*L)->elemPtr[j + 1];
    }
  }
  if ((*L)->count <= ((*L)->arrSize / 2) && (*L)->arrSize > MAX) {
    (*L)->elemPtr = realloc((*L)->elemPtr, ((*L)->arrSize / 2) * sizeof(int));
    (*L)->arrSize /= 2;
  }
}

int retriveElem(listPtr L, int position) {
  return (position > 0 && position <= (*L)->count) ? L->elemPtr[position - 1] : -1; // -1 meaning invalid
}

void makeNull(listPtr *L) {
  free((*L)->elemPtr);
  (*L)->elemPtr = malloc(MAX * sizeof(int));
  (*L)->count = 0;
  (*L)->arrSize = MAX;
}

void printList(listPtr L) {
  for (int i = 0; i < L->count; i++) {
    printf("%d. [%d]\n", i + 1, L->elemPtr[i]);
  }
  printf("Arr size: %d\nArr count: %d\n", L->arrSize, L->count);
  printf("\n");
}

int main(void) {
  listPtr X;

  initList(&X);
  insertList(&X, 1);
  insertList(&X, 2);
  insertList(&X, 3);
  printList(X);
  insertList(&X, 4);
  printList(X);
  deleteElem(&X, 4);
  printList(X);

  int retrieved = retriveElem(&X, 2);
  printf("Retrieved element at position 2: %d\n", retrieved);

  makeNull(&X);
  printList(X);

  free(X->elemPtr);
  free(X);
  return 0;
}
```