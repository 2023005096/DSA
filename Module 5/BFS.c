#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int visited[MAX];
int adj[MAX][MAX];
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int v) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = v;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

void BFS(int n, int start) {
    int u, w;
    
    for (u = 0; u < n; u++) {
        visited[u] = 0;
    }

    enqueue(start);
    visited[start] = 1;
    
    while (front <= rear) {
        u = dequeue();
        printf("%d ", u);
        
        for (w = 0; w < n; w++) {
            if (adj[u][w] == 1 && !visited[w]) {
                enqueue(w);
                visited[w] = 1;
            }
        }
    }
}

int main() {
    int n = 5;
    int start = 0;

    int edges[5][5] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 0},
        {1, 1, 0, 0, 1},
        {0, 1, 0, 1, 0}
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = edges[i][j];
        }
    }

    printf("BFS Traversal: ");
    BFS(n, start);
    
    return 0;
}
