#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head,*temp,*newnode;
void insertatbeg(int value)
{
    printf("jjj");
    newnode=malloc(sizeof(struct node));
    newnode->prev=NULL;
    newnode->next=head;
    newnode->data=value;
    if(head!=NULL)
    {
        head->prev=newnode;
    }
    head=newnode;
    
}
void insertatend(int value)
{
    newnode=malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    if(head==NULL)
    {
        newnode->prev=NULL;
        head=newnode;
    }
    struct node *last=head;
    while(last->next!=NULL)
    {
        last=last->next;
    }
    newnode->prev=last;
        last->next=newnode;
}

void insertAtPos(int pos,int value)
{
    if(pos==1)
    {
        insertatbeg(value);
        return;
    }
    else
    {
        int i=1;
        temp=head;
        // struct node *prev;
        while(i<pos-1)
        {
            // prev=temp;
            temp=temp->next;
        }
        if(temp->next==NULL)
        {
            insertatend(value);
            return;
        }
        newnode=malloc(sizeof(struct node));
        newnode->data=value;
        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next=newnode;
        temp->next->prev=newnode;
        
    }
}
void display()
{
    printf("fff");
    if(head==NULL)
    {
        printf("Empty");
        return;
    }
    else
    {
        temp=head;
        while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
}

void deletefrombeg

void main()
{
    struct node *head;
    insertatbeg(10);
    insertatbeg(20);
    insertatbeg(30);
    display();
    insertatend(90);
    display();
    insertAtPos(2,8);
    display();
}