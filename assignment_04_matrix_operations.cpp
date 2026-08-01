// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void inputMatrix(int matrix[10][10], int rows, int cols)
{
for (int i = 0; i < rows; i++)
{
for (int j = 0; j < cols; j++)
{
cin >> matrix[i][j];
}
}
}
void displayMatrix(int matrix[10][10], int rows, int cols)
{
for (int i = 0; i < rows; i++)
{
for (int j = 0; j < cols; j++)
{
cout << matrix[i][j] << " ";
}
cout << endl;
}
}
void transposeMatrix(int matrix[10][10], int rows, int cols)
{
int transpose[10][10];
for (int i = 0; i < rows; i++)
{
for (int j = 0; j < cols; j++)
{
transpose[j][i] = matrix[i][j];
}
}
cout << "Transposed Matrix:" << endl;
displayMatrix(transpose, cols, rows);
}
void addMatrices(int a[10][10], int b[10][10], int rows, int cols)
{
int sum[10][10];
for (int i = 0; i < rows; i++)
{
for (int j = 0; j < cols; j++)
{
sum[i][j] = a[i][j] + b[i][j];
}
}
cout << "Sum Matrix:" << endl;
displayMatrix(sum, rows, cols);
}
void multiplyMatrices(int a[10][10], int b[10][10], int m, int n, int p)
{
int product[10][10];
for (int i = 0; i < m; i++)
{
for (int j = 0; j < p; j++)
{
product[i][j] = 0;
for (int k = 0; k < n; k++)
{
product[i][j] += a[i][k] * b[k][j];
}
}
}
cout << "Product Matrix:" << endl;
displayMatrix(product, m, p);
}
int main()
{
int matrix[10][10];
int rows, cols;
cout << "PART A - Transpose Matrix" << endl;
cout << "Enter rows and columns: ";
cin >> rows >> cols;
cout << "Enter matrix elements:" << endl;
inputMatrix(matrix, rows, cols);
transposeMatrix(matrix, rows, cols);
int a[10][10], b[10][10];
int m, n;
cout << "\nPART B - Add Two Matrices" << endl;
cout << "Enter rows and columns: ";
cin >> m >> n;
cout << "Enter first matrix:" << endl;
inputMatrix(a, m, n);
cout << "Enter second matrix:" << endl;
inputMatrix(b, m, n);
addMatrices(a, b, m, n);
int r1, c1, r2, c2;
int matrixA[10][10], matrixB[10][10];
cout << "\nPART C - Multiply Two Matrices" << endl;
cout << "Enter rows and columns of Matrix A: ";
cin >> r1 >> c1;
cout << "Enter elements of Matrix A:" << endl;
inputMatrix(matrixA, r1, c1);
cout << "Enter rows and columns of Matrix B: ";
cin >> r2 >> c2;
if (c1 != r2)
{
cout << "Matrix multiplication not possible." << endl;
return 0;
}
cout << "Enter elements of Matrix B:" << endl;
inputMatrix(matrixB, r2, c2);
multiplyMatrices(matrixA, matrixB, r1, c1, c2);
return 0;
}
