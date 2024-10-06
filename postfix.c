#include<stdio.h> 
#include<ctype.h> 
char postfix[20]; 
int stack[20],top=-1,i; 
void push(int x) 
{ 
stack[++top]=x; 
} 
int pop() 
{ 
return(stack[top--]); 
} 
void main() 
{ 
int op1,op2; printf("Enter the postfix expression = "); 
scanf("%s",postfix); 
for(i=0;postfix[i]!='\0';i++) 
{ 
if(isdigit(postfix[i])) push(postfix[i]-48); else 
{ 
op2=pop(); 
op1=pop(); switch(postfix[i]) { 
case '+': push(op1+op2); break; 
case '-': 
push(op1-op2); 
break; 
case '*': push(op1*op2); 
break; 
case '/': 
push(op1/op2); 
break; 
case '^': 
push(op1^op2); 
break; 
default: 
printf("invalid"); 
} 
} 
} 
printf("%d",stack[top]); 
} 