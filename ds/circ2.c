#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
};
struct node *newnode, *temp, *head;
int pos,value;
void insertatbeg(int value)
{
    newnode=malloc(sizeof(struct node));
    newnode->data=value;
    if(head==NULL)
    {
        newnode->next=newnode;
        head=newnode;
        return;
    }
    struct node *last=head;
    while(last->next!=head)
    {
        last=last->next;
    }
    last->next=newnode;
    newnode->next=head;
    head=newnode;
}

// void insertatend(int data) {
//     if (head == NULL) {
//         insertatbeg(data);
//         return;
//     }

//     struct node* newnode = (struct node*)malloc(sizeof(struct node));
//     newnode->data = data;

//     struct node* last = head;
//     while (last->next != head)
//         last = last->next;

//     last->next = newnode;
//     newnode->next = head;
// }

void insertatend(int value)
{
    if(head==NULL)
    {
        insertatbeg(value);
        return;
    }
    newnode=malloc(sizeof(struct node));
    newnode->data=value;
    struct node *last=head;
    while(last->next!=head)
    {
        last=last->next;
    }
    last->next=newnode;
    newnode->next=head;
}

void insertAtPos(int value)
{
    printf("Enter pos:");
    scanf("%d",&pos);
    newnode=malloc(sizeof(struct node));
    newnode->data=value;
    if(pos==1)
    {
        insertatbeg(value);
        return;
    }
    else
    {
        temp=head;
        for(int i=0;i<pos-1 &&temp->next!=head;i++)
        {
            temp=temp->next;
        }
        if(temp->next==head)
        {
            insertatend(value);
            return;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
}

void display()
{
    if(head==NULL)
    {
        printf("List is empty");
    }
    else
    {
        struct node *last=head;
        while(last->next!=head)
        {
            printf("%d ",last->data);
            last=last->next;
        }
    }
}

void main()
{
    // insertatbeg(10);
    insertatbeg(90);
    insertatend(10);
    insertAtPos(40);
    display();
}


// bst doubly prims
// dfs bfs kruskals