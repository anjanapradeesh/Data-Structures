#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(int value){
    struct node* newnode = (struct node *)malloc(sizeof(struct node));
    newNode->left=NULL;
    newNode->right=NULL;
    newNode->data = value;
    return newnode;
}

struct node * insert(struct Node* root,int value){
    if (root==NULL){
        return createNode(value);
    }

    if (value < root->data)
        root->left=insert(root->left,value);
    
    else if(value > root->data)
       root->right=insert(root->right,value);
    

    return root;
}

void inorder(struct node* root){
    if(root != NULL){
        inorder(root->left);
        printf(" -> %d",root->data);
        inorder(root->right);
    }
}
void preorder(struct node* root){
    if(root != NULL){
        printf(" -> %d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node* root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf(" -> %d",root->data);
    }
}


struct node *search(struct node* root , int value){
    if (root == NULL || root->data==value){
        return root;
    }
    if (value<root->data){
        return search(root->left,value);
    }
    else if (value>root->data){
        return search(root->right,value);
    }
}

struct node *inorderSuccessor(struct node* root){
    while(root && root->left!=NULL){
        root=root->left;
    }
    return root;
}

struct node* delete(struct node* root , int value){
    if (root == NULL){
        return root;
    }
    if (value < root->data){
        root->left=delete(root->left , value);
    }
    else if(value > root->data){
        root->right=delete(root->right , value);
    }
    else{
        if (root->left == NULL){
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = inorderSuccessor(root->right);
        root->data=temp->data;
        root->right = delete(root->right , temp->data);

    }
    return root;
}



int main(){


    root=insert(root,10);
    root=insert(root,6);
    root=insert(root,16);
    root=insert(root,90);
    root=insert(root,9);
    root=insert(root,8);

    printf("inorder :");
    inorder(root);

    printf("\npreorder :");
    preorder(root);

    printf("\npostorder :");
    postorder(root);

    struct node* result=search(root,10);
    if (result != NULL){
    printf("\nresult is -> %d ",result->data);

    int key=10;
    printf("\nafter deleting %d\n",key);
    root = delete(root,key);
    inorder(root);

}
}