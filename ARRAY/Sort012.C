// Given an array consisting of only 0s, 1s, and 2s, sort it in-place (without using any sorting algorithm) in linear time and constant space.


#include <stdio.h>

// Function to sort 0s, 1s, and 2s in-place
void sort012(int arr[], int n) {
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
        switch (arr[mid]) {
            case 0:
                // Swap arr[low] and arr[mid]
                {
                    int temp = arr[low];
                    arr[low] = arr[mid];
                    arr[mid] = temp;
                    low++;
                    mid++;
                }
                break;

            case 1:
                mid++;
                break;

            case 2:
                // Swap arr[mid] and arr[high]
                {
                    int temp = arr[mid];
                    arr[mid] = arr[high];
                    arr[high] = temp;
                    high--;
                }
                break;
        }
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function
int main() {
    int arr[] = {2, 0, 2, 1, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    sort012(arr, n);

    printf("Sorted array:   ");
    printArray(arr, n);

    return 0;
}


// ❌ Brute Force Approach (Not optimal)
// Count number of 0s, 1s, and 2s.

// Overwrite the array with counted values.

// Time Complexity: O(n)
// Space Complexity: O(1)
// But not optimal in interviews because it uses multiple passes.

// ✅ Optimal Approach: Dutch National Flag Algorithm
// We use 3 pointers:

// low → boundary of 0s

// mid → current element

// high → boundary of 2s

// 🔁 Logic:
// If arr[mid] == 0: Swap with arr[low], then low++ and mid++

// If arr[mid] == 1: Just mid++

// If arr[mid] == 2: Swap with arr[high], then high-- (don’t move mid)