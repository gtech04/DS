#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
 int data;
 struct Node* next;
 struct Node* prev;
} Node;

Node* front = NULL;
Node* rear = NULL;

void insertFront(int x) {
 Node* newNode = (Node*)malloc(sizeof(Node));
 newNode->data = x;
 newNode->next = NULL;
 newNode->prev = NULL;
 if (front == NULL) {
  front = newNode;
  rear = newNode;
 } else {
  newNode->next = front;
  front->prev = newNode;
  front = newNode;
 }
}

void insertRear(int x) {
 Node* newNode = (Node*)malloc(sizeof(Node));
 newNode->data = x;
 newNode->next = NULL;
 newNode->prev = NULL;
 if (rear == NULL) {
  front = newNode;
  rear = newNode;
 } else {
  newNode->prev = rear;
  rear->next = newNode;
  rear = newNode;
 }
}

void deleteFront() {
 if (front == NULL) {
  printf("Deque is empty!\n");
 } else {
  Node* temp = front;
  if (front == rear) {
   front = NULL;
   rear = NULL;
  } else {
   front = front->next;
   front->prev = NULL;
  }
  free(temp);
 }
}

void deleteRear() {
 if (rear == NULL) {
  printf("Deque is empty!\n");
 } else {
  Node* temp = rear;
  if (front == rear) {
   front = NULL;
   rear = NULL;
  } else {
   rear = rear->prev;
   rear->next = NULL;
  }
  free(temp);
 }
}

void display() {
 if (front == NULL) {
  printf("Deque is empty!\n");
 } else {
  Node* temp = front;
  while (temp != NULL) {
   printf("%d ", temp->data);
   temp = temp->next;
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
    deleteFront();
    break;
   case 4:
    deleteRear();
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

//OUTPUT
//1. Insert at front
//2. Insert at rear
//3. Delete from front
//4. Delete from rear
//5. Display
//6. Exit
//Enter your choice: 1
//Enter element to insert at front: 54
//1. Insert at front
//2. Insert at rear
//3. Delete from front
//4. Delete from rear
//5. Display
//6. Exit
//Enter your choice: 2
//Enter element to insert at rear: 74
//1. Insert at front
//2. Insert at rear
//3. Delete from front
//4. Delete from rear
//5. Display
//6. Exit
//Enter your choice: 1
//Enter element to insert at front: 47
//1. Insert at front
//2. Insert at rear
//3. Delete from front
//4. Delete from rear
//5. Display
//6. Exit
//Enter your choice: 2
//Enter element to insert at rear: 56
//1. Insert at front
//2. Insert at rear
//3. Delete from front
//4. Delete from rear
//5. Display
//6. Exit
//Enter your choice: 3
//1. Insert at front
//2. Insert at rear
//3. Delete from front
//4. Delete from rear
//5. Display
//6. Exit
//Enter your choice: 4
//1. Insert at front
//2. Insert at rear
//3. Delete from front
//4. Delete from rear
//5. Display
//6. Exit
//Enter your choice: 5
//54 74 
//1. Insert at front
//2. Insert at rear
//3. Delete from front
//4. Delete from rear
//5. Display
//6. Exit
//Enter your choice: 6