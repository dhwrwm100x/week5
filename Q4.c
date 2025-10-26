// Write a C program to create a doubly linked list and implement functions to insert a node after a given node and to delete a node from the beginning
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

void insertAfter(int key, int val) {
    struct Node* temp = head;
    while (temp && temp->data != key) temp = temp->next;
    if (!temp) { printf("Key not found\n"); return; }
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next) temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteBeginning() {
    if (!head) return;
    struct Node* temp = head;
    head = head->next;
    if (head) head->prev = NULL;
    free(temp);
}

void display() {
    struct Node* temp = head;
    while (temp) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, val, key;
    do {
        printf("\n1.Insert After 2.Delete Beginning 3.Display 4.Exit\nChoice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter key and value: ");
                scanf("%d %d", &key, &val);
                insertAfter(key, val);
                break;
            case 2: deleteBeginning(); break;
            case 3: display(); break;
        }
    } while(choice != 4);
    return 0;
}
