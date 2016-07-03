#include <stdio.h>

int SIZE = 10;
int queue[10];
int FRONT = 0, REAR = -1;

void enqueue() {
        if (REAR == SIZE - 1) {
                printf("Queue overflow\n");
        } else {
                ++REAR;
                int data;
                printf("Enter data: ");
                scanf("%d", &data);
                queue[REAR] = data;
        }
}

void dequeue() {
        if(FRONT < 0 || FRONT > REAR) {
                printf("Queue underflow\n");
        } else {
                printf("%d was dequeued\n", queue[FRONT]);
                ++FRONT;
                if (FRONT == SIZE) {
                        FRONT = 0;
                }
        }
}

void peek() {
        printf("The first in the queue is %d\n", queue[FRONT]);
}

void display() {
        int i;
        for (i = FRONT; i <= REAR; i++) {
                printf("%d\n", queue[i]);
        }
}

int main() {
        int c;
        do {
                printf("\n1. Enqueue \n2. Dequeue \n3. Peek \n4. Display \n5.Exit \nEnter Choice: ");
                scanf("%d", &c);
                switch (c) {
                case 1: enqueue();
                        break;
                case 2: dequeue();
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
