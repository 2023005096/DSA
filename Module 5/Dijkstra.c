#include <stdio.h>
#include <limits.h>

#define MAX 100    
#define INF INT_MAX 

int minDistance(int dist[], int visited[], int n)
{
    int min = INF, min_index;

    for (int v = 0; v < n; v++)
    {
        if (!visited[v] && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int graph[MAX][MAX], int n, int start)
{
    int dist[MAX];   
    int visited[MAX];

    for (int i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[start] = 0; 

    for (int count = 0; count < n - 1; count++)
    {
        int u = minDistance(dist, visited, n); 
        visited[u] = 1;                      

        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Node \t Distance from Source\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

int main()
{
    int n = 5; 

    int graph[MAX][MAX] = {
        {0, 10, 0, 0, 5},
        {0, 0, 1, 0, 2},
        {0, 0, 0, 4, 0},
        {7, 0, 6, 0, 0},
        {0, 3, 9, 2, 0}};

    int start = 0; 
    printf("Dijkstra's Algorithm:\n");
    dijkstra(graph, n, start);

    return 0;
}
