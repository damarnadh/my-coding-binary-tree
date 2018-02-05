#include <conio.h>
#include <iostream.h>
#include <stdlib.h>
struct Node
{
     int data;
     struct Node *left, *right;
};
struct Node *newNode(int item)
{
     struct Node *temp =  (struct Node *)malloc(sizeof(struct Node));
     temp->data = item;
     temp->left = temp->right = NULL;
     return temp;
}
void rightView(struct Node *root )
{
     if (root==NULL)
     {
	  return;
     }
     else if ( root->right!=NULL)
     {
	  cout<<"\n"<<root->data;
	  rightView(root->right);
     }
     else
     {
	     
	  cout<<"\n"<<root->data;
	  rightView(root->left);
     }	     
}
int main()
{
     clrscr();
     struct Node *root = newNode(1);
     root->left = newNode(2);
     root->right = newNode(3);
     root->left->left = newNode(4);
     root->left->right = newNode(5);
     root->right->left = newNode(6);
     root->right->right = newNode(7);
     root->right->left->right = newNode(8);
     rightView(root);
     getch();
     return 0;
}
