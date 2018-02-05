#include<conio.h>
#include<iostream.h>
#include<stdlib.h>

struct node
{
     int data;
     struct node *left, *right;
};
struct node *newNode(int item)
{
     struct node *temp =  (struct node *)malloc(sizeof(struct node));
     temp->data = item;
     temp->left = temp->right = NULL;
     return temp;
}
void lefttView(struct Node *root )
{
     if (root==NULL)
     {
	  return;
     }
     else if ( root->left!=NULL)
     {
	  cout<<"\n"<<root->data;
	  leftView(root->left);
     }
     else
     {
	     
	  cout<<"\n"<<root->data;
	  leftView(root->right);
     }	     
}
int main()
{
     clrscr();
     struct node *root = newNode(12);
     root->left = newNode(10);
     root->right = newNode(30);
     root->right->left = newNode(25);
     root->right->right = newNode(40);
     leftView(root);
     getch();
     return 0;
}
