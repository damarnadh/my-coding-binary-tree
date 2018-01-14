#include <conio.h>
#include <iostream.h>
#include <stdlib.h>
#define  bool int
struct node
{
    int data;
    struct node* left;
    struct node* right;
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
bool isBalanced(struct node *root)
{
    int lh;
    int rh;
    if(root == NULL)
    {
	 return 1;
    }
    lh = height(root->left);
    rh = height(root->right);
    if( abs(lh-rh) <= 1 &&isBalanced(root->left) &&isBalanced(root->right))
    {
	 return 1;
    }
    return 0;
}
/* OPTIMISED ONE

bool isBalanced(struct node *root, int* height)
{
    int lh = 0, rh = 0;
    int l = 0, r = 0;
    if(root == NULL)
    {
	*height = 0;
	 return 1;
    }
    l = isBalanced(root->left, &lh);
    r = isBalanced(root->right,&rh);
    *height = (lh > rh? lh: rh) + 1;
    if((lh - rh >= 2) || (rh - lh >= 2))
    {
	 return 0;
    }
    else
    {
	 return l&&r;
    }
}


*/
struct node* newNode(int data)
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
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->left->left->left = newNode(7);
    if(isBalanced(root))
    {
	 cout<<"Tree is balanced";
    }
    else
    {
	 cout<<"Tree is not balanced";
    }
    getch();
}