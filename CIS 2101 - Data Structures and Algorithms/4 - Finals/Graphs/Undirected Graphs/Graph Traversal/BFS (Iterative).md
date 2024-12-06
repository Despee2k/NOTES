[Python Tutor](https://pythontutor.com/c.html#mode=edit)

### Complete Code
```c
#include <stdio.h>
#include <stdlib.h>

// Circular Array Implementation of Queue

#define MAX 5           // Max number of elements
#define SIZE MAX + 1    // Size of our circular queue

typedef int elemType;

typedef elemType Matrix[MAX][MAX];

typedef struct {
    int items[SIZE];
    int front;
    int rear;
} Queue, *queuePtr;

void initQueue(queuePtr Q){
    Q->front = 0;
    Q->rear = MAX;
}

void enqueue(queuePtr Q, elemType data){
    if((Q->rear + 2) % (SIZE) != Q->front){
        Q->rear = (Q->rear + 1) % (SIZE);
        Q->items[Q->rear] = data;
    }
}

int dequeue(queuePtr Q){
    int val = -1;
    if((Q->rear + 1) % (SIZE) != Q->front){
        val = Q->items[Q->front];
        Q->front = (Q->front + 1) % (SIZE);
    } else printf("Queue is EMPTY!\n");
    return val;
}

void initVisited(int V[]){
    for(int i = 0; i < MAX; i++){
        V[i] = 0;
    }
}

void BFS(Matrix M, int start){
    int Visited[MAX];
    initVisited(Visited);
    
    Queue Q;
    initQueue(&Q);
    
    enqueue(&Q, start);
    Visited[start] = 1;
    
    while((Q.rear + 1) % (SIZE) != Q.front){
        int vertex = dequeue(&Q);
        if(vertex != -1){
            printf("[%d]", vertex);
        }
        
        for(int i = 0; i < MAX; i++){
            if(M[vertex][i] != 0 && Visited[i] != 1){
                enqueue(&Q, i);
                Visited[i] = 1;
            }
        }
    }
}

int main(void){
    Matrix X = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}
    };
    BFS(X, 1);
    
    return 0;
}
```