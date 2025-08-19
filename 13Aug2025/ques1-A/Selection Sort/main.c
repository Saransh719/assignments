/*
Algorithm: Selection Sort

1. Start from the first element of the array.
2. Find the minimum element in the unsorted part of the array.
3. Swap it with the first element of the unsorted part.
4. Move the boundary of the sorted and unsorted parts one element forward.
5. Repeat steps 2-4 until the array is sorted.

Pseudocode:
for i = 0 to n-2
    min_idx = i
    for j = i+1 to n-1
        if arr[j] < arr[min_idx]
            min_idx = j
    swap arr[i] and arr[min_idx]

Time Complexity:
- Best case: O(n^2)
- Average case: O(n^2)
- Worst case: O(n^2)

Space Complexity:
- O(1) (in-place sorting)
*/

#include <stdio.h>

/*
 * Function: selectionSort
 * -----------------------
 * Performs Selection Sort on an integer array using pointers.
 *
 * Parameters:
 *   arr -> pointer to the first element of the array
 *   n   -> total number of elements in the array
 *
 * Selection Sort Algorithm:
 *   - For each pass, find the smallest element from the unsorted part of the array
 *   - Swap it with the first element of the unsorted part
 *   - Continue until the entire array is sorted
 */
void selectionSort(int *arr, int n) {
    int i, j, min_idx, temp;

    // Outer loop moves the boundary of the unsorted part
    for (i = 0; i < n - 1; i++) {
        min_idx = i; // Assume the current element is the smallest

        // Inner loop: search for the actual smallest element in the unsorted part
        for (j = i + 1; j < n; j++) {
            // Compare elements using pointer arithmetic
            if (*(arr + j) < *(arr + min_idx)) {
                min_idx = j; // Update index of minimum element
            }
        }

        // Swap only if the smallest element is not already at the correct position
        if (min_idx != i) {
            temp = *(arr + i);
            *(arr + i) = *(arr + min_idx);
            *(arr + min_idx) = temp;
        }
    }
}

/*
 * Function: printArray
 * --------------------
 * Prints all elements of an integer array using pointers.
 *
 * Parameters:
 *   arr -> pointer to the first element of the array
 *   n   -> total number of elements in the array
 */
void printArray(int *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {
        // Access array elements using pointer arithmetic
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

/*
 * Function: main
 * --------------
 * Entry point of the program.
 * Demonstrates Selection Sort on a sample array.
 */
int main() {
    // Initialize an array of integers
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate number of elements

    printf("Original array:\n");
    printArray(arr, n); // Print unsorted array

    // Perform selection sort
    selectionSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n); // Print sorted array

    return 0; // Exit program successfully
}
