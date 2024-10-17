#include <stdio.h>
#include <stdlib.h>

#define NODE_CAPACITY 4  // Number of elements a node can store

// Node structure
struct UnrolledNode {
    int elements[NODE_CAPACITY];  // Array to store elements
    int numElements;              // Number of elements currently in the node
    struct UnrolledNode* next;    // Pointer to the next node
};

// Unrolled Linked List structure
struct UnrolledLinkedList {
    struct UnrolledNode* head;
};

// Function to create a new node
struct UnrolledNode* createNode() {
    struct UnrolledNode* node = (struct UnrolledNode*)malloc(sizeof(struct UnrolledNode));
    node->numElements = 0;
    node->next = NULL;
    return node;
}

// Function to initialize an unrolled linked list
struct UnrolledLinkedList* createUnrolledLinkedList() {
    struct UnrolledLinkedList* list = (struct UnrolledLinkedList*)malloc(sizeof(struct UnrolledLinkedList));
    list->head = createNode();
    return list;
}

// Function to insert an element into the unrolled linked list
void insert(struct UnrolledLinkedList* list, int value) {
    struct UnrolledNode* current = list->head;
    while (current->next != NULL) {
        current = current->next;
    }
    
    if (current->numElements < NODE_CAPACITY) {
        current->elements[current->numElements] = value;
        current->numElements++;
    } else {
        struct UnrolledNode* newNode = createNode();
        newNode->elements[0] = value;
        newNode->numElements++;
        current->next = newNode;
    }
}

// Function to display the elements of the unrolled linked list
void display(struct UnrolledLinkedList* list) {
    struct UnrolledNode* current = list->head;
    while (current != NULL) {
        for (int i = 0; i < current->numElements; i++) {
            printf("%d ", current->elements[i]);
        }
        printf(" -> ");
        current = current->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate insertion and display
int main() {
    struct UnrolledLinkedList* list = createUnrolledLinkedList();
    
    insert(list, 10);
    insert(list, 20);
    insert(list, 30);
    insert(list, 40);
    insert(list, 50);  // This will cause a new node to be created

    display(list);  // Output: 10 20 30 40 -> 50 -> NULL

    return 0;
}
