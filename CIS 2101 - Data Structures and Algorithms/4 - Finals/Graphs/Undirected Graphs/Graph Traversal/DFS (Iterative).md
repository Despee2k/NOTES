[Python Tutor](https://pythontutor.com/c.html#mode=edit)

### Complete Code
```c
#include <stdio.h>

#define MAX 5

typedef int Matrix[MAX][MAX];

typedef struct {
    int items[MAX];
    int top;
} Stack;

// Stack Helper Functions
void initStack(Stack *S){
    S->top = -1;
}

void push(Stack *S, int data){
    if(S->top < MAX - 1){
        S->items[++S->top] = data;
    }
}

int pop(Stack *S){
    if(S->top > -1)
        return S->items[S->top--];
}

void DFS(Matrix M, int start){
    int Visited[MAX];
    for(int i = 0; i < MAX; i++){
        Visited[i] = 0;
    }
    
    Stack S;
    initStack(&S);
    push(&S, start);
    
    while(S.top > -1){
        int vertex = pop(&S);
        if(Visited[vertex] != 1){
            printf("[%d]", vertex);
            Visited[vertex] = 1;
        }
        
        for(int j = MAX - 1; j >= 0; j--){              // We start at MAX - 1 
            if(M[vertex][j] != 0 && Visited[j] != 1){   // to make the output
                push(&S, j);                            // ascending since
            }                                           // stack is FILO
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
    DFS(X, 1);
    
    return 0;
}
```