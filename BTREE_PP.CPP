#include <conio.h>
#include <iostream.h>
#include <stdlib.h>
struct node
{
     int data;
     struct node *left;
     struct node *right;
     struct node *nextRight;
};
struct node* newNode(int data)
{
     struct node* node1=new node;
     node1->data = data;
     node1->left = NULL;
     node1->right = NULL;
     node1->nextRight = NULL;
     return(node1);
}
void printArray(int ints[], int len)
{
     int i;
     for (i=0; i<len; i++)
     {
	  cout<<ints[i];
     }
     cout<<"\n";
}
void printPathsRecur(struct node* node, int path[], int pathLen)
{
     if (node==NULL)
     {
	  return;
     }
     path[pathLen] = node->data;
     pathLen++;
     if (node->left==NULL && node->right==NULL)
     {
	  printArray(path, pathLen);
     }
     else
     {
	  printPathsRecur(node->left, path, pathLen);
	  printPathsRecur(node->right, path, pathLen);
     }
}
void printPaths(struct node* node)
{
     int path[1000];
     printPathsRecur(node, path, 0);
}
int main()
{
     clrscr();
     struct node *root = newNode(1);
     root->left        = newNode(2);
     root->right       = newNode(3);
     root->left->left  = newNode(4);
     root->left->right = newNode(5);
     printPaths(root);
     getch();
     return 0;
}