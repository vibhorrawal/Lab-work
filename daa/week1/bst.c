#include <stdlib.h>
#include <stdio.h>
struct BST
{
	int data;
	struct BST * prev;
	struct BST * next;
};
typedef struct BST BST;

BST * newNode(int value);
BST * insert(BST * node, int data);
void preorder(BST * node);

int main(int argc, char const *argv[])
{
	BST * root = NULL;

	int choice;
	int value;

	printf("Enter data for root: \n");
	scanf("%d",&value);
	root = insert(root,value);

	printf("*****To END enter -1:*****\n");	
	while(1)
	{	
		printf("Insert more value(s)? : ");
		scanf(" %d",&choice);
		if (choice == -1)
			break;
		//printf("value:\n");
		//scanf("%d",&value);
		insert(root,choice);
	}

	preorder(root);

	return 0;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------

BST * newNode(int value)
{
	BST * temp = (BST *) malloc (sizeof( BST ));
	temp -> data = value;
	temp -> next = NULL;
	temp -> prev = NULL;
	return temp;
}

BST * insert(BST * node, int data)
{
	if ( node == NULL )
		return newNode(data);

	if (data < node -> data)
		node -> prev = insert(node -> prev, data);
	else
		node -> next = insert(node -> next, data);

	return node;
}

void preorder(BST * node)
{
	if (node != NULL)
	{
		printf(" %d,", node -> data);
		preorder(node -> prev);
		preorder(node -> next);
	}
}