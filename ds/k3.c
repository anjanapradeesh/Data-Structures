#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

int parent[10];

int find(int v)
{
    while(parent[v]!=v)
    {
        v=parent[v];
    }
    return v;
}

void UnionSet(int a, int b)
{
    parent[a]=b;
}

int main()
{
    int v;
    printf("Enter the number of vertices:");
    scanf("%d",&v);
    int cost[10][10];

    for(int i=0;i<v;i++)
    {
        for(int j=i;j<v;j++)
        {
            if(i==j)
            {
                cost[i][j]=INT_MAX;
            }
            else
            {
                printf("cost[%d][%d]",i,j);
                scanf("%d",&cost[i][j]);
                if(cost[i][j]==0)
                {
                    cost[i][j]=INT_MAX;
                }
                cost[j][i]=cost[i][j];

            }
            }
        }
        for(int i=0;i<v;i++)
        {
            parent[i]=i;
        }
        int edges=0,total=0;
        while(edges<v-1)
        {
            int min,a=-1,b=-1;
            min=INT_MAX;
            for(int i=0;i<v;i++)
            {
                for(int j=0;j<v;j++)
                {
                    if(cost[i][j]<min)
                    {
                        min=cost[i][j];
                        a=i;
                        b=j;
                    }
                   
                }
            }
             int u=find(a);
            int w=find(b);
            if(u!=w)
                    {
                        printf("{%d,%d}=%d",a,b,min);
                        total+=min;
                        UnionSet(u,w);
                        edges++;
                    }
                    cost[a][b]=cost[b][a]=INT_MAX;
        
    }
    printf("cost=%d",total);

    
}