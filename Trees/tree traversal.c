#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *new_node(int data){
	struct node *node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left=NULL;
	node->right=NULL;
	return(node);
}

void preOrder(struct node *n){
	if(n==NULL)	return;
	printf("%d ",n->data);
	preOrder(n->left);
	preOrder(n->right);
}

void inOrder(struct node *n){
	if(n==NULL)	return;
	inOrder(n->left);
	printf("%d ",n->data);
	inOrder(n->right);
}

void postOrder(struct node *n){
	if(n==NULL)	return;
	postOrder(n->left);
	postOrder(n->right);
	printf("%d ",n->data);
}

int main(){
	struct node *root=new_node(1);
	root->left = new_node(2);
	root->right = new_node(3);
	root->left->left  = new_node(4);
	root->left->right   = new_node(5);
	printf("PreOrder traversal \t");
	preOrder(root);
	printf("\nInOrder traversal \t");
	inOrder(root);
	printf("\nPostOrder traversal\t");
	postOrder(root);
	return 0;
}
