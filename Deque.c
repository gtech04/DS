#include<stdio.h>
#include<stdlib.h>
#define max 5
int a[max];
int front=-1,rear=-1;

void pif(int a[]){
int item;
if(front==0&&rear==max-1){
printf("\nDeque is full\n");
}
else{
if(front==-1&&rear==-1){
front=rear=0;
printf("\nEnter element to be inserted:");
scanf("%d",&item);
a[front]=item;
}
else if(front<=0){
printf("\nInsertion not possible\n");
}
else if(front>0){
printf("\nEnter element to be inserted:");
scanf("%d",&item);
front--;
a[front]=item;
}
}
}

void pff(int a[]){
int item=0;
if(front==-1&&rear==-1){
printf("\nDeque is empty\n");
}
else{
if(front==rear){
item=a[front];
printf("\nPopped %d\n",item);
front=rear=-1;
}
else{
item=a[front];
printf("\nPopped %d\n",item);
front++;
}
}
}

void pir(int a[]){
int item;
if(front==0&&rear==max-1){
printf("\nDeque is full\n");
}
else{
if(rear>=max-1){
printf("\ninsertion not possible\n");
}
else if(rear<max-1){
printf("\nEnter number to be inserted:");
scanf("%d",&item);
rear++;
a[rear]=item;
}
}
}

void pfr(int a[]){
int item=0;
if(front==-1&&rear==-1){
printf("\nDeque is empty\n");
}
else{
if(rear==front){
item=a[rear];
printf("\nPopped %d\n",item);
front=rear=-1;
}
else{
item=a[rear];
printf("\nPopped %d\n",item);
rear--;
}
}
}

void dis(int a[]){
int i;
printf("\n[");
for(i=front;i<=rear;i++){
printf("\t%d",a[i]);
}
printf("\t]\n");
}

void main(){
int ch=0;
while(ch<6){
printf("Choose an option:\n1.Push in front\n2.Pop from front\n3.Push in rear\n4.Pop from rear\n5.Display\n6.exit\n");
scanf("%d",&ch);
switch(ch){
case 1:pif(a);
break;
case 2:pff(a);
break;
case 3:pir(a);
break;
case 4:pfr(a);
break;
case 5:dis(a);
break;
default:
exit(1);
}
}
}