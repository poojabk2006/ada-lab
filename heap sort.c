#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count = 0;

void heapify(int n, int H[])
{
    for (int i = n / 2; i >= 1; i--)
    {
        int k = i;
        int v = H[k];
        int heap = 0;

        while (!heap && 2 * k <= n)
        {
            int j = 2 * k;

            if (j < n)
            {
                count++;
                if (H[j] < H[j + 1])
                {
                    j = j + 1;
                }
            }

            count++;

            if (v >= H[j])
            {
                heap = 1;
            }
            else
            {
                H[k] = H[j];
                k = j;
            }
        }

        H[k] = v;
    }
}

void heap_sort_custom(int H[], int n)
{
    heapify(n, H);

    for (int i = n; i >= 2; i--)
    {
        int temp = H[1];
        H[1] = H[i];
        H[i] = temp;

        heapify(i - 1, H);
    }
}

int main()
{
    int i, n;
    int H[1025];

    srand(time(0));

    printf("Enter number of elements (max 1024): ");
    scanf("%d", &n);

    if (n < 1 || n > 1024)
    {
        printf("Invalid size.\n");
        return 1;
    }

    printf("Enter elements:\n");

    for (i = 1; i <= n; i++)
    {
        scanf("%d", &H[i]);
    }

    heap_sort_custom(H, n);

    printf("\nSorted elements are:\n");

    for (i = 1; i <= n; i++)
    {
        printf("%d ", H[i]);
    }

    printf("\n");

    int c1, c2, c3;
    int a1[1025], b[1025], c[1025];

    printf("\n-----------------------------------------");
    printf("\nSize\tASC\tDESC\tRAND");
    printf("\n-----------------------------------------\n");

    for (int size = 16; size <= 512; size *= 2)
    {
        for (int j = 1; j <= size; j++)
        {
            a1[j] = j;
            b[j] = size - j + 1;
            c[j] = rand() % size;
        }

        count = 0;
        heap_sort_custom(a1, size);
        c1 = count;

        count = 0;
        heap_sort_custom(b, size);
        c2 = count;

        count = 0;
        heap_sort_custom(c, size);
        c3 = count;

        printf("%d\t%d\t%d\t%d\n", size, c1, c2, c3);
    }

    return 0;
}
