#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *newnode, *head,*temp;
void insertatbeg(int value)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->left=NULL;
    newnode->right=head;
    newnode->data=value;
    if(head!=NULL){
        head->left=newnode;
    }
    // temp->left=newnode;
    // newnode->right=temp;
    head=newnode;
    printf("hello");
}

void insertatend(int value)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->right=NULL;
    newnode->data=value;
    if(head==NULL)
    {
        newnode->left=NULL;
        head=newnode;
        return ;
    }
    temp=head;
    while(temp->right!=NULL)
    {
        temp=temp->right;
    }
    temp->right=newnode;  
    newnode->left=temp;
}

void insertatpos(int pos,int value)
{
    temp=head;
    int i=0;
    if(pos==1)
    {
        insertatbeg(value);
        return;
    }
    while(i<pos-1 && temp!=NULL){
        temp=temp->right;
        i++;
    }
    if(temp==NULL)
    {
        insertatend(value);
        return;
    }
    newnode=malloc(sizeof(struct node));
    newnode->data=value;
    newnode->right=temp->right;
    
    newnode->left=temp;
    if(temp->right!=NULL)
    {
        temp->right->left=newnode;
    }
    temp->right=newnode;
}

void traversal()
{
    temp=head;
    while(temp!=NULL)
    {
        printf("%d ->",temp->data);
        temp=temp->right;
    }
    // printf("%d",temp->data);
}

void deletefrombeg()
{
    if(head==NULL)
    {
        printf("LIST EMPTY");
        return;
    }
    temp=head;
    head=head->right;
    
    if(head!=NULL)
    {
        head->left=NULL;
    }
    free(temp);
}

void deletefromend()
{
    if(head==NULL)
    {
        printf("LIST EMPTY");

    }
    temp=head;
    while(temp->right!=NULL)
    {
        temp=temp->right;
    }
    temp->left->right=NULL;
    free(temp);
}

void deletefrompos(int pos)
{   
    temp=head;
    int i=0;
    while(i<pos-1)
    {
        printf("hi1");
        temp=temp->right;
        i++;
    }
    temp->right->left=temp->left;
    temp->left->right=temp->right;
    printf("hi2");

    free(temp);
}

void main()
{
    int ch,value,pos,f=1,node;
    insertatbeg(10);
    insertatbeg(20);
    insertatbeg(30);
    insertatbeg(40);
    while(f==1)
    {
        printf("1.insertatbeg\n");
        printf("2.insertatend\n");
        printf("3.insertatpos\n");
        printf("4.traversal\n");
        printf("5.deletefrombeg\n");
        printf("6.deletefromend\n");
        printf("7.deletefrompos\n");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter the value:");
            scanf("%d",&value);
            insertatbeg(value);
            break;

            case 2:
            printf("Enter the value:");
            scanf("%d",&value);
            insertatend(value);
            break;

            case 3:
            printf("Enter the value:");
            scanf("%d",&value);
            printf("Enter the position:");
            scanf("%d",&pos);
            insertatpos(pos,value);
            break;

            case 4:
            traversal();
            break;

            case 5:
            deletefrombeg();
            break;

            case 6:
            deletefromend();
            break;

            case 7:
            printf("Enter the position:");
            scanf("%d",&pos);
            deletefrompos(pos);
            break;

            default:
            printf("INVALID CHOICE");
        }
        printf("Do you want to continue?(1/0)");
        scanf("%d",&f);
    }
}