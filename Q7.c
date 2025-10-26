//  Write a C program that uses linked lists to represent two polynomials, adds them, and displays the resulting polynomial.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff, pow;
    struct Node* next;
};

struct Node* createNode(int c, int p) {
    struct Node* n = malloc(sizeof(struct Node));
    n->coeff = c;
    n->pow = p;
    n->next = NULL;
    return n;
}

void insert(struct Node** head, int c, int p) {
    struct Node* newNode = createNode(c, p);
    if (*head == NULL)
        *head = newNode;
    else {
        struct Node* temp = *head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
}

struct Node* addPoly(struct Node* p1, struct Node* p2) {
    struct Node* res = NULL;
    while (p1 || p2) {
        int c, p;
        if (!p2 || (p1 && p1->pow > p2->pow)) {
            c = p1->coeff; p = p1->pow; p1 = p1->next;
        } else if (!p1 || (p2->pow > p1->pow)) {
            c = p2->coeff; p = p2->pow; p2 = p2->next;
        } else {
            c = p1->coeff + p2->coeff; p = p1->pow;
            p1 = p1->next; p2 = p2->next;
        }
        if (c) insert(&res, c, p);
    }
    return res;
}

void display(struct Node* poly) {
    while (poly) {
        printf("%dx^%d", poly->coeff, poly->pow);
        if (poly->next) printf(" + ");
        poly = poly->next;
    }
    printf("\n");
}

int main() {
    struct Node *p1 = NULL, *p2 = NULL, *sum = NULL;

    insert(&p1, 3, 2); insert(&p1, 2, 1); insert(&p1, 1, 0);
    insert(&p2, 1, 1); insert(&p2, 2, 0);

    printf("P1: "); display(p1);
    printf("P2: "); display(p2);

    sum = addPoly(p1, p2);
    printf("Sum: "); display(sum);

    return 0;
}
