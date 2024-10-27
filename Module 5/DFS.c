#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int visited[MAX];
int adj[MAX][MAX];
int stack[MAX];
int top = -1;

void push(int v) {
    stack[++top] = v;
}

int pop() {
    return stack[top--];
}

void DFS(int n, int start) {
    int u, w;
    
    for (u = 0; u < n; u++) {
        visited[u] = 0;
    }

    push(start);
    
    while (top != -1) {
        u = pop();
        
        if (!visited[u]) {
            printf("%d ", u);
            visited[u] = 1;
        }
        
        for (w = 0; w < n; w++) {
            if (adj[u][w] == 1 && !visited[w]) {
                push(w);
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

    printf("DFS Traversal: ");
    DFS(n, start);
    
    return 0;
}
