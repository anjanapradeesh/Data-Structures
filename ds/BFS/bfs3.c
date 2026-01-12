#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX_NODES 100

int n;
int queue[MAX_NODES];
int front=-1, rear=-1;

void enqueue(int value);
int dequeue();

void bfs(int graph[][MAX_NODES],int n,int visited[],int source)
{
    enqueue(source);
    visited[source]=1;
    while(front!=-1 && front<=rear)
    {
        int node=dequeue();
        printf("%d",node);
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
    int A[MAX_NODES][MAX_NODES];
    printf("Enter the number of nodes:");
    scanf("%d",&n);
    int V[n];
    for(int i=0;i<n;i++)
    {
        V[i]=0;
    }
    printf("ADJACENCY MATRIX:");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("\nA[%d][%d]",i,j);
            scanf("%d",&A[i][j]);
        }
    }
    int source;
    printf("Enter source:");
    scanf("%d",&source);
    if(source<0 || source>=n)
    {
        printf("Invalid source");
        return -1;
    }
    printf("BFS->");
    bfs(A,n,V,source);
    printf("\n");
}

void enqueue(int value)
{
    if(rear==n-1)
    return;
    if(front==-1)
    front=0;
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