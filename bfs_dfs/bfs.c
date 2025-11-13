#include<stdio.h>
#include<stdlib.h>

#define MAX 10
int queue[MAX];
int graph[MAX][MAX];
int visited[MAX];
int front=-1,rear=-1;

void enqueue(int v)
{
    if(rear==MAX-1){
        return;
    }
    if(front==-1)
    {
        front=0;
    }
    queue[++rear]=v;

}

int dequeue()
{
    if (front==-1 || front>rear)
    {
        return -1;
    }
    return queue[front++];
}

void bfs(int start, int n)
{
    for (int i=start;i<n;i++)
    {
        visited[i]=0;
    }
    enqueue(start);
    visited[start]=1;

    printf("BFS TRAVERSAL:\n");
    while(front<=rear)
    {
        int v=dequeue();
        printf("%d ",v);
        for (int i=0;i<n;i++)
        {
            if(graph[v][i]==1 && !visited[i])
            {
                enqueue(i);
                visited[i]=1;
            }
        }
    }
    printf("\n");
}
int main()
{
    int n=6;
    for (int i=0;i<n;i++)
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
    bfs(0,n);
    return 0;
}