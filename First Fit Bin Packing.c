#include <stdio.h>

int main()
{
    int n, i, j;
    float weight[20], capacity;
    float bin[20] = {0}; // stores filled capacity
    int bins_used = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights of items:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &weight[i]);
    }

    printf("Enter bin capacity: ");
    scanf("%f", &capacity);

    // First Fit Algorithm
    for (i = 0; i < n; i++)
    {
        int placed = 0;

        for (j = 0; j < bins_used; j++)
        {
            if (bin[j] + weight[i] <= capacity)
            {
                bin[j] += weight[i];
                printf("Item %.2f placed in Bin %d\n", weight[i], j + 1);
                placed = 1;
                break;
            }
        }

        if (!placed)
        {
            bin[bins_used] = weight[i];
            bins_used++;
            printf("Item %.2f placed in Bin %d\n", weight[i], bins_used);
        }
    }

    printf("Total bins used: %d\n", bins_used);

    return 0;
}
