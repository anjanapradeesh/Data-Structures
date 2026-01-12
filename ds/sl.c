#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *bottom;
};
 struct node *newnode,*temp,*top=NULL;
void push(int value)
{
    newnode=malloc(sizeof(struct node));
    newnode->data=value;
    newnode->bottom=top;
    top=newnode;

}

void pop()
{
    if(top==NULL)
    {
        return;
    }
    temp=top;
    top=top->bottom;
    free(temp);
}

void peek()
{
    if(top==NULL)
    {
        printf("Empty");
    }
    printf("%d",top->data);
        
    
    
}

void display()
{
    temp=top;
    while(temp!=NULL)
    {
        printf("%d",top->data);
        top=top->bottom;
    }
}

void main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    pop();
    peek();
    display(); 

    
}