#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int getMax(int arr[], int n) {
    int max = abs(arr[0]);
    for (int i = 1; i < n; i++)
        if (abs(arr[i]) > max)
            max = abs(arr[i]);
    return max;
}

void countingSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(abs(arr[i]) / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(abs(arr[i]) / exp) % 10] - 1] = arr[i];
        count[(abs(arr[i]) / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int max = getMax(arr, n);

    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[MAX];
    int n, choice;

    do {
        printf("\nMenu:\n");
        printf("1. Enter Array\n");
        printf("2. Perform Radix Sort\n");
        printf("3. Display Array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of elements: ");
                scanf("%d", &n);
                printf("Enter the elements:\n");
                for (int i = 0; i < n; i++) {
                    printf("Element %d: ", i + 1);
                    scanf("%d", &arr[i]);
                }
                break;

            case 2: {
                int pos[MAX], neg[MAX];
                int posCount = 0, negCount = 0;

                for (int i = 0; i < n; i++) {
                    if (arr[i] < 0)
                        neg[negCount++] = -arr[i]; 
                    else
                        pos[posCount++] = arr[i];
                }

                radixSort(pos, posCount);
                radixSort(neg, negCount);

                int index = 0;
                for (int i = negCount - 1; i >= 0; i--)
                    arr[index++] = -neg[i]; 
                for (int i = 0; i < posCount; i++)
                    arr[index++] = pos[i];
                
                printf("Array has been sorted using modified Radix Sort.\n");
                break;
            }

            case 3:
                printf("Current Array:\n");
                printArray(arr, n);
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
