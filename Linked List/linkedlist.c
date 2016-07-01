#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

void printLL(struct node *n){
	while(n!=NULL){
		printf("%d ",n->data);
		n = n->next;
	}
}

void push(int new_data, struct node **head){
	struct node *new_node= (struct node*)malloc(sizeof(struct node));
	new_node->next=*head;
	new_node->data=new_data;
	*head = new_node;
}

void insertAfter(int position, int new_data, struct node **head){
	struct node *new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data = new_data;
	struct node *temp = *head;
	int count=0;
	while(temp!=NULL){
		count++;
		if(count==position){
			new_node->next = temp->next;
			temp->next=new_node;
			return;
		}
		temp=temp->next;
	}
}

void insertEnd(int new_data, struct node **head){
	struct node *new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=new_data;
	new_node->next=NULL;
	struct node *temp = *head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=new_node;
}

void deleteNodeElement(int data, struct node **head){
	struct node *temp = *head, *prev;
	while(temp->next!=NULL){
		prev = temp;
		temp = temp->next;
		if(temp->data==data){
			prev->next= temp->next;
			free(temp);
			return;
		}
	}
	
}

void deleteNodeKey(int key, struct node **head){
	struct node *temp = *head, *prev;
	int count=0;
	if(key==1){
		*head=temp->next;
		free(temp);
		return;
	}
	
	while(temp->next!=NULL){
		count++;
		if(count==key){
			prev->next = temp->next;
			free(temp);
			return;
		}
		prev = temp;
		temp = temp->next;
		
	}
}

void printLength(struct node *head){
	int count = 0;
	while(head->next!=NULL){
		count++;
		head = head->next;
	}
	printf("\n%d",count+1);
}

int main(){
	struct node *first = (struct node*)malloc(sizeof(struct node));
	struct node *second = (struct node*)malloc(sizeof(struct node));
	struct node *third = (struct node*)malloc(sizeof(struct node));

	first->data=1;	first->next=second;
	second->data=2;	second->next=third;
	third->data=3;	third->next=NULL;

	push(12, &first);

	insertAfter(2,45,&first);

	insertEnd(123,&first);

	deleteNodeElement(2,&first);

	deleteNodeKey(3,&first);

	printLL(first);
	
	printLength(first);

	return 0;
}
