#include <stdio.h>
void towerofhanoi(int n, char source, char auxiliary, char destination)
{
    if (n == 1)
    {
        printf("\nmove disk 1 from %c to %c", source, destination);
        return;
    }

    // move n-1 disks from source to destination
    towerofhanoi(n - 1, source, destination, auxiliary);
    // move nth disk from source to destination
    printf("\nMove %d disk from %c to %c", n, source, destination);
    // Move n-1 disks from auxiliary to destination
    towerofhanoi(n - 1, auxiliary, source, destination);
}
int main()
{
    int n;
    printf("Enter no of disks:");
    scanf("%d", &n);
    towerofhanoi(n, 'A', 'B', 'C');
    return 0;
}
