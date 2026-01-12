#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int arr[MAX];
int size=-1;

void insert(int num)
{
    int pos;
    printf("Enter pos:");
    scanf("%d",&pos);
    pos--;
    if(pos<0 || pos>size+1|| size>=MAX-1)
    {
        printf("INVALID POS");
        return;
    }
    for(int i=size+1;i>0;i--)
    {
        arr[i]=arr[i-1];
    }
    arr[pos]=num;
    size++;
    printf("success");
}
void delete()
{
    int pos;
    printf("Enter pos:");
    scanf("%d",&pos);
    pos--;
    if(size<0)
    {
        printf("ARRAY EMPTY");
        return;
    }
    else if(pos<0 || pos>size+1)
    {
        printf("INVALID POS");  
        return;
    }
    printf("deleted %d",arr[pos]);
    for(int i=pos;i<size+1;i++)
    {
        arr[i]=arr[i+1];
    }
    size--;
}
void display()
{
    if(size==-1)
    {
        printf("empty");
    }
    else{
        for(int i=0;i<size+1;i++)
        {
            printf("%d ",arr[i]);

        }
    }
}

void main()
{
    insert(10);
    // display();


    insert(20);
    // display();

    insert(30);
    // display();

    insert(40);
    // display();

    insert(50);
    display();

    delete();
    
    display();
}