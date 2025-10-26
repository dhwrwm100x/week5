// : Write a C program to implement a header linked list where the header node stores a count of the total number of elements. The program should update the count during insertion and deletion.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Header {
    int count;
    struct Node* next;
};

struct Header* head = NULL;

void createHeader() {
    head = malloc(sizeof(struct Header));
    head->count = 0;
    head->next = NULL;
}

void insert(int val) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = head->next;
    head->next = newNode;
    head->count++;
}

void delete() {
    if (head->next == NULL) {
        printf("List empty!\n");
        return;
    }
    struct Node* temp = head->next;
    head->next = temp->next;
    free(temp);
    head->count--;
}

void display() {
    struct Node* temp = head->next;
    printf("Count = %d\nList: ", head->count);
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, val;
    createHeader();
    do {
        printf("\n1.Insert 2.Delete 3.Display 4.Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Enter value: "); scanf("%d", &val); insert(val); break;
            case 2: delete(); break;
            case 3: display(); break;
        }
    } while (choice != 4);
    return 0;
}
