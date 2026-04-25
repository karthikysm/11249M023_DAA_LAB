#include <stdio.h>
#include <limits.h>

int n, cost[10][10];
int visited[10];
int minCost = INT_MAX;

// Function to find minimum
int min(int a, int b)
{
    return (a < b) ? a : b;
}

// Recursive function
void tsp(int city, int count, int currentCost)
{
    int i;

    // If all cities visited, return to start
    if (count == n && cost[city][0] > 0)
    {
        minCost = min(minCost, currentCost + cost[city][0]);
        return;
    }

    for (i = 0; i < n; i++)
    {
        if (!visited[i] && cost[city][i] > 0)
        {
            visited[i] = 1;
            tsp(i, count + 1, currentCost + cost[city][i]);
            visited[i] = 0; // backtrack
        }
    }
}

int main()
{
    int i, j;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    // Initialize visited
    for (i = 0; i < n; i++)
        visited[i] = 0;

    visited[0] = 1; // start from city 0

    tsp(0, 1, 0);

    printf("Minimum travelling cost: %d\n", minCost);

    return 0;
}
