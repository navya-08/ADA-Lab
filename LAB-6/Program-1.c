#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void merge_sort(int arr[], int low, int high);
void merge(int arr[], int low, int mid, int high);
int main() {
    int n, i;
    clock_t start, end;
    double cpu_time_used;
    int sizes[] = {100, 1000, 5000, 10000}; 
    for (i = 0; i < sizeof(sizes) / sizeof(sizes[0]); i++) {
        n = sizes[i];
        int arr[n];
        for (int j = 0; j < n; j++) {
            arr[j] = rand() % 10000; // Generate random numbers between 0 and 9999
        }
        start = clock();
        merge_sort(arr, 0, n - 1);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Time taken to sort array of size %d: %f seconds\n", n, cpu_time_used);
    }

    return 0;
}
void merge_sort(int arr[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}
void merge(int arr[], int low, int mid, int high) {
    int left_len = mid - low + 1;
    int right_len = high - mid;
    int left[left_len], right[right_len];
    for (int i = 0; i < left_len; i++)
        left[i] = arr[low + i];
    for (int j = 0; j < right_len; j++)
        right[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = low;
    while (i < left_len && j < right_len) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < left_len) {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < right_len) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

