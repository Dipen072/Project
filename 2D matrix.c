#include <stdio.h>

// Define maximum size for matrices
#define MAX 10

// Function to input a matrix
void inputMatrix(int matrix[MAX][MAX], int rows, int cols, char name) {
    int i, j;
    printf("\nEnter elements for Matrix %c (%d x %d):\n", name, rows, cols);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Enter element %c[%d][%d]: ", name, i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[MAX][MAX], int rows, int cols, char name) {
    int i, j;
    printf("\nMatrix %c (%d x %d):\n", name, rows, cols);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%5d", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to multiply two matrices
void multiplyMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int r1, int c1, int c2) {
    int i, j, k;

    // Initialize result matrix to 0
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            result[i][j] = 0;
        }
    }

    // Matrix multiplication logic
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            for (k = 0; k < c1; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int matrixA[MAX][MAX], matrixB[MAX][MAX], result[MAX][MAX];
    int rowsA, colsA, rowsB, colsB;

    printf("=== Welcome to 2D Matrix Multiplication Program ===\n");

    // Input matrix dimensions
    printf("\nEnter the number of rows for Matrix A: ");
    scanf("%d", &rowsA);
    printf("Enter the number of columns for Matrix A: ");
    scanf("%d", &colsA);

    printf("\nEnter the number of rows for Matrix B: ");
    scanf("%d", &rowsB);
    printf("Enter the number of columns for Matrix B: ");
    scanf("%d", &colsB);

    // Validate dimensions for matrix multiplication
    if (colsA != rowsB) {
        printf("\nError: Matrix multiplication not possible.\n");
        printf("Reason: Number of columns of Matrix A must equal number of rows of Matrix B.\n");
        return 1; // End program
    }

    // Input matrices
    inputMatrix(matrixA, rowsA, colsA, 'A');
    inputMatrix(matrixB, rowsB, colsB, 'B');

    // Display entered matrices
    displayMatrix(matrixA, rowsA, colsA, 'A');
    displayMatrix(matrixB, rowsB, colsB, 'B');

    // Perform multiplication
    multiplyMatrices(matrixA, matrixB, result, rowsA, colsA, colsB);

    // Display resultant matrix
    printf("\nResultant Matrix (A x B):\n");
    displayMatrix(result, rowsA, colsB, 'R');

    printf("\n=== Program Completed Successfully ===\n");

    return 0;
}

