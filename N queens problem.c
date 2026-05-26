#include <stdio.h>
#include <stdlib.h>

int b[20], count = 0;

int place(int row, int col)
{
    int i;

    for (i = 1; i < row; i++)
    {
        if (b[i] == col || abs(b[i] - col) == abs(row - i))
            return 0;
    }

    return 1;
}

void dis(int n)
{
    int i, j;

    printf("\nSolution number: %d\n", ++count);

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (b[i] == j)
                printf("\tQ");
            else
                printf("\t*");
        }

        printf("\n");
    }

    printf("\n");
}

void queen(int row, int n)
{
    int col;

    for (col = 1; col <= n; col++)
    {
        if (place(row, col))
        {
            b[row] = col;

            if (row == n)
                dis(n);
            else
                queen(row + 1, n);
        }
    }
}

int main()
{
    int n;

    printf("========================================\n");
    printf("\t\tN - Queens Problem\n");
    printf("========================================\n");

    printf("\nEnter the number of queens: ");
    scanf("%d", &n);

    if (n > 0 && n < 20)
    {
        queen(1, n);
        printf("\nTotal number of solutions: %d\n", count);
    }
    else
    {
        printf("Enter a valid number of queens\n");
    }

    return 0;
}
