// : Implement a C program for a circular doubly linked list with functions to insert a node at
// the end and delete a node from the beginning.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* tail = NULL; // points to the last node

void insertEnd(int val) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = val;
    if (!tail) { // empty list
        newNode->next = newNode->prev = newNode;
        tail = newNode;
    } else {
        newNode->next = tail->next;
        newNode->prev = tail;
        tail->next->prev = newNode;
        tail->next = newNode;
        tail = newNode;
    }
}

void deleteBeginning() {
    if (!tail) return; // empty
    struct Node* head = tail->next;
    if (head == tail) { // single node
        free(head);
        tail = NULL;
        return;
    }
    tail->next = head->next;
    head->next->prev = tail;
    free(head);
}

void display() {
    if (!tail) { printf("List is empty\n"); return; }
    struct Node* temp = tail->next;
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
    printf("(head)\n");
}

int main() {
    int choice, val;
    do {
        printf("\n1.Insert End 2.Delete Beginning 3.Display 4.Exit\nChoice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: printf("Enter value: "); scanf("%d", &val); insertEnd(val); break;
            case 2: deleteBeginning(); break;
            case 3: display(); break;
        }
    } while(choice != 4);
    return 0;
}
