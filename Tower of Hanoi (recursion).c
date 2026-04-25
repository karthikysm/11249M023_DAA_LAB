#include <stdio.h>
#include <string.h>

// Function to swap characters
void swap(char *x, char *y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
}

// Recursive function to generate permutations
void permute(char str[], int l, int r)
{
    int i;

    if (l == r)
    {
        printf("%s\n", str);
    }
    else
    {
        for (i = l; i <= r; i++)
        {
            swap(&str[l], &str[i]); // Fix one character
            permute(str, l + 1, r); // Recur for remaining
            swap(&str[l], &str[i]); // Backtrack
        }
    }
}

int main()
{
    char str[20];

    printf("Enter a string: ");
    scanf("%s", str);

    printf("Permutations are:\n");
    permute(str, 0, strlen(str) - 1);

    return 0;
}
