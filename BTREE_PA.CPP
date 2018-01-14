#include <conio.h>
#include <iostream.h>
#include <stdlib.h>
#define bool int
struct node
{
   int data;
   struct node* left;
   struct node* right;
};
bool hasPathSum(struct node* node, int sum)
{
  if (node == NULL)
  {
     return (sum == 0);
  }
  else
  {
     bool ans = 0;
     int subSum = sum - node->data;
     if ( subSum == 0 && node->left == NULL && node->right == NULL )
     {
	  return 1;
     }
     if(node->left)
     {
	  ans = ans || hasPathSum(node->left, subSum);
     }
     if(node->right)
     {
	  ans = ans || hasPathSum(node->right, subSum);
     }
     return ans;
  }
}
struct node* newnode(int data)
{
     struct node* node = (struct node*)malloc(sizeof(struct node));
     node->data = data;
     node->left = NULL;
     node->right = NULL;
     return(node);
}
void main()
{
     clrscr();
     int sum ;
     cout<<"\nenter a number:\n";
     cin>>sum;
     struct node *root = newnode(10);
     root->left        = newnode(8);
     root->right       = newnode(2);
     root->left->left  = newnode(3);
     root->left->right = newnode(5);
     root->right->left = newnode(2);
     if(hasPathSum(root, sum))
     {
	  cout<<"There is a root-to-leaf path with sum :"<<sum;
     }
     else
     {
	  cout<<"There is no root-to-leaf path with sum :"<<sum;
     }
     getch();
}