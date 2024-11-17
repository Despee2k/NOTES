###### Definition
```c
typedef struct {
    int data[MAX];
    int lastIdx;
} Heap;
```

###### Diagram


###### Functions


###### Complete Code
```c
#include <stdio.h>

#define MAX 10

typedef struct {
    int data[MAX];
    int lastIdx;
} Heap;

void heapify(Heap *heap, int n, int i);
void buildHeap(Heap *heap);
void heapSort(Heap *heap);
void swap(int *a, int *b);
void printer(Heap *heap);

// Main function
int main() {
    Heap heap = {{5, 6, 11, 7, 4}, 4};
    printf("Original array:\n");
    printer(&heap);

    heapSort(&heap);

    printf("\nSorted array:\n");
    printer(&heap);

    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(Heap *heap, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap->data[left] > heap->data[largest])
        largest = left;

    if (right < n && heap->data[right] > heap->data[largest])
        largest = right;

    if (largest != i) {
        swap(&heap->data[i], &heap->data[largest]);
        heapify(heap, n, largest);
    }
}

void buildHeap(Heap *heap) {
    int n = heap->lastIdx + 1;

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(heap, n, i);
    }
}

void heapSort(Heap *heap) {
    int n = heap->lastIdx + 1;

    buildHeap(heap);

    for (int i = n - 1; i > 0; i--) {
        swap(&heap->data[0], &heap->data[i]);
        heapify(heap, i, 0);
    }
}

void printer(Heap *heap) {
    for (int i = 0; i <= heap->lastIdx; i++) {
        printf("%d ", heap->data[i]);
    }
    printf("\n");
}

```
