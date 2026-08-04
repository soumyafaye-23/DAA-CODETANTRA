/**
 * @file 1.1.1. Quick Sort.c
 * @brief Write a program to sort an array of length N using the Quick Sort algorithm.
 * @strategy Divide and Conquer
 * @complexity
 *   - Time Complexity:
 *     - Best Case: O(n log n) [Balanced partitioning]
 *     - Average Case: O(n log n)
 *     - Worst Case: O(n^2) [When the pivot partition is highly unbalanced]
 *   - Space Complexity: O(log n) [Recursion call stack depth]
 */

#include <stdio.h>
#include <stdlib.h>

// Quick Sort function using the last element as pivot (Lomuto Partition Scheme)
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        int pi = i + 1;

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print an array matching the exact CodeTantra spacing/newlines
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    // Input the size of the array
    if (scanf("%d", &n) != 1) return 1;
    
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) return 1;

    // Input the elements of the array
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            free(arr);
            return 1;
        }
    }

    // Print the original array
    printArray(arr, n);

    // Sort the array using quick sort
    quickSort(arr, 0, n - 1);
    
    // Print the sorted array
    printArray(arr, n);

    free(arr);
    return 0;
}
