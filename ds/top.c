#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX_NODES 100

int A[MAX_NODES][MAX_NODES];
int stack[MAX_NODES];
int V[MAX_NODES];
int top=-1;

void dfs(int node, int n)
{
    V[node]=1;
    for(int i=0;i<n;i++)
    {
        if(A[node][i]==1 && !V[i])
        {
            dfs(i,n);
        }
    }
    stack[++top]=node;
}
void main()
{
    int n;
    printf("Enter the number of nodes:");
    scanf("%d",&n);
    printf("ADJ");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("A[%d][%d]",i,j);
            scanf("%d",&A[i][j]);
            
        }
    }
    for(int i=0;i<n;i++)
    {
        V[i]=0;
    }
    for(int j=0;j<n;j++)
    {
        if(!V[j])
        {
            dfs(j,n);
        }
    }
    printf("\nSTACK ELEMENTS ARE:");
    while(top!=-1)
    {
        printf("%d ",stack[top]);
        top--;
    }
}