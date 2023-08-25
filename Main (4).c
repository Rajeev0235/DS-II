#include <stdio.h>
#include <stdlib.h>

// Structure for a term in the polynomial
typedef struct Node {
    int coefficient, exponent;
    struct Node* next;
} Node;

// Function to create a new term
Node* createTerm(int coef, int exp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coefficient = coef;
    newNode->exponent = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a term into the polynomial
void insertTerm(Node** poly, int coef, int exp) {
    Node* newTerm = createTerm(coef, exp);
    if (*poly == NULL) {
        *poly = newTerm;
    } else {
        Node* current = *poly;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newTerm;
    }
}

// Function to multiply two polynomials
Node* multiplyPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;
    Node* current1 = poly1;
  
    while (current1 != NULL) {
        Node* current2 = poly2;
  
        while (current2 != NULL) {
            int coef = current1->coefficient * current2->coefficient;
            int exp = current1->exponent + current2->exponent;
            insertTerm(&result, coef, exp);
            current2 = current2->next;
        }
  
        current1 = current1->next;
    }
  
    return result;
}

// Function to display a polynomial
void displayPolynomial(Node* poly) {
    Node* current = poly;
  
    while (current != NULL) {
        if(current->exponent != 0) {
            printf("%dx^%d + ", current->coefficient, current->exponent);
        } else {
            printf("%d ", current->coefficient);
        }
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;
  
    // Example inputs
    insertTerm(&poly1, 2, 2);
    insertTerm(&poly1, 3, 1);
    insertTerm(&poly1, 4, 0);
  
    insertTerm(&poly2, 1, 1);
    insertTerm(&poly2, 2, 0);
  
    printf("Polynomial 1: ");
    displayPolynomial(poly1);
  
    printf("Polynomial 2: ");
    displayPolynomial(poly2);
  
    Node* product = multiplyPolynomials(poly1, poly2);
  
    printf("Product: ");
    displayPolynomial(product);
  
    return 0;
}