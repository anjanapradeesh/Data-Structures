#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX_NODES 100
int n;
void dfs(int graph[][MAX_NODES], int n, int visited[],int source)
{
    int stack[MAX_NODES];
    int top=-1;
    stack[++top]=source;
    visited[source]=1;
    while(top!=-1)
    {
        int node=stack[top--];
        printf("%d",node);
        for(int i=n-1;i>=0;i--)
        {
            if(graph[node][i]!=0 && !visited[i])
            {
                stack[++top]=i;
                visited[i]=1;
            }
        }
    }
}
int main()
{
    printf("Enter the number of nodes:");
    scanf("%d",&n);
    int V[n];
    for(int i=0;i<n;i++)
    {
        V[i]=0;
    }
    int A[MAX_NODES][MAX_NODES];
    printf("ADJACENCY MATRIX");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("\nA[%d][%d]",i,j);
            scanf("%d",&A[i][j]);
        }
    }
    int source;
    printf("Enter the source:");
    scanf("%d",&source);
    if(source<0 || source>=n)
    {
        printf("Invalid source!");
        return -1;
    }
    printf("DFS->");
    dfs(A,n,V,source);
}
