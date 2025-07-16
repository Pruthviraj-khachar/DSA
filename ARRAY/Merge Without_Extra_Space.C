#include <bits/stdc++.h>
using namespace std;

// ✅ Swap only if arr1[ind1] > arr2[ind2]
void swapIfGreater(long long arr1[], long long arr2[], int ind1, int ind2) {
    if (arr1[ind1] > arr2[ind2]) {
        swap(arr1[ind1], arr2[ind2]);
    }
}

// ✅ Merge function using GAP method
void merge(long long arr1[], long long arr2[], int n, int m) {
    int len = n + m;
    int gap = (len / 2) + (len % 2); // Initial gap (ceil of len/2)

    while (gap > 0) {
        int left = 0;
        int right = left + gap;

        while (right < len) {
            // Case 1: Both pointers in arr1
            if (left < n && right < n) {
                if (arr1[left] > arr1[right]) {
                    swap(arr1[left], arr1[right]);
                }
            }

            // Case 2: left in arr1, right in arr2
            else if (left < n && right >= n) {
                if (arr1[left] > arr2[right - n]) {
                    swap(arr1[left], arr2[right - n]);
                }
            }

            // Case 3: Both pointers in arr2
            else if (left >= n && right >= n) {
                if (arr2[left - n] > arr2[right - n]) {
                    swap(arr2[left - n], arr2[right - n]);
                }
            }

            left++;
            right++;
        }

        // If gap is 1, we're done
        if (gap == 1) break;

        // Update the gap
        gap = (gap / 2) + (gap % 2);
    }
}

// ✅ Driver Code
int main() {
    long long arr1[] = {1, 4, 7, 8, 10};
    long long arr2[] = {2, 3, 9};
    int n = 5, m = 3;

    // Call the merge function
    merge(arr1, arr2, n, m);

    // Print merged arrays
    cout << "Array 1: ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }

    cout << "\nArray 2: ";
    for (int i = 0; i < m; i++) {
        cout << arr2[i] << " ";
    }

    return 0;
}

// 💡 Explanation:
// This method avoids using extra space by comparing elements at a "gap" distance.

// The gap reduces every round until it becomes 1, then stops.

// ⏱ Time Complexity:
// scss
// Copy
// Edit
// O((N+M) log(N+M)) – due to the reducing gap and scanning.
