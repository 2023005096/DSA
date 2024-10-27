#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE); 
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int isStackEmpty(struct Node* top) {
    return top == NULL;
}

// Push a value onto the stack
struct Node* push(struct Node* top, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = top;
    return newNode;  
}

struct Node* pop(struct Node* top, int* value) {
    if (isStackEmpty(top)) {
        printf("Stack is empty!\n");
        *value = -1;  
        return top;   
    }
    struct Node* temp = top;
    *value = temp->data;
    top = top->next;  
    free(temp);
    return top; 
}

void dfs(int graph[][MAX], int n, int start) {
    int visited[MAX] = {0}; 
    struct Node* stack = NULL;

    stack = push(stack, start); 

    while (!isStackEmpty(stack)) {
        int node;
        stack = pop(stack, &node);  

        if (node == -1) 
            continue;

        if (!visited[node]) {
            printf("%d ", node);
            visited[node] = 1;
        }

        for (int i = n - 1; i >= 0; i--) {
            if (graph[node][i] && !visited[i]) {
                stack = push(stack, i);  
            }
        }
    }
}


int main() {
    int n = 6;  

    int graph[MAX][MAX] = {
        {0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0}};

    printf("DFS Traversal:\n");
    dfs(graph, n, 0);

    return 0;
}
