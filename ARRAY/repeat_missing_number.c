#include <stdio.h>

void findRepeatAndMissing(int arr[], int n) {
    // Step 1: Calculate the expected sum of first n natural numbers
    long long sum_n = (long long)n * (n + 1) / 2;

    // Step 2: Calculate the expected sum of squares of first n natural numbers
    long long sum_n_sq = (long long)n * (n + 1) * (2 * n + 1) / 6;

    // Step 3: Calculate the actual sum and sum of squares from the given array
    long long sum_actual = 0, sum_sq_actual = 0;

    for (int i = 0; i < n; i++) {
        sum_actual += arr[i];                   // sum of array elements
        sum_sq_actual += (long long)arr[i] * arr[i];  // sum of squares
    }

    // Step 4: Let x = repeating, y = missing
    // We know: y - x = sum_n - sum_actual
    // And: y^2 - x^2 = sum_n_sq - sum_sq_actual = (y - x)(y + x)
    long long diff = sum_n - sum_actual;              // y - x
    long long sq_diff = sum_n_sq - sum_sq_actual;     // y^2 - x^2

    long long sum_xy = sq_diff / diff;                // y + x

    // Step 5: Solve the equations:
    // y - x = diff
    // y + x = sum_xy
    // Add both: 2y = diff + sum_xy
    int missing = (int)((diff + sum_xy) / 2);         // y
    int repeating = (int)(sum_xy - missing);          // x

    // Step 6: Print the result
    printf("Repeating Number: %d\n", repeating);
    printf("Missing Number:   %d\n", missing);
}

int main() {
    // Test input: array with one number repeating and one missing
    int arr[] = {1, 2, 2, 4};  // 3 is missing, 2 is repeating
    int n = sizeof(arr) / sizeof(arr[0]);

    findRepeatAndMissing(arr, n);

    return 0;
}
// Step 1: Expected values for numbers from 1 to n
// -----------------------------------------------
// Expected sum of first n natural numbers:
// S = n(n + 1) / 2 = 4 * 5 / 2 = 10
// long long sum_n = (long long)n * (n + 1) / 2;

// Expected sum of squares of first n natural numbers:
// P = n(n + 1)(2n + 1) / 6 = 4 * 5 * 9 / 6 = 30
// long long sum_n_sq = (long long)n * (n + 1) * (2 * n + 1) / 6;

// Step 2: Actual values from given array [1, 2, 2, 4]
// --------------------------------------------------
// Actual sum:      S_actual = 1 + 2 + 2 + 4 = 9
// Actual squares:  P_actual = 1^2 + 2^2 + 2^2 + 4^2 = 1 + 4 + 4 + 16 = 25
// long long sum_actual = 0, sum_sq_actual = 0;
// for (int i = 0; i < n; i++) {
//     sum_actual += arr[i];
//     sum_sq_actual += (long long)arr[i] * arr[i];
// }

// Step 3: Form equations from differences
// ----------------------------------------
// Let:
// x = Repeating number
// y = Missing number

// Equation 1: y - x = sum_n - sum_actual = 10 - 9 = 1
// long long diff = sum_n - sum_actual;               // y - x

// Equation 2: y^2 - x^2 = sum_n_sq - sum_sq_actual = 30 - 25 = 5
// Using identity: y^2 - x^2 = (y - x)(y + x)
// → 5 = 1 * (y + x) → y + x = 5
// long long sq_diff = sum_n_sq - sum_sq_actual;      // y^2 - x^2
// long long sum_xy = sq_diff / diff;                 // y + x

// Step 4: Solve the equations
// ----------------------------
// Equation 1: y - x = 1
// Equation 2: y + x = 5
// Add both: 2y = 6 → y = 3 → x = 2
// int missing = (int)((diff + sum_xy) / 2);          // y = (y - x + y + x) / 2
// int repeating = (int)(sum_xy - missing);           // x = (y + x) - y

// Step 5: Print result
// ---------------------
// printf("Repeating Number: %d\n", repeating);  // Output: 2
// printf("Missing Number:   %d\n", missing);    // Output: 3
