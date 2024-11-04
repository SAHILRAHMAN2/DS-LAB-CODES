#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    char items[MAX];
    int front, rear;
} CircularQueue;

void initQueue(CircularQueue *q);
int isFull(CircularQueue *q);
int isEmpty(CircularQueue *q);
void enqueue(CircularQueue *q, char value);
char dequeue(CircularQueue *q);
void displayQueue(CircularQueue *q);

void initQueue(CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(CircularQueue *q) {
    return (q->rear + 1) % MAX == q->front;
}

int isEmpty(CircularQueue *q) {
    return q->front == -1;
}

void enqueue(CircularQueue *q, char value) {
    if (isFull(q)) {
        printf("Queue Overflow! Cannot insert '%c'.\n", value);
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
    printf("Inserted '%c' into the queue.\n", value);
}

char dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! Cannot delete from the queue.\n");
        return '\0';
    }
    char value = q->items[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    printf("Deleted '%c' from the queue.\n", value);
    return value;
}

void displayQueue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Circular Queue is empty.\n");
        return;
    }
    printf("Circular Queue: ");
    int i = q->front;
    while (1) {
        printf("%c ", q->items[i]);
        if (i == q->rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    CircularQueue q;
    initQueue(&q);
    int choice;
    char value;

    do {
        printf("\nMenu:\n");
        printf("1. Insert an Element onto Circular Queue\n");
        printf("2. Delete an Element from Circular Queue\n");
        printf("3. Demonstrate Overflow and Underflow\n");
        printf("4. Display the Status of Circular Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a character to insert: ");
                scanf(" %c", &value);
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                printf("Attempting to delete from empty queue:\n");
                dequeue(&q);
                printf("Attempting to insert into full queue:\n");
                for (int i = 0; i < MAX + 1; i++) {
                    enqueue(&q, 'A' + i);
                }
                break;
            case 4:
                displayQueue(&q);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

