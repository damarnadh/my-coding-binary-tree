#include <conio.h>
#include <iostream.h>
#include <stdlib.h>
struct node
{
     int data;
     struct node* left;
     struct node* right;
};

void printKDistant(struct node *root , int k)
{
     if(root == NULL)
     {
	  return;
     }
     if( k == 0 )
     {
	  cout<<root->data<<"\n";
	  return ;
     }
     else
     {
	  printKDistant( root->left, k-1 ) ;
	  printKDistant( root->right, k-1 ) ;
     }
}
struct node* newNode(int data)
{
     struct node* node1 = new node ;
     node1->data = data;
     node1->left = NULL;
     node1->right = NULL;
     return(node1);
}
int main()
{
     clrscr();
     struct node *root = newNode(1);
     root->left        = newNode(2);
     root->right       = newNode(3);
     root->left->left  = newNode(4);
     root->left->right = newNode(5);
     root->right->left = newNode(8);
     printKDistant(root, 2);
     getch();
     return 0;
}

