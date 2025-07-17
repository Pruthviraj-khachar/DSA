#include <stdio.h>

// Function to set matrix zeroes in-place using constant space
void setZeroes(int matrix[][100], int rows, int cols) {
    int row0 = 0, col0 = 0;

    // Step 1: Check if first column needs to be zeroed
    for (int i = 0; i < rows; i++) {
        if (matrix[i][0] == 0) {
            col0 = 1; // Mark that first column needs to be zeroed
        }
    }

    // Step 2: Check if first row needs to be zeroed
    for (int j = 0; j < cols; j++) {
        if (matrix[0][j] == 0) {
            row0 = 1; // Mark that first row needs to be zeroed
        }
    }

    // Step 3: Use first row and first column to mark zeroes
    // For the rest of the matrix (excluding first row and column)
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0; // Mark the row
                matrix[0][j] = 0; // Mark the column
            }
        }
    }

    // Step 4: Set matrix elements to 0 based on markers in first row and column
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // Step 5: Set first row to 0 if needed
    if (row0) {
        for (int j = 0; j < cols; j++) {
            matrix[0][j] = 0;
        }
    }

    // Step 6: Set first column to 0 if needed
    if (col0) {
        for (int i = 0; i < rows; i++) {
            matrix[i][0] = 0;
        }
    }
}

// Helper function to print the matrix
void printMatrix(int matrix[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Declare and initialize a 2D matrix
    int matrix[100][100] = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    int rows = 3, cols = 3;

    // Print the original matrix
    printf("Original matrix:\n");
    printMatrix(matrix, rows, cols);

    // Call function to modify the matrix
    setZeroes(matrix, rows, cols);

    // Print the matrix after setting zeroes
    printf("\nMatrix after setting zeroes:\n");
    printMatrix(matrix, rows, cols);

    return 0;
}
