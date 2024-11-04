#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

typedef struct {
    int items[MAX];
    int top;
} Stack;

void initStack(Stack *s);
int isFull(Stack *s);
int isEmpty(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
int evaluatePostfix(const char *expression);
void towerOfHanoi(int n, char source, char target, char auxiliary);

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
    if (!isFull(s)) {
        s->items[++(s->top)] = value;  
    }
}

int pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[(s->top)--];  
    }
    return 0;  

int evaluatePostfix(const char *expression) {
    Stack s;
    initStack(&s);
    for (int i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) {
            push(&s, expression[i] - '0');  
        } else {
            int b = pop(&s);
            int a = pop(&s);
            switch (expression[i]) {
                case '+': push(&s, a + b); break;
                case '-': push(&s, a - b); break;
                case '*': push(&s, a * b); break;
                case '/': push(&s, a / b); break;
                case '%': push(&s, a % b); break;
                case '^': push(&s, (int)pow(a, b)); break;
            }
        }
    }
    return pop(&s);  
}


void towerOfHanoi(int n, char source, char target, char auxiliary) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, target);
        return;
    }
    towerOfHanoi(n - 1, source, auxiliary, target);
    printf("Move disk %d from %c to %c\n", n, source, target);
    towerOfHanoi(n - 1, auxiliary, target, source);
}

int main() {
    int choice;
    char postfix[MAX];
    int n;

    do {
        printf("\nMenu:\n");
        printf("1. Evaluate Suffix Expression\n");
        printf("2. Solve Tower of Hanoi\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a postfix expression (single digit operands): ");
                scanf("%s", postfix);
                printf("Result: %d\n", evaluatePostfix(postfix));
                break;
            case 2:
                printf("Enter the number of disks: ");
                scanf("%d", &n);
                printf("Tower of Hanoi solution:\n");
                towerOfHanoi(n, 'A', 'C', 'B');  
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

