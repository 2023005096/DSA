#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int data;
    struct Node* next;
};

void initializeStack(struct Node** top) {
    *top = NULL;
}

int isStackEmpty(struct Node* top) {
    return top == NULL;
}

void push(struct Node** top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

void pop(struct Node** top, int* value) {
    if (isStackEmpty(*top)) {
        printf("Stack is empty!\n");
        *value = -1;  
        return;
    }
    struct Node* temp = *top;
    *value = temp->data;
    *top = (*top)->next;  
    free(temp);
}

void dfs(int graph[][MAX], int n, int start) {
    int visited[MAX] = {0}; 
    struct Node* stack = NULL;

    push(&stack, start); 

    while (!isStackEmpty(stack)) {
        int node;
        pop(&stack, &node);  

        if (!visited[node]) {
            printf("%d ", node);
            visited[node] = 1;
        }

        for (int i = n - 1; i >= 0; i--) {
            if (graph[node][i] && !visited[i]) {
                push(&stack, i);
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
