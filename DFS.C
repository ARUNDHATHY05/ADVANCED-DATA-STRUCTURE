#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct Stack {
    int top;
    unsigned int capacity;
    int* array;
};

struct Stack* createStack(unsigned int capacity);
int isFull(struct Stack* stack);
int isEmpty(struct Stack* stack);
void push(struct Stack* stack, int value);
int pop(struct Stack* stack);
void DFS(int graph[][SIZE], int startVertex);

int main() {
    int n, i, j, start;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int graph[n][n];

    printf("Enter the adjacency matrix: \n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    DFS(graph, start);
    return 0;
}

struct Stack* createStack(unsigned int capacity) {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    return stack;
}

int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, int value) {
    if(isFull(stack)) {
        return;
    }
    stack->array[++stack->top] = value;
}

int pop(struct Stack* stack) {
    if(isEmpty(stack)) {
        return -1;
    }
    return stack->array[stack->top--];
}

void DFS(int graph[][SIZE], int startVertex) {
    struct Stack* stack = createStack(SIZE);
    push(stack, startVertex);

    while(!isEmpty(stack)) {
        int vertex = pop(stack);
        if(graph[vertex][vertex] == 1) {
            printf("%d ", vertex);
            graph[vertex][vertex] = 0;
        }

        for(int i = 0; i < SIZE; i++) {
            if(graph[vertex][i] == 1) {
                push(stack, i);
                graph[vertex][i] = 0;
            }
        }
    }

    printf("\n");
}
