###### Definition
```c
#define MAX 5

typedef struct {
  int data;
  int next;
} Node;

typedef struct {
  Node nodes[MAX];
  int avail;
} VirtualHeap;
```

###### Diagram


###### Functions


###### Complete Code
```c
#include <stdio.h>
#include <stdbool.h>

#define MAX 5

typedef struct {
  int data;
  int next;
} Node;

typedef struct {
  Node nodes[MAX];
  int avail;
} VirtualHeap;

// "Points" to the first node of the list
typedef int List;

//Cursor Based Functions
void initVH(VirtualHeap* VH);
int allocSpace(VirtualHeap* VH);
void deallocSpace(VirtualHeap* VH, int index);

// List Functions
void initList(List *L);
void insertFirst(List *L, VirtualHeap* VH, int data);
void insertLast(List *L, VirtualHeap* VH, int data);
void deleteElem(List *L, VirtualHeap* VH, int data);
bool member(List L, VirtualHeap VH, int data);
int locate(List L, VirtualHeap H, int data);
void printer(List L, VirtualHeap VH);

int main(void){
  VirtualHeap VH;
  List L;
  
  initVH(&VH);
  initList(&L);
  insertLast(&L, &VH, 2);
  insertFirst(&L, &VH, 1);
  insertFirst(&L, &VH, 8);
  insertLast(&L, &VH, 7);
  insertLast(&L, &VH, 9);
  insertFirst(&L, &VH, 5);
  
  printer(L, VH);
  
  return 0;
}

void initVH(VirtualHeap* VH){
  int i;
  for(i = 0; i < MAX; i++){
    VH->nodes[i].next = i-1;
  }
  VH->avail = i-1;
}

int allocSpace(VirtualHeap* VH){
  int avail = VH->avail;
  if(VH->avail != -1){
    VH->avail = VH->nodes[avail].next;
  }
  return avail;
}

void deallocSpace(VirtualHeap* VH, int index){
  if(index >= 0 && index < MAX){
    VH->nodes[index].next = VH->avail;
    VH->avail = index;
  }
}

void initList(List* L){
  // L is set to -1 because 0 is a valid address in the VirtualHeap
  *L = -1;
}

void insertFirst(List* L, VirtualHeap* VH, int data){
  int avail = allocSpace(VH);
  if(avail != -1){
    VH->nodes[avail].data = data;
    VH->nodes[avail].next = *L;
    *L = avail;
  }
  else printf("FULL! Cannot insert %d\n", data);
}

void insertLast(List* L, VirtualHeap* VH, int data){
  int avail = allocSpace(VH);
  if(avail != -1){
    List *trav;
    for(trav = L; *trav != -1; trav = &(VH->nodes[*trav].next));
    VH->nodes[avail].data = data;
    VH->nodes[avail].next = -1;
    *trav = avail;
  }
  else printf("FULL! Cannot insert %d\n", data);
}

void deleteElem(List* L, VirtualHeap* VH, int data){
  int* trav;
  for(trav = L ; 
      *trav != -1 && VH->nodes[*trav].data != data ; 
      trav = &(VH->nodes[*trav].next));
  if(*trav != -1){
    int temp = *trav;
    *trav = VH->nodes[temp].next;
    deallocSpace(VH, temp);
  }
}

bool member(List L, VirtualHeap VH, int data){
  int trav;
  for(trav = L ;
      trav != -1 && VH.nodes[trav].data != data ;
      trav = VH.nodes[trav].next);
  return(trav != -1)? true : false;
}

int locate(List L, VirtualHeap VH, int data){
  int trav;
  for(trav = L ;
      trav != -1 && VH.nodes[trav].data != data ;
      trav = VH.nodes[trav].next);
  return trav;
}

void printer(List L, VirtualHeap VH){
  int trav;
  for(trav = L; trav != -1; trav = VH.nodes[trav].next){
    printf("%d->", VH.nodes[trav].data);
  }
  printf("NULL\n");
}
```


