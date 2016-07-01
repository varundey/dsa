#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *prev;
	struct node *next;
};

void printList(struct node *n){
	printf("Forward direction:\t");
	struct node *last;
	while(n!=NULL){
		printf("%d ",n->data);
		last=n;
		n=n->next;
	}
	printf("\nReverse direction:\t");
	while(last!=NULL){
		printf("%d ",last->data);
		last = last->prev;
	}
}

void push(int new_data, struct node **head){
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data=new_data;
	new_node->next=*head;
	new_node->prev=NULL;
	(*head)->prev = new_node;
	*head=new_node;
}

void insertAfter(int key, int new_data, struct node **head){
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	struct node *temp = *head, *prev_node;
	new_node->data = new_data;
	int count=0;
	while(temp!=NULL){
		count++;
		if(count==key+1){
			prev_node->next=new_node;
			new_node->prev = prev_node;
			new_node->next = temp;
			temp->prev = new_node;
			return;
		}
		prev_node = temp;
		temp = temp->next;
	}
}

void insertEnd(int new_data, struct node **head){
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	struct node *temp=*head;
	new_node->data=new_data;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=new_node;
	new_node->prev=temp;
	new_node->next=NULL;
}

void deleteNodeElement(int data, struct node **head){
	struct node *temp = *head, *prev_node;
	while(temp!=NULL){
		prev_node=temp;
		temp=temp->next;
		if(temp->data==data){
			prev_node->next=temp->next;
			temp->next->prev=temp->prev;
			free(temp);
			return;
		}
	}
}

void deleteNodeKey(int key, struct node **head){
	struct node *temp = *head, *prev_node;
	int count=0;
	while(temp!=NULL){
		prev_node = temp;
		temp = temp->next;
		count++;
		if(count==key){
			prev_node->next=temp->next;
			temp->next->prev=temp->prev;
			free(temp);
			return;
		}
	}
}

int main(){
	struct node *first = (struct node*)malloc(sizeof(struct node));
	struct node *second = (struct node*)malloc(sizeof(struct node));
	struct node *third = (struct node*)malloc(sizeof(struct node));
	
	first->data=1;	first->next=second;	first->prev=NULL;
	second->data=2;	second->next=third;	second->prev=first;
	third->data=3;	third->next=NULL;	third->prev=second;
	
	push(12,&first);
	
	insertAfter(2,45,&first);
	
	insertEnd(123,&first);
	
	deleteNodeElement(3,&first);
	
	deleteNodeKey(2,&first);
	
	printList(first);
	
	return 0;
}
