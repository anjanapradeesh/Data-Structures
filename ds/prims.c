#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define max_nodes 100

void main()
{
    int n;
    printf("Enter the number of nodes:");
    scanf("%d",&n);
    int A[max_nodes][max_nodes];
    int V[n];
    printf("Enter adj:");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("A[%d][%d]:",i,j);
            scanf("%d",&A[i][j]);
            if(!A[i][j]){
                A[i][j]=INT_MAX;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        V[i]=0;
    }
    int e=0,cost=0;
    V[0]=1;
    while(e<n-1)
    {
        int u,v,min;
        min=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(V[i])
            {
                for(int j=0;j<n;j++)
                {
                    if(A[i][j]<min && !V[j])
                    {
                        min=A[i][j];
                        u=i;
                        v=j;
                    }
                }
            }
        }
        printf("{%d,%d}=%d",u,v,min);
        V[v]=1;
        e++;
        cost+=min;
    }
    printf("Total:%d",cost);
}