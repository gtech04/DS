#include <stdio.h>
#include <ctype.h>

char stack[32], exp1[32];
int top = -1, i;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x) {
    if (x == '(')
        return 0;
    else if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    else if (x == '^')
        return 3;
    return 0;
}

void main() {
    char ch, x;
    printf("Enter the infix expression: ");
    scanf("%s", exp1);
    
    i = 0;
    ch = exp1[i];
    
    while (ch != '\0') {
        if (isalnum(ch)) {
            printf("%c", ch); 
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while ((x = pop()) != '(') {
                printf("%c", x);
            }
        } else {
            while (top != -1 && priority(stack[top]) >= priority(ch)) {
                printf("%c", pop());
            }
            push(ch);
        }
        ch = exp1[++i];
    }
    
    while (top != -1) {
        printf("%c", pop());
    }
}


//OUTPUT

// Enter the infix expression: (A+B/C*(D+E)-F
// ABC/DE+*+F-(