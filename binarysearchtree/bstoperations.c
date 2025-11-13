#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node* createNode(int value)
{
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->left=newnode->right=NULL;
    newnode->data=value;
    return newnode;
}
struct Node* insert(struct Node* root, int value)
{
    if (root==NULL)
    {
        return createNode(value);
    }
    if (value<root->data)
    {
        root->left=insert(root->left,value);
    }
    else if(value>root->data)
    {
        root->right=insert(root->right,value);
    }
    return root;
}
struct Node* search(struct Node *root, int key)
{
    if (root==NULL || key==root->data)
    {
        return root;
    }
    if (key<root->data)
    {
        return search(root->left,key);
    }
    else
    {
        return search(root->right,key);
    }
}
struct Node* findMin(struct Node *node)
{
    struct Node *current=node;
    while(current && current->left!=NULL)
    {
        current=current->left;
    }
    return current;
}
struct Node* deleteNode(struct Node *root, int key)
{
    if(root==NULL)
    {
        return root;
    }
    if(key<root->data)
    {
        root->left=deleteNode(root->left,key);
    }
    else if(key>root->data)
    {
        root->right=deleteNode(root->right,key);
    }
    else{
        if (root->left==NULL)
        {
            struct Node *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            struct Node *temp=root->left;
            free(root);
            return temp;
        }
        struct Node *temp=findMin(root->right);
        root->data=temp->data;
        root->right=deleteNode(root->right,temp->data);
    }
    return root;
}
void inorder(struct Node *root)
{
    if (root!=NULL)
    {
        inorder(root->left);
        printf("-> %d",root->data);
        inorder(root->right);
    }
   
}
void preorder(struct Node *root)
{
    if(root!=NULL)
    {
        printf("%d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct Node *root)
{
    if (root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->data);
    }
}
int main()
{
    
    // root = insert(root, 50);
    // root = insert(root, 40);
    // root = insert(root, 60);
    // root = insert(root, 70);

    // inorder(root);
    int ch=1;
    // scanf("%d",&ch);
    struct Node* root=NULL;
    while(ch==1)
    {
        int choice;
    printf("Binary Search Tree Operations\n");
    printf("*******************************\n");
    printf("1. Insertion\n");
    printf("2. Deletion\n");
    printf("3. Search\n");
    printf("4. Inorder Traversal\n");  
    printf("5. Preorder Traversal\n");
    printf("6. Postorder Traversal\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
    
        switch (choice)
        {
            case 1:
            {
                int limit,value;
                printf("Enter the number of values to be inserted into the BST:");
                scanf("%d",&limit);
                for(int i=0;i<limit;i++)
                {
                    printf("Enter value to insert:");
                    scanf("%d",&value);
                    root=insert(root,value);
                }
                printf("Value inserted successfully.\n");
                break;
            }
            case 2:
            {
                int key=0;
                printf("Enter the value to be deleted:");
                scanf("%d",&key);
                root=deleteNode(root,key);
                printf("Value deleted successfully.\n");
                break;
            }
            case 3:
            {
                printf("Enter the value to be searched:");
                int key=0;
                scanf("%d",&key);
                struct Node *found=search(root,key);
                if (found!=NULL)
                {
                    printf("Value is found in the BST\n");
                }
                else
                {
                    printf("Value not found in BST\n");
                }
                break;
            }
            case 4:
            {
                printf("Inorder Traversal of BST:");
                inorder(root);
                printf("\n");
                break;
            }
            case 5:
            {
                printf("Preorder Traversal of BST:");
                preorder(root);
                printf("\n");
                break;
            }
            case 6:
            {
                printf("Postorder Traversal of BST:");
                postorder(root);
                printf("\n");
                break;
            }
        }
        printf("Do you want to continue? (1 for Yes / 0 for No):"); 
        scanf("%d",&ch);
        }
return 0;
}