#include<stdio.h>
#include<stdlib.h>

struct binary_tree
{
	int data;
	struct binary_tree *left;
	struct binary_tree *right;
	
};

void insert(struct binary_tree **tree,int val)
{
	struct binary_tree *temp;
	if(*tree == NULL)
	{
		temp = (struct binary_tree *)malloc(sizeof(struct binary_tree));
	 	temp->left = temp->right = NULL;
		temp->data = val;
		*tree = temp;
		return ;
	}	
	if(val < (*tree)->data)
	{
		insert(&(*tree)->left,val);
	}
	if(val > (*tree)->data)
	{
		insert(&(*tree)->right,val);
	}
}
		
void delete(struct binary_tree *tree)
{
	if(tree)
	{
		delete(tree->left);
		delete(tree->right);
		free(tree);
	}
}

void printPreorder(struct binary_tree *tree)
{
	if(tree)
	{
		printf("%d\n",tree->data);
		printPreorder(tree->left);
		printPreorder(tree->right);
	}
}


void printInorder(struct binary_tree *tree)
{
	if(tree)
	{
		printf("%d\n",tree->data);
		printInorder(tree->left);
		printInorder(tree->right);
	}
}


void printPostorder(struct binary_tree *tree)
{
	if(tree)
	{
		printf("%d\n",tree->data);
		printPostorder(tree->left);
		printPostorder(tree->right);
	}
}

int main()
{
	struct binary_tree *root;
	struct binary_tree *temp;

	root = NULL;
	
	insert(&root,5);
	insert(&root,3);
	insert(&root,7);
	insert(&root,8);
	insert(&root,11);
	insert(&root,4);
	
	printf("PrintPreoder:\n");
	printPreorder(root);
	
	printf("PrintInorder:\n");
	printInorder(root);
	
	printf("PrintPostorder:\n");
	printPostorder(root);

	delete(root);
}

	
