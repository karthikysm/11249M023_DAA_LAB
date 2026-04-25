#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

// Binary Search Function
int binarysearch(int arr[], int key, int low, int high)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main()
{
    int arr[SIZE];
    clock_t start, end;
    int key, result;
    double time_taken;

    srand(time(NULL));

    // Generate sorted random array
    arr[0] = rand() % 10;
    for (int i = 1; i < SIZE; i++)
    {
        arr[i] = arr[i - 1] + (rand() % 10);
    }

    // Print array
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d,", arr[i]);
    }

    printf("\nEnter the key value to search:\n");
    scanf("%d", &key);

    start = clock();

    result = binarysearch(arr, key, 0, SIZE - 1);

    end = clock();

    if (result != -1)
    {
        printf("\nThe element was found at %d position", result);
    }
    else
    {
        printf("\nIt was not found");
    }

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nThe time taken for search %f seconds:\n", time_taken);

    return 0;
}
