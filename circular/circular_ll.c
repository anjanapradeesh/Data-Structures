#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head=NULL;
void insertAtBeginning(int data){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    if (head==NULL)
    {
        newnode->prev=newnode;
        newnode->next=newnode;
        head=newnode;
        return;
    }
struct node *last=head->prev;
newnode->prev=last;
newnode->next=head;
last->next=newnode;
head->prev=newnode;
head=newnode;
}

void insertAtEnd(int data)
{
    
    if (head==NULL)
    {
        insertAtBeginning(data);
        return;
    }
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    struct node *last=head->prev;
    last->next=newnode;
    newnode->prev=last;
    newnode->next=head;
    head->prev=newnode;
}

void insertAtPosition(int data, int pos)
{
    if (pos==1)
    {
        insertAtBeginning(data);
        return;
    }
    struct node *temp=head;
    for (int i=1;i<pos-1 && temp->next!=head;i++)
    {
        temp=temp->next;
    }
    if(temp->next==head)
    {
        insertAtEnd(data);
        return;
    }
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=temp->next;
    newnode->prev=temp;
    newnode->next->prev=newnode;
    temp->next=newnode;

}

void display()
{
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct node *temp=head;
    printf("List: ");
    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=head);
    return;
    
}

void deleteAtBeginning()
{
    if (head==NULL)
    {
        return;
    }
    if (head->next==head)
    {
        free(head);
        head=NULL;
        return;
    }
    struct node *last=head->prev;
    struct node *temp=head;
    head = head->next;
    head->prev = last;
    last->next = head;
    free(temp);
}

void deleteAtEnd()
{
    if (head==NULL)
    {
        return;
    }
    if(head->next==head)
    {
        free(head);
        head=NULL;
        return;
    }
    struct node *
}

int main() {
    insertAtBeginning(10);
    insertAtEnd(20);
    insertAtPosition(15, 2);
    display();
    deleteAtBeginning();
    display();
    return 0;
}