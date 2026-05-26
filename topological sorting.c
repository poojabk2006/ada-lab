#include <stdio.h>

int a[10][10], indegree[10], v[10], stack[10];
int n, k = 0, top = -1;

void readadj();
void topological();

int main()
{
    int i;

    printf("======================================\n");
    printf(" Topological Ordering of Vertices\n");
    printf("======================================\n");

    readadj();
    topological();

    if (k == n)
    {
        printf("\nTopological sequence is:\n");

        for (i = 0; i < n; i++)
        {
            printf("%d\t", v[i]);
        }
    }
    else
    {
        printf("\nTopological sequence does not exist");
    }

    return 0;
}

void readadj()
{
    int i, j;

    printf("\nEnter the number of vertices:\n");
    scanf("%d", &n);

    if (n <= 0 || n > 10)
    {
        printf("Enter valid number of vertices\n");
        return;
    }

    printf("\nEnter the adjacency matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

void topological()
{
    int i, j, R;

    for (i = 0; i < n; i++)
    {
        indegree[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[i][j] == 1)
            {
                indegree[j]++;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            stack[++top] = i;
        }
    }

    while (top != -1)
    {
        R = stack[top--];
        v[k++] = R;

        for (i = 0; i < n; i++)
        {
            if (a[R][i] == 1)
            {
                indegree[i]--;

                if (indegree[i] == 0)
                {
                    stack[++top] = i;
                }
            }
        }
    }
}
