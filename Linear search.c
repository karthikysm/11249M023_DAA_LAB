#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10000
int linearsearch(int arr[], int key)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int arr[SIZE];
    clock_t start, end;
    int key;
    double time_taken;
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % 10000;
        printf("%d,", arr[i]);
    }
    printf("\nEnter the key value to search:\n");
    scanf("%d", &key);
    start = clock();
    int result = linearsearch(arr, key);
    end = clock();
    if (result != -1)
    {
        printf("\nThe element was found at %d position", result);
    }
    else
    {
        printf("\nit was not found");
    }
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nThe time taken for search %f seconds:\n", time_taken);
    return 0;
}
