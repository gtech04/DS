#include<stdio.h>
#include<ctype.h>
#include<string.h>
int s[20];
int top=-1;
void push(char x);
int pop();
void push(char x)
{
s[++top]=x;
}
int pop()
{
return s[top--];
}
int main()
{
char exp[20],*e;
int y,a,b,r;
printf("Enter the string:"); scanf("%s",exp);
e=exp; while(*e!='\0') {
if(isdigit(*e)) {
y=*e-48; push(y);
}
else
{
a=pop();
b=pop();
}
switch (*e) {
case '+': {
r=b+a; push(r); break; }
case '-': {
r=b-a; push(r); break;}
case '*':
{
r=a*b;
push(r);
break;
}
case '/':
{
r=a/b;
push(r);
break;
}
case '^':
{
r=a^b;
push(r);
break;
}
}
e++;
}
printf("The result is %d ",pop()); return(0);
}

//OUTPUT

// Enter the string:53+7*
// The result is 56 