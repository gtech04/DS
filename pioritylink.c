#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
 int data;
 int priority;
 struct Node* next;
} Node;
Node* front = NULL;
void insert(int x, int priority) {
 Node* newNode = (Node*)malloc(sizeof(Node));
 newNode->data = x;
 newNode->priority = priority;
 newNode->next = NULL;
 if (front == NULL || front->priority < priority) {
  newNode->next = front;
  front = newNode;
 } else {
  Node* temp = front;
  while (temp->next != NULL && temp->next->priority > priority) {
   temp = temp->next;
  }
  newNode->next = temp->next;
  temp->next = newNode;
 }
}

void delete() {
 if (front == NULL) {
  printf("Priority Queue is empty!\n");
 } else {
  Node* temp = front;
  front = front->next;
  free(temp);
 }
}

void display() {
 if (front == NULL) {
  printf("Priority Queue is empty!\n");
 } else {
  Node* temp = front;
  while (temp != NULL) {
   printf("%d (%d) ", temp->data, temp->priority);
   temp = temp->next;
  }
  printf("\n");
 }
}

int main() {
 int choice, x, priority;
 while (1) {
  printf("1. Insert\n");
  printf("2. Delete\n");
  printf("3. Display\n");
  printf("4. Exit\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);
  switch (choice) {
   case 1:
    printf("Enter data and priority: ");
    scanf("%d %d", &x, &priority);
    insert(x, priority);
    break;
   case 2:
    delete();
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

//1. Insert
//2. Delete
//3. Display
//4. Exit
//Enter your choice: 1
//Enter data and priority: 45  5
//1. Insert
//2. Delete
//3. Display
//4. Exit
//Enter your choice: 1
//Enter data and priority: 74
//8
//1. Insert
//2. Delete
//3. Display
//4. Exit
//Enter your choice: 2
//1. Insert
//2. Delete
//3. Display
//4. Exit
//Enter your choice: 3
//45 (5) 
//1. Insert
//2. Delete
//3. Display
//4. Exit
//Enter your choice: 4