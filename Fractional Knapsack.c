#include <stdio.h>

int main()
{
    int n, i, j;
    float weight[20], profit[20], ratio[20];
    float capacity, temp, maxProfit = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights:\n");
    for (i = 0; i < n; i++)
        scanf("%f", &weight[i]);

    printf("Enter profits:\n");
    for (i = 0; i < n; i++)
        scanf("%f", &profit[i]);

    printf("Enter capacity: ");
    scanf("%f", &capacity);

    // Step 1: Calculate ratios
    for (i = 0; i < n; i++)
        ratio[i] = profit[i] / weight[i];

    // Step 2: Sort by ratio (descending)
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (ratio[i] < ratio[j])
            {
                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;

                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;
            }
        }
    }

    // Step 3: Fill knapsack
    for (i = 0; i < n; i++)
    {
        if (weight[i] <= capacity)
        {
            maxProfit += profit[i];
            capacity -= weight[i];
        }
        else
        {
            maxProfit += ratio[i] * capacity;
            break;
        }
    }

    printf("Maximum profit: %.2f\n", maxProfit);

    return 0;
}
