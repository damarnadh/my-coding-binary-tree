#include <conio.h>
#include <iostream.h>
#include <stdlib.h>
struct node
{
     struct node *left;
     int data;
     struct node *right;
};
int max(int a, int b)
{
      return (a >= b)? a: b;
}
int height(struct node* node)
{
      if(node == NULL)
      {
	   return 0;
      }
      return 1 + max(height(node->left), height(node->right));
}
void printGivenLevel(struct node* root, int level)
{
      if (root == NULL)
      {
	   return;
      }
      if (level == 1)
      {
	   cout<<root->data<<" ";
      }
      else if (level > 1)
      {
	   printGivenLevel(root->left, level-1);
	   printGivenLevel(root->right, level-1);
      }
}
void printLevelOrder(struct node* root)
{
      int h = height(root);
      int i;
      for (i=1; i<=h; i++)
      {
	   printGivenLevel(root, i);
	   cout<<"\n";
      }
}
node* newNode(int data)
{
      node *temp = new node;
      temp->data = data;
      temp->left = NULL;
      temp->right = NULL;
      return temp;
}
void main()
{
      clrscr();
      node *root = newNode(1);
      root->left = newNode(2);
      root->right = newNode(3);
      root->left->left = newNode(4);
      root->left->right = newNode(5);
      root->right->right = newNode(6);
      printLevelOrder(root);
      getch();
}