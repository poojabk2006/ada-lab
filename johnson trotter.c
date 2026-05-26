#include <stdio.h>

int perm[10];
int dir[10];

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printPermutation(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", perm[i]);
    }
    printf("\n");
}

int getMobile(int n)
{
    int mobile = 0;
    int mobileIndex = -1;

    for (int i = 0; i < n; i++)
    {
        if (dir[perm[i]] == -1 && i != 0)
        {
            if (perm[i] > perm[i - 1] && perm[i] > mobile)
            {
                mobile = perm[i];
                mobileIndex = i;
            }
        }

        if (dir[perm[i]] == 1 && i != n - 1)
        {
            if (perm[i] > perm[i + 1] && perm[i] > mobile)
            {
                mobile = perm[i];
                mobileIndex = i;
            }
        }
    }

    return mobileIndex;
}

void johnsonTrotter(int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        perm[i] = i + 1;
        dir[i + 1] = -1;
    }

    printPermutation(n);

    while (1)
    {
        int mobileIndex = getMobile(n);

        if (mobileIndex == -1)
        {
            break;
        }

        int mobile = perm[mobileIndex];

        if (dir[mobile] == -1)
        {
            swap(&perm[mobileIndex], &perm[mobileIndex - 1]);
            mobileIndex--;
        }
        else
        {
            swap(&perm[mobileIndex], &perm[mobileIndex + 1]);
            mobileIndex++;
        }

        for (i = 0; i < n; i++)
        {
            if (perm[i] > mobile)
            {
                dir[perm[i]] *= -1;
            }
        }

        printPermutation(n);
    }
}

int main()
{
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    johnsonTrotter(n);

    return 0;
}
