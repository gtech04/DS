
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int deque[MAX_SIZE];
int front = -1;
int rear = -1;

void insertFront(int x) {
	if (front == -1) {
		front = 0;
		rear = 0;
		deque[front] = x;
	} else if (front == 0 && rear == MAX_SIZE - 1) {
		printf("Deque is full!\n");
	} else if (front > 0) {
		deque[--front] = x;
	}
}

void insertRear(int x) {
	if (front == -1) {
		front = 0;
		rear = 0;
		deque[rear] = x;
	} else if (front == 0 && rear == MAX_SIZE - 1) {
		printf("Deque is full!\n");
	} else if (rear < MAX_SIZE - 1) {
		deque[++rear] = x;
	}
}

int deleteFront() {
	if (front == -1) {
		printf("Deque is empty!\n");
		return -1;
	} else {
		int x = deque[front];
		if (front == rear) {
			front = -1;
			rear = -1;
		} else {
			front++;
		}
		return x;
	}
}

int deleteRear() {
	if (front == -1) {
		printf("Deque is empty!\n");
		return -1;
	} else {
		int x = deque[rear];
		if (front == rear) {
			front = -1;
			rear = -1;
		} else {
			rear--;
		}
		return x;
	}
}

void display() {
	if (front == -1) {
		printf("Deque is empty!\n");
	} else {
		printf("Deque elements are:\n");
		for (int i = front; i <= rear; i++) {
			printf("%d ", deque[i]);
		}
		printf("\n");
	}
}

int main() {
	int choice, x;
	while (1) {
		printf("1. Insert at front\n");
		printf("2. Insert at rear\n");
		printf("3. Delete from front\n");
		printf("4. Delete from rear\n");
		printf("5. Display\n");
		printf("6. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				printf("Enter element to insert at front: ");
				scanf("%d", &x);
				insertFront(x);
				break;
			case 2:
				printf("Enter element to insert at rear: ");
				scanf("%d", &x);
				insertRear(x);
				break;
			case 3:
				printf("Deleted element from front: %d\n", deleteFront());
				break;
			case 4:
				printf("Deleted element from rear: %d\n", deleteRear());
				break;
			case 5:
				display();
				break;
			case 6:
				exit(0);
			default:
				printf("Invalid choice!\n");
		}
	}
	return 0;
}