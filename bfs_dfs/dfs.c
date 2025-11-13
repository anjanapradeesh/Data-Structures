#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int graph[MAX][MAX];
int stack[MAX];
int visited[MAX];
int top=-1;

void push(int v)
{
    if(top==MAX-1)
    {
        return;
    }
    stack[++top]=v;
}

int pop()
{
    if(top==-1)
    {
        return -1;
    }
    return stack[top--];
}

void dfs(int start, int n)
{
    int v,i;
    push(start);
    visited[start]=1;
    printf("DFS TRAVERSAL:\n");
    while(top!=-1)
    {
        v=pop();
        printf("%d ",v);
        for(int i=n-1;i>=0;i--)
        {
            if(graph[v][i]==1 && !visited[i])
            {
                push(i);
                visited[i]=1;
            }
        }
    }
    printf("\n");
}

int main()
{
    int n=6;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            graph[i][j]=0;
        }
    }

    graph[0][1] = graph[1][0] = 1;
    graph[0][2] = graph[2][0] = 1;
    graph[1][3] = graph[3][1] = 1;
    graph[2][4] = graph[4][2] = 1;
    graph[3][5] = graph[5][3] = 1;

    for (int i=0;i<n;i++)
    {
        visited[i] = 0;
    }
    dfs(0, n);
    return 0;
}
