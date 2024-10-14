/*
Ben Haney
EECS 348 Lab 5
Lab Section: Thursday 9am
*/


#include <stdio.h>
#include <math.h>

#define SIZE 5

//Prints matrix in user friendly way
void printMatrix(int matrix[SIZE][SIZE]) {
    int i = 0;
    int j = 0;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%4d ", matrix[i][j]);

        }
        printf("\n");
    }
}

//Adds two matrices
int addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int sum[SIZE][SIZE]) {
    int i = 0;
    int j = 0;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            sum[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

//Transposes (flips rows and columns) matrix
int transposeMatrix(int matrix[SIZE][SIZE], int result[SIZE][SIZE]) {
    int i = 0;
    int j = 0;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            result[i][j] = matrix[j][i];
        }
    }
}

//Multiplies 2 matrices
int multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int product[SIZE][SIZE]) {
    int i;
    int j;
    int k;
//Initializes all values of product matrix as 0 so they can easily be added to
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            product[i][j] = 0;
        }
    }
//Performs dot products and adds values to product matrix
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            for (k = 0; k < SIZE; k++) {
                product[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

//Driver contains m1 and m2, calls functions, and prints resulting matrices
int main() {
    int m1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };

    printf("Matrix 1: \n");
    printMatrix(m1);
    printf("\n");
    printf("Matrix 2: \n");
    printMatrix(m2);
    printf("\n");

    int sum[SIZE][SIZE];
    addMatrices(m1, m2, sum);
    printf("Matrix 1 + Matrix 2: \n");
    printMatrix(sum);
    printf("\n");

    int product[SIZE][SIZE];
    printf("Product of Matrix 1 and Matrix 2: \n");
    multiplyMatrices(m1, m2, product);
    printMatrix(product);
    printf("\n");

    int transposition1[SIZE][SIZE];
    printf("transposition of Matrix 1: \n");
    transposeMatrix(m1, transposition1);
    printMatrix(transposition1);
    printf("\n");

    int transposition2[SIZE][SIZE];
    printf("transposition of Matrix 2: \n");
    transposeMatrix(m2, transposition2);
    printMatrix(transposition2);

    return 0;
}