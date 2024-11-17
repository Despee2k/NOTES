```c
#include <stdio.h>

#define MAX 10

typedef struct {
    int data[MAX];
    int lastIdx;
} Heap;

void initHeap(Heap *H);
void heapSort(Heap *H);
int deleteMax(Heap *H);
void heapify(Heap *H, int subRoot);
void buildMaxHeap(Heap *H);
void printer(Heap H);

int main(void) {
    Heap hp;
    initHeap(&hp);
    hp.data[0] = 5;
    hp.data[1] = 6;
    hp.data[2] = 11;
    hp.data[3] = 7;
    hp.data[4] = 4;
    hp.lastIdx = 4;
    printer(hp);
    heapSort(&hp);
    printer(hp);

    return 0;
}

void initHeap(Heap *H) {
    H->lastIdx = -1;
}

void buildMaxHeap(Heap *H) {
    for (int i = (H->lastIdx - 1) / 2; i >= 0; i--) {
        heapify(H, i);
    }
}

void heapSort(Heap *H) {
    buildMaxHeap(H);
    int origLastIdx = H->lastIdx;
    while (H->lastIdx > 0) {
        H->data[H->lastIdx] = deleteMax(H);
    }
    H->lastIdx = origLastIdx;
}

int deleteMax(Heap *H) {
    int temp = H->data[0];
    H->data[0] = H->data[(H->lastIdx)--];
    if (H->lastIdx > 0) {
        heapify(H, 0);
    }

    return temp;
}

void heapify(Heap *H, int subRoot) {
    int trav, idx;
    for (trav = subRoot; (2 * trav + 1) <= H->lastIdx; trav = idx) {
        idx = (H->data[2 * trav + 1] > H->data[trav]) ? (2 * trav + 1) : trav;
        if (2 * trav + 2 <= H->lastIdx && H->data[2 * trav + 2] > H->data[idx]) {
            idx = 2 * trav + 2;
        }
        if (idx != trav) {
            int temp = H->data[idx];
            H->data[idx] = H->data[trav];
            H->data[trav] = temp;
        } else {
            break;
        }
    }
}

void printer(Heap H) {
    for (int i = 0; i <= H.lastIdx; i++) {
        printf("[%d]", H.data[i]);
    }
    printf("\n");
}

```