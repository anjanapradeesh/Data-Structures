#include<stdio.h>
#include<stdlib.h>
#define max 5
int stack[max],top=-1;
void push(int data)
{
    if(top==max-1)
    {
    printf("Stack Overflow\n");
    }
    else
    {
    top++;
    stack[top]=data;
    printf("Data inserted\n");
    }
}
int pop()
{
    if (top==-1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
    return stack[top];
    top--;
    }
}
void display()
{
    int i;
    if (top==-1)
    {
    printf("Stack Underflow\n");
    }

else
{
    for(i=top;i>=-1;i--)
    {
        printf("%d\n",stack[i]);
    }

}
}
void main()
{
    int choice;
    printf("STACK OPERATIONS");
    printf("\n1. PUSH\n2. POP\n3. DISPLAY\n4. EXIT");
    printf("\nSelect an operation:\n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
    {
        int data;
        printf("Enter the data to be pushed:\n");
        scanf("%d",&data);
        push(data);
    }
    case 2:
    {
        int data;
        printf("Popped element is:%d",pop());
    }
    case 3:
    {
        printf("Elements in stack are:");
        display();
    }
    case 4:
    {
        exit(0);
    }
    while(1)
    {
    printf("Do you want to continue(1/0):");
    int ch;
    scanf("%d",&ch);    
    if (ch==1)
    {
        main();
    }
    else
    {
        exit(0);
    }
}

    }
}