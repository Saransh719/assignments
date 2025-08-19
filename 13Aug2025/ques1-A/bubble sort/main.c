/*
Algorithm: Bubble Sort

1. Start from the first element of the array.
2. Compare the current element with the next element.
3. If the current element is greater than the next, swap them.
4. Repeat steps 2-3 for all elements, reducing the range by one each time (since the largest element "bubbles" to the end).
5. Repeat the process for n-1 passes or until no swaps are needed.

pusedo code:
procedure BubbleSort(A[1..n]) 
    for i ← 1 to n-1 do
        swapped ← false
        for j ← 1 to n-i do
            if A[j] > A[j+1] then
                swap A[j] and A[j+1]
                swapped ← true
            end if
        end for
        if swapped = false then
            break   // No swaps means array is already sorted
        end if
    end for
end procedure

Time Complexity:
- Best Case: O(n) (when the array is already sorted, with optimization)
- Average Case: O(n^2)
- Worst Case: O(n^2)

Space Complexity:
- O(1) (in-place sorting)
*/

#include <stdio.h>

// Function to perform bubble sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = 0; // Flag to check if any swapping happened
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++) {
            // Compare adjacent elements
            if (arr[j] > arr[j + 1]) {
                // Swap if elements are in wrong order
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        // If no two elements were swapped, array is sorted
        if (swapped == 0)
            break;
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: ");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}