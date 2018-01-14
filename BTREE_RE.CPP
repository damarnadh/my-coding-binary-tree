#include <conio.h>
#include <iostream.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

void printGivenLevel(struct node* root, int level);
int height(struct node* node);
struct node* newNode(int data);

void reverseLevelOrder(struct node* root)
{
    int h = height(root);
    int i;
    for (i=h; i>=1; i--)
    {
	printGivenLevel(root, i);
    }
}
void printGivenLevel(struct node* root, int level)
{
    if (root == NULL)
    {
	return;
    }
    if (level == 1)
    {
	cout<<root->data;
    }
    else if (level > 1)
    {
	printGivenLevel(root->left, level-1);
	printGivenLevel(root->right, level-1);
    }
}
int height(struct node* node)
{
    if (node==NULL)
    {
	return 0;
    }
    else
    {
	int lheight = height(node->left);
	int rheight = height(node->right);
	if (lheight > rheight)
	{
	    return(lheight+1);
	}
	else return(rheight+1);
    }
}
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
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    cout<<"Level Order traversal of binary tree is \n";
    reverseLevelOrder(root);
    getch();
}