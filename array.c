#include <stdio.h>
#include <stdlib.h>

void createArray(int **arr, int *size) {
    printf("Enter the number of elements: ");
    scanf("%d", size);
    *arr = (int *)malloc(*size * sizeof(int));
    printf("Enter %d integer elements:\n", *size);
    for (int i = 0; i < *size; i++) {
        scanf("%d", &(*arr)[i]);
    }
}

void displayArray(int *arr, int size) {
    printf("Array elements are:\n");
    for (int i = 0; i < size; i++) {
        printf("Element at index %d: %d\n", i, arr[i]);
    }
}

void insertElement(int **arr, int *size, int pos, int value) {
    if (pos < 0 || pos > *size) {
        printf("Invalid position! Please try again.\n");
        return;
    }
    *arr = (int *)realloc(*arr, (*size + 1) * sizeof(int));
    for (int i = *size; i > pos; i--) {
        (*arr)[i] = (*arr)[i - 1]; // Shift elements to the right
    }
    (*arr)[pos] = value; // Insert the new value
    (*size)++;
    printf("Element inserted successfully.\n");
}

void deleteElement(int **arr, int *size, int pos) {
    if (pos < 0 || pos >= *size) {
        printf("Invalid position! Please try again.\n");
        return;
    }
    for (int i = pos; i < *size - 1; i++) {
        (*arr)[i] = (*arr)[i + 1]; // Shift elements to the left
    }
    *arr = (int *)realloc(*arr, (*size - 1) * sizeof(int));
    (*size)--;
    printf("Element deleted successfully.\n");
}

int main() {
    int *arr = NULL;
    int size = 0;
    int choice, pos, value;

    do {
        printf("\nMenu:\n");
        printf("1. Create Array\n");
        printf("2. Display Array\n");
        printf("3. Insert Element\n");
        printf("4. Delete Element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createArray(&arr, &size);
                break;
            case 2:
                displayArray(arr, size);
                break;
            case 3:
                printf("Enter the position to insert (0 to %d): ", size);
                scanf("%d", &pos);
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insertElement(&arr, &size, pos, value);
                break;
            case 4:
                printf("Enter the position to delete (0 to %d): ", size - 1);
                scanf("%d", &pos);
                deleteElement(&arr, &size, pos);
                break;
            case 5:
                printf("Exiting the program.\n");
                free(arr); // Free allocated memory
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

