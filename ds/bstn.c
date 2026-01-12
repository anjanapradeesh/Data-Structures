#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct node 
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *newnode, *temp, *head;

struct node *createNode(int data)
{
    newnode=malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct node *insert(struct node *root, int data)
{
    if(root==NULL)
    {
        return createNode(data);
    }
    if(data<root->data)
    {
        root->left=insert(root->left,data);
    }
    else if(data>root->data)
    {
        root->right=insert(root->right,data);
    }
    return root;
}

void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d->",root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d->",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d->",root->data);
    }
}

struct node *inorderSuccessor(struct node *root)
{
    while(root && root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}

struct node *delete(struct node *root,int value)
{
    if(root==NULL)
    {
        return root;
    }
    if(value<root->data)
    {
        root->left=delete(root->left,value);
    }
    else if(value>root->data)
    {
        root->right=delete(root->right,value);
    }
    else
    {
        if(root->left==NULL)
        {
            struct node *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            struct node *temp=root->left;
            free(root);
            return temp;
        }
        struct node *temp=inorderSuccessor(root->right);
        root->data=temp->data;
        root->right=delete(root->right,temp->data);
        
    }
}

void main()
{
    struct node *root=NULL;
    root=insert(root,12);
    root=insert(root,15);
    root=insert(root,2);
    root=insert(root,8);
    preorder(root);
    root=delete(root,8);
    preorder(root);
    
}