#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

void initializeQueue(struct Queue* q) {
    q->front = q->rear = NULL;
}

int isQueueEmpty(struct Queue* q) {
    return q->front == NULL;
}

void enqueue(struct Queue* q, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear) {
        q->rear->next = newNode;
    } else {
        q->front = newNode; 
    }
    q->rear = newNode; 
}

void dequeue(struct Queue* q, int* value) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty!\n");
        *value = -1;
        return;
    }
    struct Node* temp = q->front;
    *value = temp->data;
    q->front = q->front->next;

    if (!q->front) {
        q->rear = NULL; 
    }
    free(temp);
}

void bfs(int graph[][MAX], int n, int start) {
    int visited[MAX] = {0};  
    struct Queue queue;     
    initializeQueue(&queue);      

    enqueue(&queue, start); 
    visited[start] = 1;   

    while (!isQueueEmpty(&queue)) {
        int node;
        dequeue(&queue, &node); 
        printf("%d ", node);

        for (int i = 0; i < n; i++) {
            if (graph[node][i] && !visited[i]) {
                enqueue(&queue, i);
                visited[i] = 1; 
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

    printf("BFS Traversal:\n");
    bfs(graph, n, 0);  

    return 0;
}
