#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

void createSLL();
void insertAtBeginning(int data);
void insertAtLast(int data);
void insertAtRandom(int data, int position);
void deleteFromBeginning();
void deleteFromLast();
void deleteAfterPosition(int position);
void searchElement(int data);
void showList();
void freeList();

int main() {
    int choice, data, position;

    do {
        printf("\nMenu:\n");
        printf("1. Create SLL\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at Last\n");
        printf("4. Insert at Random Location\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from Last\n");
        printf("7. Delete Node After Specified Location\n");
        printf("8. Search for an Element\n");
        printf("9. Show List\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createSLL();
                break;
            case 2:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 3:
                printf("Enter data to insert at last: ");
                scanf("%d", &data);
                insertAtLast(data);
                break;
            case 4:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                insertAtRandom(data, position);
                break;
            case 5:
                deleteFromBeginning();
                break;
            case 6:
                deleteFromLast();
                break;
            case 7:
                printf("Enter position after which to delete: ");
                scanf("%d", &position);
                deleteAfterPosition(position);
                break;
            case 8:
                printf("Enter element to search for: ");
                scanf("%d", &data);
                searchElement(data);
                break;
            case 9:
                showList();
                break;
            case 10:
                freeList();
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 10);

    return 0;
}

void createSLL() {
    int data;
    printf("Enter data for the first node: ");
    scanf("%d", &data);
    head = (Node*)malloc(sizeof(Node));
    head->data = data;
    head->next = NULL;
    printf("SLL created with first node having data %d.\n", data);
}

void insertAtBeginning(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    printf("Inserted %d at the beginning.\n", data);
}

void insertAtLast(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Inserted %d at the last.\n", data);
}

void insertAtRandom(int data, int position) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (position == 0) {
        newNode->next = head;
        head = newNode;
        printf("Inserted %d at position %d.\n", data, position);
        return;
    }

    Node* temp = head;
    for (int i = 0; i < position - 1; i++) {
        if (temp == NULL) {
            printf("Position out of bounds.\n");
            free(newNode);
            return;
        }
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d at position %d.\n", data, position);
}

void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    Node* temp = head;
    head = head->next;
    free(temp);
    printf("Deleted node from beginning.\n");
}

void deleteFromLast() {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Deleted node from last.\n");
        return;
    }

    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    printf("Deleted node from last.\n");
}

void deleteAfterPosition(int position) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    Node* temp = head;
    for (int i = 0; i < position; i++) {
        if (temp == NULL) {
            printf("Position out of bounds.\n");
            return;
        }
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("No node to delete after the specified position.\n");
        return;
    }

    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
    printf("Deleted node after position %d.\n", position);
}

void searchElement(int data) {
    Node* temp = head;
    int position = 0;
    while (temp != NULL) {
        if (temp->data == data) {
            printf("Element %d found at position %d.\n", data, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Element %d not found in the list.\n", data);
}

void showList() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    Node* temp = head;
    printf("Singly Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void freeList() {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

