

#include <stdio.h>
#include <stdlib.h>

// Define a struct to represent a polynomial term
typedef struct Node {
	int coefficient;
	int exponent;
	struct Node* next;
} Node;

// Function to add two polynomials
void addPolynomials(Node* poly1, Node* poly2, Node** result) {
	Node* temp1 = poly1;
	Node* temp2 = poly2;
	while (temp1 != NULL && temp2 != NULL) {
		if (temp1->exponent == temp2->exponent) {
			Node* newNode = (Node*)malloc(sizeof(Node));
			newNode->coefficient = temp1->coefficient + temp2->coefficient;
			newNode->exponent = temp1->exponent;
			newNode->next = (*result);
			(*result) = newNode;
			temp1 = temp1->next;
			temp2 = temp2->next;
		} else if (temp1->exponent > temp2->exponent) {
			Node* newNode = (Node*)malloc(sizeof(Node));
			newNode->coefficient = temp1->coefficient;
			newNode->exponent = temp1->exponent;
			newNode->next = (*result);
			(*result) = newNode;
			temp1 = temp1->next;
		} else {
			Node* newNode = (Node*)malloc(sizeof(Node));
			newNode->coefficient = temp2->coefficient;
			newNode->exponent = temp2->exponent;
			newNode->next = (*result);
			(*result) = newNode;
			temp2 = temp2->next;
		}
	}
	while (temp1 != NULL) {
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->coefficient = temp1->coefficient;
		newNode->exponent = temp1->exponent;
		newNode->next = (*result);
		(*result) = newNode;
		temp1 = temp1->next;
	}
	while (temp2 != NULL) {
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->coefficient = temp2->coefficient;
		newNode->exponent = temp2->exponent;
		newNode->next = (*result);
		(*result) = newNode;
		temp2 = temp2->next;
	}
}

int main() {
	Node* poly1 = NULL;
	Node* poly2 = NULL;
	Node* result = NULL;
	int n1, n2;
	printf("Enter number of terms in first polynomial: ");
	scanf("%d", &n1);
	for (int i = 0; i < n1; i++) {
		Node* newNode = (Node*)malloc(sizeof(Node));
		printf("Enter coefficient and exponent for term %d: ", i + 1);
		scanf("%d %d", &newNode->coefficient, &newNode->exponent);
		newNode->next = poly1;
		poly1 = newNode;
	}
	printf("Enter number of terms in second polynomial: ");
	scanf("%d", &n2);
	for (int i = 0; i < n2; i++) {
		Node* newNode = (Node*)malloc(sizeof(Node));
		printf("Enter coefficient and exponent for term %d: ", i + 1);
		scanf("%d %d", &newNode->coefficient, &newNode->exponent);
		newNode->next = poly2;
		poly2 = newNode;
	}
	addPolynomials(poly1, poly2, &result);
	printf("Resultant polynomial: ");
	while (result != NULL) {
		printf("%dx^%d + ", result->coefficient, result->exponent);
		result = result->next;
	}
	return 0;
}