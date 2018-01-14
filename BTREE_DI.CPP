#include <conio.h>
#include <iostream.h>
#include <stdlib.h>
struct node
{
     int data;
     struct node* left, *right;
};

struct node* newNode(int data);
int max(int a, int b);
int height(struct node* node);

int diameter(struct node *root, int * height)
{
     int lh = 0, rh = 0;
     int ldiameter = 0, rdiameter = 0;
     if(root == NULL)
     {
	 *height = 0;
	  return 0;
     }
     ldiameter = diameter(root->left,& lh);
     rdiameter = diameter(root->right,& rh);
    *height = max(lh, rh) + 1;
     return max(lh + rh + 1, max(ldiameter, rdiameter));
}
int height(struct node* node)
{
     if(node == NULL)
     {
	  return 0;
     }
     return 1 + max(height(node->left), height(node->right));
}
struct node* newNode(int data)
{
     struct node* node = (struct node*)malloc(sizeof(struct node));
     node->data = data;
     node->left = NULL;
     node->right = NULL;
     return(node);
}
int max(int a, int b)
{
     return (a >= b)? a: b;
}
int main()
{
     clrscr();
     struct node *root = newNode(1);
     root->left        = newNode(2);
     root->right       = newNode(3);
     root->left->left  = newNode(4);
     root->left->right = newNode(5);
     cout<<"Diameter of the given binary tree is :\n"<<diameter(root,0);
     getch();
     return 0;
}