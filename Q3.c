// Implement a C program for a circular linked list that inserts a node at the beginning and
// deletes a node from the end
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* tail = NULL; // points to the last node

void insertBeginning(int val) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = val;
    if (!tail) { // empty list
        newNode->next = newNode;
        tail = newNode;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
    }
}

void deleteEnd() {
    if (!tail) return; // empty
    if (tail->next == tail) { // single node
        free(tail);
        tail = NULL;
        return;
    }
    struct Node* temp = tail->next;
    while (temp->next != tail) temp = temp->next;
    temp->next = tail->next;
    free(tail);
    tail = temp;
}

void display() {
    if (!tail) { printf("List is empty\n"); return; }
    struct Node* temp = tail->next;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
    printf("(head)\n");
}

int main() {
    int choice, val;
    do {
        printf("\n1.Insert Beginning 2.Delete End 3.Display 4.Exit\nChoice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: printf("Enter value: "); scanf("%d", &val); insertBeginning(val); break;
            case 2: deleteEnd(); break;
            case 3: display(); break;
        }
    } while(choice != 4);
    return 0;
}
