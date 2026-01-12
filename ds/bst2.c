#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
 
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node *newnode, *root;
struct node *createNode(int value)
{
    newnode=malloc(sizeof(struct node));
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->data=value;
    return newnode;
}

struct node *insert(struct node *root,int value)
{
    printf("h");
    if(root==NULL)
    {
        return createNode(value);
    }
    if(value < root->data)
    {
        root->left=insert(root->left,value);
    }
    else if(value > root->data)
    {
        root->right=insert(root->right,value);
    }
    return root;
}

void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("->%d",root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if(root!=NULL)
    {
        printf("->%d",root->data);
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
        printf("->%d",root->data);
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
    else{
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
        root->right=delete(root->right,value);
    }
    return root;
}

// struct node *search(struct node *root, int value)
// {
//     if(root->data==value)
//     {
//         return root;
//     }
//     else if(value<root->data)
//     {
//         return search(root->data,value);
//     }
//     else{
//         return search(root->data,value);
//     }
//     return root;
// }

void main()
{
    struct node *root=NULL;
    struct node *temp=NULL;
    root=insert(root,20);
    root=insert(root,22);
    root=insert(root,1);
    root=insert(root,12);
    root=insert(root,57);
    root=insert(root,39);
    inorder(root);
    printf("\n");
    root=delete(root,22);
    root=delete(root,20);
    inorder(root);
}