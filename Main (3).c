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
    struct Node* temp = *poly;
    
    if (temp == NULL) {
        *poly = createNode(coeff, exp);
        return;
    }
    
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    struct Node* newTerm = createNode(coeff, exp);
    temp->next = newTerm;
}

void addPoly(struct Node* poly1, struct Node* poly2, struct Node** result) {
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp > poly2->exp) {
            insertTerm(result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        }
        else if (poly1->exp < poly2->exp) {
            insertTerm(result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        }
        else {
            insertTerm(result, poly1->coeff + poly2->coeff, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    
    while (poly1 != NULL) {
        insertTerm(result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }
    
    while (poly2 != NULL) {
        insertTerm(result, poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }
}

void display(struct Node* poly) {
    struct Node* temp = poly;
    
    while (temp != NULL) {
        printf("%dx^%d ", temp->coeff, temp->exp);
        temp = temp->next;
        
        if (temp != NULL) {
            printf("+ ");
        }
    }
    
    printf("\n");
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* result = NULL;

    // Example: 2x^3 + 4x^2 - 3x^1 + 5
    insertTerm(&poly1, 2, 3);
    insertTerm(&poly1, 4, 2);
    insertTerm(&poly1, -3, 1);
    insertTerm(&poly1, 5, 0);
    
    // Example: 3x^2 + 2x^1 - 1
    insertTerm(&poly2, 3, 2);
    insertTerm(&poly2, 2, 1);
    insertTerm(&poly2, -1, 0);
    
    printf("Polynomial 1: ");
    display(poly1);
    
    printf("Polynomial 2: ");
    display(poly2);
    
    addPoly(poly1, poly2, &result);
    
    printf("Result: ");
    display(result);
    
    return 0;
}