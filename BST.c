#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode *left,*right;
};

struct TreeNode * createNode(int ele){
    struct TreeNode * newNode = malloc(sizeof(struct TreeNode));
    newNode->data=ele;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

struct TreeNode * insertBST(struct TreeNode * root,int ele)
{
    if(root==NULL){
        root=createNode(ele);
        return root;
    }
    if(root->data<ele){
        root->right=insertBST(root->right,ele);
    }
    else if(root->data>ele){
        root->left=insertBST(root->left,ele);

    }
    return root;
}

void preOrderTraversal(struct TreeNode * root){
    if(root){
        printf("%d ",root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void postOrderTraversal(struct TreeNode * root){
    if(root){
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ",root->data);
    }
}

void inOrderTraversal(struct TreeNode * root){
    if(root){
        inOrderTraversal(root->left);
        printf("%d ",root->data);
        inOrderTraversal(root->right);
    }
}

int main(int argc, char const *argv[])
{
    struct TreeNode * root = malloc(sizeof(struct TreeNode));
    root=NULL;
    while (1)
    {
        printf("Enter choice 1.Insert 2.PreOrder 3.InOrder 4.PostOrder\n");
        int choice;
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: printf("Enter element to be inserted\n");
                int n;
                scanf("%d",&n);
                root=insertBST(root,n);
            break;
        case 2: printf("PRE ORDER TRAVERSAL\n");
                preOrderTraversal(root);
            break;
        case 3: printf("IN ORDER TRAVERSAL\n");
                inOrderTraversal(root);
            break;
        case 4: printf("POST ORDER TRAVERSAL\n");
                postOrderTraversal(root);
                break;
        default:printf("INVALID CHOICE\n");

            break;
        }
    }
    
    return 0;
}
