#include <stdio.h>
#include <stdlib.h>
int toh(int n, char S, char A, char D)
{
    int count = 1;
    if (n == 1)
    {
        printf("Disc %d moved' from %c to %c", n, S, D);
        return 1;
    }
    count += toh(n - 1, S, D, A);
    printf("\nDisc %d moved from %c to %c\n", n, S, D);
    count += toh(n - 1, A, S, D);
    return count;
}
void main()
{
    int n;
    printf("\nEnter the no. of discs: ");
    scanf("%d", &n);
    printf("\n");
    char S, A, D;
    int steps = toh(n, 'S', 'A', 'D');
    printf("\n\nNo. of Steps: %d\n", steps);
}