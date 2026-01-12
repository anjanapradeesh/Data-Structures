#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *temp, *newnode, *front=NULL, *rear=NULL;
void enqueue()
{
    newnode=malloc(sizeof(struct node));
    newnode->next=NULL;
    printf("Enter data:");
    scanf("%d",&newnode->data);
    if(rear==NULL || front==NULL)
    {
        rear=newnode;
        front=newnode;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
    
}
void dequeue()
{
    if(front==NULL)
    {
        printf("empty");
    }
    else
    {
        temp=front;
        printf("deleted:%d",front->data);
        front=front->next;
        free(temp);
    }
}
void display()
{
    if(front==NULL)
    {
        printf("Empty");
        return;
    }
    else
    {
    temp=front;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
}
void main()
{
    enqueue();
    enqueue();
    enqueue();
    enqueue();
    dequeue();
    display();
}