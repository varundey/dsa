#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *new_node(int data){
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->left=temp->right = NULL;
	return temp;
}

void inOrder(struct node *root){
	if(root!=NULL){
		inOrder(root->left);
		printf("%d ",root->data);
		inOrder(root->right);
	}
}

struct node *insert(struct node *root, int data){
	if(root==NULL){
		return new_node(data);
	}
	if(data < root->data){
		root->left= insert(root->left, data);
	}
	if(data > root->data){
		root->right = insert(root->right, data);
	}
	return root;
}

int main(){
	struct node *root=NULL;
	root = insert(root, 50);
	insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
	inOrder(root);
	return 0;
}
