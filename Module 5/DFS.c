#include <stdio.h>
#include <stdlib.h>

#define MAX 100 
typedef struct
{
    int top;
    int items[MAX];
} Stack;

void initStack(Stack *s)
{
    s->top = -1;
}

int isStackEmpty(Stack *s)
{
    return s->top == -1;
}

void push(Stack *s, int value)
{
    if (s->top < MAX - 1)
        s->items[++(s->top)] = value;
}

int pop(Stack *s)
{
    if (!isStackEmpty(s))
        return s->items[(s->top)--];
    return -1;
}

void dfs(int graph[][MAX], int n, int start)
{
    int visited[MAX] = {0}; 
    Stack stack;
    initStack(&stack);

    push(&stack, start);

    while (!isStackEmpty(&stack))
    {
        int node = pop(&stack);

        if (!visited[node])
        {
            printf("%d ", node);
            visited[node] = 1;
        }

        for (int i = n - 1; i >= 0; i--)
        { 
            if (graph[node][i] && !visited[i])
            {
                push(&stack, i);
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

    printf("DFS Traversal:\n");
    dfs(graph, n, 0); 
    return 0;
}
