#include <stdio.h>
#include <limits.h>

int main()
{
    int n, i, j, src, u, v, min;
    int cost[10][10], dist[10], visited[10] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0 && i != j)
                cost[i][j] = INT_MAX;
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &src);

    // Initialize distances
    for (i = 0; i < n; i++)
    {
        dist[i] = cost[src][i];
    }

    dist[src] = 0;
    visited[src] = 1;

    // Dijkstra Algorithm
    for (i = 0; i < n - 1; i++)
    {
        min = INT_MAX;

        // Find minimum distance vertex
        for (j = 0; j < n; j++)
        {
            if (!visited[j] && dist[j] < min)
            {
                min = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        // Update distances
        for (v = 0; v < n; v++)
        {
            if (!visited[v] && cost[u][v] != INT_MAX &&
                dist[u] + cost[u][v] < dist[v])
            {
                dist[v] = dist[u] + cost[u][v];
            }
        }
    }

    // Output
    printf("Shortest distances from vertex %d:\n", src);
    for (i = 0; i < n; i++)
    {
        printf("To %d = %d\n", i, dist[i]);
    }

    return 0;
}
