/*
Algorithm: Generic Bubble Sort

1. Start from the first element of the array.
2. Compare the current element with the next element using a comparison function.
3. If the comparison function indicates the elements are in wrong order, swap them.
4. Repeat steps 2-3 for all elements, reducing the range by one each time (since the largest element "bubbles" to the end).
5. Repeat the process for n-1 passes or until no swaps are needed.

Pseudo Code:
procedure GenericBubbleSort(A[1..n], elementSize, compareFunction) 
    for i ← 1 to n-1 do
        swapped ← false
        for j ← 1 to n-i do
            if compareFunction(A[j], A[j+1]) > 0 then
                swap A[j] and A[j+1] using elementSize
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
- O(1) (in-place sorting, only uses temporary variable for swapping)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Generic bubble sort function
void bubbleSort(void *arr, int n, size_t elementSize, 
                int (*compare)(const void *a, const void *b)) {
    char *base = (char *)arr;
    void *temp = malloc(elementSize);
    int swapped;
    
    for (int i = 0; i < n - 1; i++) {
        swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            void *elem1 = base + j * elementSize;
            void *elem2 = base + (j + 1) * elementSize;
            
            if (compare(elem1, elem2) > 0) {
                memcpy(temp, elem1, elementSize);
                memcpy(elem1, elem2, elementSize);
                memcpy(elem2, temp, elementSize);
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
    free(temp);
}

// Comparison functions for different data types
int compareInt(const void *a, const void *b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    return (ia > ib) - (ia < ib);
}

int compareFloat(const void *a, const void *b) {
    float fa = *(const float*)a;
    float fb = *(const float*)b;
    return (fa > fb) - (fa < fb);
}

int compareChar(const void *a, const void *b) {
    char ca = *(const char*)a;
    char cb = *(const char*)b;
    return (ca > cb) - (ca < cb);
}

int compareString(const void *a, const void *b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

// Example usage
void main() {
    // Example with integers
    int intArr[] = {64, 34, 25, 12, 22, 11, 90};
    int intSize = sizeof(intArr) / sizeof(intArr[0]);
    bubbleSort(intArr, intSize, sizeof(int), compareInt);
    
    // Example with floats
    float floatArr[] = {3.14f, 2.71f, 1.41f, 1.73f};
    int floatArraySize = sizeof(floatArr) / sizeof(floatArr[0]);
    bubbleSort(floatArr, floatArraySize, sizeof(float), compareFloat);
    
    // Example with characters
    char charArr[] = {'z', 'b', 'x', 'a', 'm'};
    int charArraySize = sizeof(charArr) / sizeof(charArr[0]);
    bubbleSort(charArr, charArraySize, sizeof(char), compareChar);
    
    // Example with strings
    char *stringArr[] = {"banana", "apple", "orange", "grape"};
    int stringArraySize = sizeof(stringArr) / sizeof(stringArr[0]);
    bubbleSort(stringArr, stringArraySize, sizeof(char*), compareString);
}