#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
 int data;
 struct Node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;

void enqueue(int x) {
 Node* newNode = (Node*)malloc(sizeof(Node));
 newNode->data = x;
 newNode->next = NULL;
 if (front == NULL) {
  front = newNode;
  rear = newNode;
  rear->next = front;
 } else {
  rear->next = newNode;
  rear = newNode;
  rear->next = front;
 }
}

void dequeue() {
 if (front == NULL) {
  printf("Queue is empty!\n");
 } else {
  Node* temp = front;
  if (front == rear) {
   front = NULL;
   rear = NULL;
  } else {
   front = front->next;
   rear->next = front;
  }
  free(temp);
 }
}

void display() {
 if (front == NULL) {
  printf("Queue is empty!\n");
 } else {
  Node* temp = front;
  printf("Queue elements are: ");
  while (temp->next != front) {
   printf("%d ", temp->data);
   temp = temp->next;
  }
  printf("%d\n", temp->data);
 }
}

int main() {
 int choice, x;
 while (1) {
  printf("1. Enqueue\n");
  printf("2. Dequeue\n");
  printf("3. Display\n");
  printf("4. Exit\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);
  switch (choice) {
   case 1:
    printf("Enter element to enqueue: ");
    scanf("%d", &x);
    enqueue(x);
    break;
   case 2:
    dequeue();
    break;
   case 3:
    display();
    break;
   case 4:
    exit(0);
   default:
    printf("Invalid choice!\n");
  }
 }
 return 0;
}


//OUTPUT

//1. Enqueue
//2. Dequeue
//3. Display
//4. Exit
//Enter your choice: 1
//Enter element to enqueue: 45
//1. Enqueue
//2. Dequeue
//3. Display
//4. Exit
//Enter your choice: 1
//Enter element to enqueue: 74
//1. Enqueue
//2. Dequeue
//3. Display
//4. Exit
//Enter your choice: 2
//1. Enqueue
//2. Dequeue
//3. Display
//4. Exit
//Enter your choice: 3
//Queue elements are: 74
//1. Enqueue
//2. Dequeue
//3. Display
//4. Exit
//Enter your choice: 4