#include <conio.h>
//#include <iostream.h>
#include <stdlib.h>
#include<stdio.h>
struct node
{
     int data;
     struct node *left;
     struct node *right;
     struct node *nextRight;
};

struct node *getNextRight(struct node *p)
{
     struct node *temp = p->nextRight;
     while (temp != NULL)
     {
	  if (temp->left != NULL)
	  {
	       return temp->left;
	  }
	  if (temp->right != NULL)
	  {
	       return temp->right;
	  }
	  temp = temp->nextRight;
     }
     return NULL;
}
void connect(struct node* p)
{
     struct node *temp;
     if (!p)
     {
	  return ;
     }
     p->nextRight = NULL;
     while (p != NULL)
     {
	  struct node *q = p;
	  while (q != NULL)
	  {
	       if (q->left)
	       {
		    if (q->right)
		    {
			 q->left->nextRight = q->right;
		    }
		    else
		    {
			 q->left->nextRight = getNextRight(q);
		    }
	       }
	       if (q->right)
	       {
		    q->right->nextRight = getNextRight(q);
	       }
	       q = q->nextRight;
	  }
	  if (p->left)
	  {
	       p = p->left;
	  }
	  else if (p->right)
	  {
	       p = p->right;
	  }
	  else
	  {
	       p = getNextRight(p);
	  }
     }
}
struct node* newnode(int data)
{
     struct node* node1=new node;
     node1->data = data;
     node1->left = NULL;
     node1->right = NULL;
     node1->nextRight = NULL;
     return(node1);
}
int main()
{
     clrscr();
     struct node *root = newnode(10);
     root->left        = newnode(8);
     root->right       = newnode(2);
     root->left->left  = newnode(3);
     root->right->right       = newnode(90);
     connect(root);
   /*  cout<<"Following are populated nextRight pointers in the tree "
	   "(-1 is printed if there is no nextRight)\n";
     cout<<"\nnextRight of "<<root->data<<"is"<<root->nextRight? root->nextRight->data: -1;
     cout<<"\nnextRight of "<<root->left->data<<"is"<<root->left->nextRight? root->left->nextRight->data: -1;
     cout<<"\nnextRight of "<<root->right->data<<"is"<<root->right->nextRight? root->right->nextRight->data: -1;
     cout<<"\nnextRight of "<<root->left->left->data<<"is"<<root->left->left->nextRight? root->left->left->nextRight->data: -1;
     cout<<"\nnextRight of "<<root->right->right->data<<"is"<<root->right->right->nextRight? root->right->right->nextRight->data: -1; */
     printf("Following are populated nextRight pointers in the tree "
	   "(-1 is printed if there is no nextRight) \n");
     printf("nextRight of %d is %d \n", root->data,
	   root->nextRight? root->nextRight->data: -1);
     printf("nextRight of %d is %d \n", root->left->data,
	   root->left->nextRight? root->left->nextRight->data: -1);
     printf("nextRight of %d is %d \n", root->right->data,
	   root->right->nextRight? root->right->nextRight->data: -1);
     printf("nextRight of %d is %d \n", root->left->left->data,
	   root->left->left->nextRight? root->left->left->nextRight->data: -1);
     printf("nextRight of %d is %d \n", root->right->right->data,
	   root->right->right->nextRight? root->right->right->nextRight->data: -1);
     getch();
     return 0;
}