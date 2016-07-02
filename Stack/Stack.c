#include <stdio.h>

int MAX=5;
int stack[10];
int TOP=-1;

void push() {
        if(TOP < MAX - 1) {
                ++TOP;
                int data;
                printf("Enter Data: ");
                scanf("%d", &data);
                stack[TOP] = data;
        } else {
                printf("Stack is full\n");
        }
}

void pop() {
        if(TOP > -1) {
                printf("Popped element: %d\n", stack[TOP]);
                --TOP;
        } else {
                printf("Stack is empty\n");
        }
}

void peek() {
        printf("Top of the stack is: %d\n", stack[TOP]);
}

void display() {
        int i;
        for (i=TOP; i >= 0; i--) {
                printf("%d\n", stack[i]);
        }
}

int main() {
        int c;
        do {
                printf("\n1. Push \n2. Pop \n3. Peek \n4. Display \n5.Exit \nEnter Choice: ");
                scanf("%d", &c);
                switch (c) {
                case 1: push();
                        break;
                case 2: pop();
                        break;
                case 3: peek();
                        break;
                case 4: display();
                        break;
                case 5: break;
                default: printf("Enter a valid option\n");
                        break;
                }
        } while(c != 5);
        return 0;
}
