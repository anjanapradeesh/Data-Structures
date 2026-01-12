#include<stdio.h>
#include<limits.h>

int main()
{
    
    int n;
    printf("Enter the number of nodes:");
    scanf("%d",&n);
    int A[n][n];
    printf("ADJACENCY MATRIX:");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("A[%d][%d]:",i,j);
            scanf("%d",&A[i][j]);
            if(A[i][j]==0)
            {
                A[i][j]=INT_MAX;
            }
        }
    }
    int e=0,cost=0,u,v;
    while(e<n-1)
    {
        int min=INT_MAX;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(A[i][j]<min)
                {
                    min=A[i][j];
                    u=i;
                    v=j;
                }
            }
        }
        
        printf("{%d,%d}=%d",u,v,min);
        cost=cost+min;
        e++;
        A[u][v]=A[v][u]=INT_MAX;

    }
    printf("COST=",cost);
}