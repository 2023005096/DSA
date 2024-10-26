#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    int front, rear;
    int items[MAX];
} Queue;

void initQueue(Queue *q)
{
    q->front = q->rear = -1;
}

int isQueueEmpty(Queue *q)
{
    return q->front == -1;
}

void enqueue(Queue *q, int value)
{
    if (q->rear < MAX - 1)
    {
        if (q->front == -1)
            q->front = 0;
        q->items[++(q->rear)] = value;
    }
}

int dequeue(Queue *q)
{
    if (!isQueueEmpty(q))
    {
        int value = q->items[q->front];
        if (q->front == q->rear)
            q->front = q->rear = -1;
        else
            q->front++;
        return value;
    }
    return -1;
}

void bfs(int graph[][MAX], int n, int start)
{
    int visited[MAX] = {0};
    Queue queue;
    initQueue(&queue);

    enqueue(&queue, start);
    visited[start] = 1;

    while (!isQueueEmpty(&queue))
    {
        int node = dequeue(&queue);
        printf("%d ", node);

        for (int i = 0; i < n; i++)
        { 
            if (graph[node][i] && !visited[i])
            {
                enqueue(&queue, i);
                visited[i] = 1;
            }
        }
    }
}

int main()
{
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
