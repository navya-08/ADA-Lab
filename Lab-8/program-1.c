#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);


    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
void measureTime(int N) {
    int *arr = (int *)malloc(N * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed\n");
        return;
    }
    srand(time(0));
    for (int i = 0; i < N; i++) {
        arr[i] = rand();
    }
    clock_t start = clock();
    heapSort(arr, N);
    clock_t end = clock();
    printf("Time to sort %d elements: %f seconds\n", N, ((double)(end - start)) / CLOCKS_PER_SEC);
    free(arr);
}
int main() {
    int choice;
    const int largeValues[] = {10000, 50000, 100000, 500000, 1000000};
    while (1) {
        printf("\nMenu:\n");
        printf("1. Sort and display array\n");
        printf("2. Measure sort times for large values\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                int N;
                printf("Enter number of elements: ");
                scanf("%d", &N);
                int *arr = (int *)malloc(N * sizeof(int));
                if (!arr) {
                    printf("Memory allocation failed\n");
                    break;
                }


                printf("Enter %d elements: ", N);
                for (int i = 0; i < N; i++) {
                    scanf("%d", &arr[i]);
                }


                printf("Unsorted array:\n");
                for (int i = 0; i < N; i++) printf("%d ", arr[i]);
                printf("\n");
                heapSort(arr, N);
                printf("Sorted array:\n");
                for (int i = 0; i < N; i++) printf("%d ", arr[i]);
                printf("\n");
                free(arr);
                break;
            }
            
case 2:


                for (int i = 0; i < sizeof(largeValues) / sizeof(largeValues[0]); i++) {
                    measureTime(largeValues[i]);
                }
                break;
            case 3:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
