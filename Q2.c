// Write a menu-driven C program to implement a singly linked list that supports creating the list, inserting a node at the beginning, deleting a node from the end, and displaying the list. as short an precise you can
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void create(int val) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if (!head) head = newNode;
    else {
        struct Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

void insertBeginning(int val) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

void deleteEnd() {
    if (!head) return;
    if (!head->next) { free(head); head = NULL; return; }
    struct Node* temp = head;
    while (temp->next->next) temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}

void display() {
    struct Node* temp = head;
    while (temp) { printf("%d -> ", temp->data); temp = temp->next; }
    printf("NULL\n");
}

int main() {
    int choice, val;
    do {
        printf("\n1.Create 2.Insert Beginning 3.Delete End 4.Display 5.Exit\nChoice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: printf("Enter value: "); scanf("%d", &val); create(val); break;
            case 2: printf("Enter value: "); scanf("%d", &val); insertBeginning(val); break;
            case 3: deleteEnd(); break;
            case 4: display(); break;
        }
    } while(choice != 5);
    return 0;
}
