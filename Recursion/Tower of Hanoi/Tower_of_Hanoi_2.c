#include <stdio.h>
void toh(int n, char S, char A, char D)
{
    if (n == 0)
    {
        return;
    }
    toh(n - 1, S, D, A);
    printf("%d Disc moved from %c to %c\n", n, S, D);
    toh(n - 1, A, S, D);
}
int main()
{
    int n;
    printf("\nEnter the no. of Discs: ");
    scanf("%d", &n);
    char A, S, D;
    toh(n, 'S', 'A', 'D');
}