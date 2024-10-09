
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if character is operator
int isOperator(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
		return 1;
	else
		return 0;
}

// Function to check operator precedence
int precedence(char op) {
	if (op == '+' || op == '-')
		return 1;
	else if (op == '*' || op == '/')
		return 2;
	else if (op == '^')
		return 3;
	else
		return 0;
}

// Function to convert infix to prefix
void infixToPrefix(char infix[], char prefix[]) {
	char stack[20];
	int top = -1;
	int i = 0, j = 0;
	strrev(infix);
	while (infix[i] != '\0') {
		if (isOperator(infix[i])) {
			while (top != -1 && isOperator(stack[top]) && precedence(stack[top]) > precedence(infix[i])) {
				prefix[j++] = stack[top--];
			}
			stack[++top] = infix[i++];
		} else {
			prefix[j++] = infix[i++];
		}
	}
	while (top != -1) {
		prefix[j++] = stack[top--];
	}
	prefix[j] = '\0';
	strrev(prefix);
}

int main() {
	char infix[20];
	char prefix[20];
	printf("Enter infix expression: ");
	scanf("%s", infix);
	infixToPrefix(infix, prefix);
	printf("Prefix expression: %s\n", prefix);
	return 0;
}