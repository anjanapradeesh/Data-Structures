#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX_NODES 100
int queue[MAX_NODES];
// int visited[MAX_NODES];
int front=-1,rear=-1;
int n;
void enqueue(int value);
int dequeue();
void bfs(int graph[][MAX_NODES], int n, int visited[],int source)
{
    enqueue(source);
    visited[source]=1;
    while(front<=rear && front!=-1)
    {
        int node=dequeue();
        printf("%d ",node);
        for(int i=0;i<n;i++)
        {
            if(graph[node][i]!=0 && !visited[i])
            {
                enqueue(i);
                visited[i]=1;
            }
        }
    }
}
int main()
{
    printf("Enter the no of nodes:");
    scanf("%d",&n);
    int V[n];
    for(int i=0;i<n;i++)
    {
        V[i]=0;
    }
    printf("Enter adjacency matrix:");
    int A[MAX_NODES][MAX_NODES];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("A[%d][%d]",i,j);
            scanf("%d",&A[i][j]);
        }
    }
    int source;
    printf("Enter the source:");
    scanf("%d",&source);
    if(source<0 || source>=n)
    {
        printf("Source is invalid!");
        return -1;
    }
    printf("BFS->");
    bfs(A,n,V,source);
    printf("\n");
}

void enqueue(int value)
{
    if(rear==n-1)
    {
        return;
    }
    if(front==-1)
    {
        front=0;
    }
    rear++;
    queue[rear]=value;
}

int dequeue()
{
    if(front==-1)
    {
        return -1;
    }
    int value=queue[front];
    front++;
    return value;
}
