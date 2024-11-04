#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Stack {
    int items[MAX];
    int top;
} Stack;

void initStack(Stack *s);
int isFull(Stack *s);
int isEmpty(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
void displayStack(Stack *s);
int isPalindrome(int num);

void initStack(Stack *s) {
    s->top = -1; 
}

int isFull(Stack *s) {
    return s->top == MAX - 1;  
}

int isEmpty(Stack *s) {
    return s->top == -1;  
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push %d onto stack.\n", value);
    } else {
        s->items[++(s->top)] = value;  
        printf("Pushed %d onto stack.\n", value);
    }
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Cannot pop from stack.\n");
        return -1;  
    } else {
        return s->items[(s->top)--]; 
    }
}

void displayStack(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack contents (top to bottom):\n");
        for (int i = s->top; i >= 0; i--) {
            printf("%d\n", s->items[i]);  
        }
    }
}

int isPalindrome(int num) {
    Stack s;
    initStack(&s);
    int original = num;
    
    while (num > 0) {
        push(&s, num % 10);
        num /= 10;
    }

    num = original;  
    while (!isEmpty(&s)) {
        if (num % 10 != pop(&s)) {
            return 0; 
        }
        num /= 10;
    }
    return 1;  
}

int main() {
    Stack s;
    initStack(&s);
    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Push an Element onto Stack\n");
        printf("2. Pop an Element from Stack\n");
        printf("3. Check Palindrome\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter an integer to push: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                value = pop(&s);
                if (value != -1) {
                    printf("Popped %d from stack.\n", value);
                }
                break;
            case 3:
                printf("Enter an integer to check if it's a palindrome: ");
                scanf("%d", &value);
                if (isPalindrome(value)) {
                    printf("%d is a palindrome.\n", value);
                } else {
                    printf("%d is not a palindrome.\n", value);
                }
                break;
            case 4:
                displayStack(&s);
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

