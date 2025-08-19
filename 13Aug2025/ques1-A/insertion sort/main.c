/*
Algorithm: Generic Insertion Sort

1. Start from the second element (index 1) of the array.
2. Store the current element as key.
3. Compare the key with elements before it using a comparison function.
4. Shift all elements greater than key one position to the right.
5. Insert the key at its correct position.
6. Repeat steps 2-5 for all elements from index 1 to n-1.

Pseudo Code:
procedure GenericInsertionSort(A[1..n], elementSize, compareFunction) 
    for i ← 2 to n do
        key ← A[i]
        j ← i - 1
        while j >= 1 and compareFunction(A[j], key) > 0 do
            A[j+1] ← A[j]
            j ← j - 1
        end while
        A[j+1] ← key
    end for
end procedure

Time Complexity:
- Best Case: O(n) (when the array is already sorted)
- Average Case: O(n^2)
- Worst Case: O(n^2) (when the array is reverse sorted)

Space Complexity:
- O(1) (in-place sorting, only uses temporary variable for key)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Generic insertion sort function
void insertionSort(void *arr, int n, size_t elementSize, 
                   int (*compare)(const void *a, const void *b)) {
    char *base = (char *)arr;
    void *key = malloc(elementSize);
    
    for (int i = 1; i < n; i++) {
        // Store current element as key
        memcpy(key, base + i * elementSize, elementSize);
        int j = i - 1;
        
        // Move elements greater than key one position ahead
        while (j >= 0 && compare(base + j * elementSize, key) > 0) {
            memcpy(base + (j + 1) * elementSize, base + j * elementSize, elementSize);
            j--;
        }
        
        // Insert key at correct position
        memcpy(base + (j + 1) * elementSize, key, elementSize);
    }
    
    free(key);
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

void main() {
    // Example with integers
    int intArr[] = {64, 34, 25, 12, 22, 11, 90};
    int intSize = sizeof(intArr) / sizeof(intArr[0]);
    insertionSort(intArr, intSize, sizeof(int), compareInt);
    
    // Example with floats
    float floatArr[] = {3.14f, 2.71f, 1.41f, 1.73f};
    int floatArraySize = sizeof(floatArr) / sizeof(floatArr[0]);
    insertionSort(floatArr, floatArraySize, sizeof(float), compareFloat);
    
    // Example with characters
    char charArr[] = {'z', 'b', 'x', 'a', 'm'};
    int charArraySize = sizeof(charArr) / sizeof(charArr[0]);
    insertionSort(charArr, charArraySize, sizeof(char), compareChar);
    
    // Example with strings
    char *stringArr[] = {"banana", "apple", "orange", "grape"};
    int stringArraySize = sizeof(stringArr) / sizeof(stringArr[0]);
    insertionSort(stringArr, stringArraySize, sizeof(char*), compareString);
}