/*
Algorithm: Insertion Sort
1. Start from the second element (index 1) of the array.
2. Compare the current element with the elements before it.
3. Shift all elements greater than the current element to one position ahead.
4. Insert the current element at its correct position.
5. Repeat steps 2-4 for all elements.

Pseudocode:
for i = 1 to n-1
    key = arr[i]
    j = i-1
    while j >= 0 and arr[j] > key
        arr[j+1] = arr[j]
        j = j-1
    arr[j+1] = key

Time Complexity:
- Best Case: O(n) (when array is already sorted)
- Average and Worst Case: O(n^2)

Space Complexity:
- O(1) (in-place sorting)
*/

#include <stdio.h>

// Function to perform insertion sort using pointers
void insertionSort(int *arr, int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = *(arr + i); // Current element to be inserted
        j = i - 1;
        // Move elements greater than key one position ahead
        while (j >= 0 && *(arr + j) > key) {
            *(arr + j + 1) = *(arr + j);
            j--;
        }
        *(arr + j + 1) = key; // Insert key at correct position
    }
}

int main() {
    int arr[100], n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    insertionSort(arr, n);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
    return 0;
}