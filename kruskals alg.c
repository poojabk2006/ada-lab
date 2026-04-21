#include <stdio.h>

int parent[20];

int find(int m)
{
    while(parent[m] != 0)
        m = parent[m];
    return m;
}

void union_ij(int i, int j)
{
    parent[i] = j;
}

void kruskal(int a[10][10], int n)
{
    int u, v, min, k = 0, i, j, sum = 0;

    while(k < n - 1)
    {
        min = 999;

        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if(a[i][j] < min && i != j)
                {
                    min = a[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        i = find(u);
        j = find(v);

        if(i != j)
        {
            union_ij(i, j);
            printf("(%d,%d) = %d\n", u, v, min);
            sum += min;
            k++;
        }

        a[u][v] = a[v][u] = 999;
    }

    printf("\nMinimum cost spanning tree = %d\n", sum);
}

int main()
{
    int a[10][10], n, i, j;

    printf("=======================================\n");
    printf(" Find minimum cost spanning tree using Kruskal Algorithm \n");
    printf("=======================================\n");

    while(1)
    {
        printf("\nEnter number of vertices: ");
        scanf("%d", &n);

        if(n > 0)
            break;

        printf("Invalid input. Try again.\n");
    }


    for(i = 1; i <= n; i++)
        parent[i] = 0;

    printf("\nEnter cost adjacency matrix:\n");
    printf("(0 for self loops, 999 for no edge)\n");

    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);

    kruskal(a, n);

    return 0;
}
