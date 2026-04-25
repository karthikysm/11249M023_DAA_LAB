#include <stdio.h>

int main()
{
    int n, m, i, j;
    int edges[20][2];
    int visited[20] = {0};

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    printf("Enter edges (u v):\n");
    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }

    printf("Vertex Cover:\n");

    for (i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        if (!visited[u] && !visited[v])
        {
            printf("%d %d ", u, v);

            visited[u] = 1;
            visited[v] = 1;
        }
    }

    return 0;
}
