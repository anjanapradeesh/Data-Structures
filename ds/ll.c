#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *newNode,*temp,*head=NULL;
void insertAtStart(int data)
{
    printf("A");
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    head=newNode;
}
void insertAtEnd(int data)
{
    newNode=malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;

    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
}

void insertAtPos(int pos,int data)
{
    if(pos==1)
    {
        insertAtStart(data);
        return;
    }
    else
    {
        newNode=malloc(sizeof(newNode));
        newNode->data=data;
        newNode->next=NULL;
        temp=head;
        int i=1;
        while(i<pos-1)
        {
            temp=temp->next; 
            i++;  
        }
        newNode->next=temp->next;

        temp->next=newNode;
        
    }
}

void deleteAtStart()
{
    if(head==NULL)
    {
        printf("empty");
        return;
    }
    else
    {
        temp=head;
        head=head->next;
        free(temp);
    }
}
void deleteAtEnd()
{
    struct Node *prev;
    temp=head;
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;

    }
    prev->next=NULL;
    free(temp);
}

void deleteAtPos(int pos)
{
    struct Node *prev;
    int i=1;
    temp=head;
    while(i<pos-1)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    free(temp);

}

void display() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void main()
{
    insertAtStart(10);
    // display();

    insertAtEnd(30);
    // // display();
    // insertAtEnd(20);
    insertAtEnd(50);

    insertAtPos(2,15);
    display();
    printf("\n\n");
    // deleteAtStart();
    // printf("sssssssss");
    // display();
    // deleteAtEnd();
    // printf("ssddddffff");
    // display();
    deleteAtPos(2);
}