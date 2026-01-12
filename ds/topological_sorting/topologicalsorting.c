#include<stdio.h>
#include<string.h>
#define MAX_NODES 100
int A[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];
int stack[MAX_NODES];
int top=-1;
void dfs(int node, int n)
{
    visited[node]=1;
    for (int j=0;j<n;j++)
    {
        if(A[node][j]==1 && !visited[j])
        {
            dfs(j,n);
        }
    }
    stack[++top]=node;
}
int main()
{
    int n;
    printf("Enter the number of nodes:");
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            printf("A[%d][%d]",i,j);
            scanf("%d",&A[i][j]);
        }
    }
    memset(visited,0,sizeof(visited));
    for (int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            dfs(i,n);
        }
    }
    printf("Topological sorting result:\n");
    while(top!=-1)
    {
        printf("%d\n",stack[top--]);
    }
    printf("\n");
    return 0;
}