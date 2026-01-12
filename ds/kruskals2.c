#include <stdio.h>
#include <limits.h>

int parent[10];

/* Find root */
int find(int v)
{
    while (parent[v] != v)
        v = parent[v];
    return v;
}

/* Union sets */
void unionSet(int u, int v)
{
    parent[u] = v;
}

int main()
{
    int v, i, j;
    int cost[10][10];

    printf("Enter number of vertices: ");
    scanf("%d", &v);

    printf("Enter adjacency matrix (upper triangle only):\n");
    for (i = 0; i < v; i++)
    {
        for (j = i; j < v; j++)
        {
            if (i == j)
            {
                cost[i][j] = INT_MAX;
            }
            else
            {
                scanf("%d", &cost[i][j]);

                if (cost[i][j] == 0)
                    cost[i][j] = INT_MAX;

                cost[j][i] = cost[i][j];   // mirror value
            }
        }
    }

    /* Initialize parents */
    for (i = 0; i < v; i++)
        parent[i] = i;

    int edges = 0, total = 0;

    printf("\nEdges in MST:\n");

    while (edges < v - 1)
    {
        int min = INT_MAX;
        int a = -1, b = -1;

        /* Find minimum edge */
        for (i = 0; i < v; i++)
        {
            for (j = 0; j < v; j++)   // upper triangle search
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        int u = find(a);
        int w = find(b);

        /* Cycle check */
        if (u != w)
        {
            printf("%d -> %d : %d\n", a, b, min);
            total += min;
            unionSet(u, w);
            edges++;
        }

        /* Remove used edge */
        cost[a][b] = cost[b][a] = INT_MAX;
    }

    printf("Total cost = %d\n", total);
    return 0;
}