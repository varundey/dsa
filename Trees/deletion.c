#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *left, *right;
};

struct node *new_node(int data){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data= data;
	temp->left=temp->right = NULL;
	return temp;
}

struct node *insert(struct node *root, int data){
	if(root==NULL){
		return new_node(data);
	}
	if(data < root->data){
		root->left = insert(root->left, data);
	}
	if(data> root->data){
		root->right=insert(root->right, data);
	}
	return root;
}

void inOrder(struct node *root){
	if(root!=NULL){
		inOrder(root->left);
		printf("%d ",root->data);
		inOrder(root->right);
	}
}

struct node *minValueNode(struct node *root){
	struct node *current  = root;
	while(current->left!=NULL){
		current = current->left;
	}
	return current;
}

struct node *delete(struct node *root, int data){
	if (root == NULL) return root;
	struct node *temp;
	if(data < root->data){
		root->left = delete(root->left, data);
	}
	if(data > root->data){
		root->right  = delete(root->right, data);
	}
	if(data == root->data){
		if(root->right==NULL){
			temp = root->left;
			free(root->left);
			return temp;
		}
		if(root->left==NULL){
			temp = root->right;
			free(root->right);
			return temp;
		}
		temp = minValueNode(root->left);
		root->data = temp->data;
		root->right = delete(root->right, data);
	}
	return root;
}

int main(){
	struct node *root =NULL;
	root = insert(root,50);
	insert(root, 30);
	insert(root,20);
	insert(root,40);
	insert(root,70);
	insert(root,60);
	insert(root,80);
	inOrder(root);
	
	printf("\nDelete leaf node 20\t");
	root = delete(root, 20);
	inOrder(root);
	
	printf("\nDelete node with one child 30\t");
	delete(root, 30);
	inOrder(root);
	
	printf("\nDelete node with two child 50\t");
	root = delete(root, 50);
	inOrder(root);
	
	return 0;
}
