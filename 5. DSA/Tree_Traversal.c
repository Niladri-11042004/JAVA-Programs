#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *left, *right;
};
struct node *create()
{
  int x; struct node *newnode;
  newnode =(struct node*)malloc(sizeof(struct node));
  printf("\nEnter data: ");
  scanf("%d",&x);
  if(x==-1)
    return 0;
  newnode->data=x;
  printf("\nEnter left child of %d", x);
  newnode->left=create();
  printf("\nEnter right child of %d", x);
  newnode->right=create();
  return newnode;
};

void preorder(struct node *root)
{
    if(root == 0)
        return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root)
{
    if(root == 0)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}


void inorder(struct node *root)
{
    if(root == 0)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}


void main()
{
    struct node *root;
    root=0;
    root=create();
    printf("\n Preorder:");
    preorder(root);
    printf("\n Postorder:");
    postorder(root);
    printf("\n Inorder:");
    inorder(root);
}