#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
int data;
struct Node* next;
struct Node* prev;
}Node;
Node* front = NULL;
Node* rear = NULL;
void insertFront(){
int item;
printf("Enter data:");
scanf("%d",&item);
Node* newNode = (Node*)malloc(sizeof(Node));
newNode->data = item;
newNode->next = NULL;
newNode->prev = NULL;
if(front == NULL){
front = newNode;
rear = newNode;
}
else{
newNode->next = front;
front->prev = newNode;
front = newNode;
}
}
void insertRear(){
int item;
printf("Enter data:");
scanf("%d",&item);
Node* newNode = (Node*)malloc(sizeof(Node));
newNode->data = item;
newNode->next = NULL;
newNode->prev = NULL;
if(rear == NULL){
front = newNode;
rear = newNode;
}
else{
newNode->prev = rear;
rear->next = newNode;
rear = newNode;
}
}
void deleteFront(){
if (front == NULL){
printf("Deque is empty!\n");
}
else{
Node* temp = front;
if (front == rear){
front = NULL;
rear = NULL;
}
else{
front = front->next;
front->prev = NULL;
}
printf("Deleted:%d\n",temp->data);
free(temp);
}
}
void deleteRear(){
if(rear == NULL){
printf("Deque is empty!\n");
}
else{
Node* temp = rear;
if (front == rear) {
front = NULL;
rear = NULL;
}
else{
rear = rear->prev;
rear->next = NULL;
}
printf("Deleted:%d\n",temp->data);
free(temp);
}
}
void display(){
if(front == NULL){
printf("Deque is empty!\n");
}
else{
Node* temp = front;
while (temp != NULL) {
printf("%d ", temp->data);
temp = temp->next;
}
printf("\n");
}
}
void main(){
int ch;
while(1){
printf("1. Insert at front\n2. Insert at rear\n3. Delete from front\n4. Delete from rear\n5. Display\n6. Exit\nEnter your choice: ");
scanf("%d", &ch);
switch (ch){
case 1:insertFront();
break;
case 2:insertRear();
break;
case 3:deleteFront();
break;
case 4:deleteRear();
break;
case 5:display();
break;
case 6:exit(0);
default:printf("Invalid choice!\n");
break;
}
}
}
