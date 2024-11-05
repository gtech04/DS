#include <stdio.h>
#include <stdlib.h>
struct Node {
    int coeff;         
    int exp;           
    struct Node* next;
};

struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}
void insertTerm(struct Node** poly, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    if (*poly == NULL || (*poly)->exp < exp) {
        newNode->next = *poly;
        *poly = newNode;
    } else {
        struct Node* temp = *poly;
        while (temp->next != NULL && temp->next->exp >= exp) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}
struct Node* multiplyPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    for (struct Node* p1 = poly1; p1 != NULL; p1 = p1->next) {
        for (struct Node* p2 = poly2; p2 != NULL; p2 = p2->next) {
            int coeff = p1->coeff * p2->coeff;
            int exp = p1->exp + p2->exp;
            insertTerm(&result, coeff, exp);
        }
    }
    return result;
}
void displayPolynomial(struct Node* poly) {
    struct Node* temp = poly;
    while (temp != NULL) {
        if (temp->next != NULL) {
            printf("%dx^%d + ", temp->coeff, temp->exp);
        } else {
            printf("%dx^%d", temp->coeff, temp->exp);
        }
        temp = temp->next;
    }
    printf("\n");
}
void freePolynomial(struct Node* poly) {
    struct Node* temp;
    while (poly != NULL) {
        temp = poly;
        poly = poly->next;
        free(temp);
    }
}
struct Node* readPolynomial() {
    struct Node* poly = NULL;
    int n, coeff, exp;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly, coeff, exp);
    }
    return poly;
}
int main() {
    printf("Enter the first polynomial:\n");
    struct Node* poly1 = readPolynomial();
    printf("Enter the second polynomial:\n");
    struct Node* poly2 = readPolynomial();
    struct Node* result = multiplyPolynomials(poly1, poly2);
    printf("Polynomial 1: ");
    displayPolynomial(poly1);
    printf("Polynomial 2: ");
    displayPolynomial(poly2);
    printf("Result of multiplication: ");
    displayPolynomial(result);
    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(result);
    return 0;
}
