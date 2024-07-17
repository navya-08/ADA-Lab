#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int* a, int* b);
void menu();
void performQuickSort();
void measureSortingTime();
int main() {
    menu();
    return 0;
}
void menu() {
    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Perform Quick Sort and Display Sorted Elements\n");
        printf("2. Display Time Taken for Sorting for n in the Range 500 to 14500\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                performQuickSort();
                break;
            case 2:
                measureSortingTime();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
void performQuickSort() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    clock_t start = clock();
    quickSort(arr, 0, n - 1);
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000.0;
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Time taken to sort: %lf milliseconds\n", time_taken);


    free(arr);
}
void measureSortingTime() {
    int increment = 500;
    for (int n = 500; n <= 14500; n += increment) {
        int* arr = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            arr[i] = rand();
        }
        clock_t start = clock();
        quickSort(arr, 0, n - 1);
        clock_t end = clock();
        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000.0;
        printf("Number of elements: %d, Time taken: %lf milliseconds\n", n, time_taken);
        free(arr);
    }
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
           int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; 
   int i = (low - 1); 
    for (int j = low; j <= high - 1; j++) {
              if (arr[j] < pivot) {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}
