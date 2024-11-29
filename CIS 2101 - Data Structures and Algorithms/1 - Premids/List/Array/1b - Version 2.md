[Python Tutor](https://pythontutor.com/c.html#mode=edit)

### Diagram
![ALT](https://raw.githubusercontent.com/Despee2k/NOTES/main/CIS%202101%20-%20Data%20Structures%20and%20Algorithms/Attachments/INSERTNAME)

### Complete Code
```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef int elemType;

typedef struct {
  elemType elems[MAX];
  int last;
} List, *listPtr;

void initList(listPtr *L) {
  *L = (listPtr)malloc(sizeof(List));
  (*L)->last = -1;
}

void insertList(listPtr *L, elemType data) {
  if ((*L)->last < MAX - 1) {
    (*L)->elems[++(*L)->last] = data;
  }
}

elemType retriveElem(listPtr L, int position) {
  return (L->last <= position && position > 0) ? L->elems[position - 1] : -1;   // -1 meaning invalid
}

void deleteElem(listPtr *L, elemType target) {
  if ((*L)->last > -1) {
    int count = (*L)->last + 1;
    int i, j;
    for (i = 0; i < count && (*L)->elems[i] != target; i++) {}
    if (i < count) {
      count = (*L)->last--;
      for (j = i; j < count; j++) {
        (*L)->elems[j] = (*L)->elems[j + 1];
      }
    }
  }
}

void makeNull(listPtr *L) {
  (*L)->last = -1;
}

void printList(listPtr L) {
  int count = L->last + 1;
  for (int i = 0; i < count; i++) {
    printf("[%d]", L->elems[i]);
  }
  printf("\n");
}

int main(void) {
  listPtr X;
  initList(&X);
  insertList(&X, 1);
  insertList(&X, 4);
  insertList(&X, 2);
  printList(X);
  deleteElem(&X, 2);
  deleteElem(&X, 1);
  printList(X);

  free(X);
  return 0;
}
```