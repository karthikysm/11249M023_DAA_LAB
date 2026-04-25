#include <stdio.h>

// Recursive function
int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n, i;
    int a = 0, b = 1, next;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    // Iterative method
    printf("Fibonacci (Iteration):\n");
    for (i = 0; i < n; i++)
    {
        if (i == 0)
            printf("%d ", a);
        else if (i == 1)
            printf("%d ", b);
        else
        {
            next = a + b;
            printf("%d ", next);
            a = b;
            b = next;
        }
    }

    // Recursive method
    printf("\nFibonacci (Recursion):\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", fib(i));
    }

    return 0;
}
