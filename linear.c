#include "linear.h"
#include <stdlib.h>

// make sure to free after done with matrix
Matrix newMatrix(int rows, int cols) {
    Matrix mat;
    mat.rows = rows;
    mat.cols = cols;
    mat.data = (double*) malloc(rows * cols * sizeof(double));
    if (mat.data == NULL) {
        return (Matrix){0, 0, NULL}; // memory allocation failure
    }
    return mat;
}

void initMatrix(Matrix* mat, const double vals[]) {
    for (int i = 0; i < mat->rows * mat->cols; i++) {
        mat->data[i] = vals[i];
    }
}

double get(Matrix mat, int row, int col) {
    return mat.data[row * mat.cols + col];
}

void set(Matrix* mat, int row, int col, double val) {
    mat->data[row * mat->cols + col] = val;
}

void freeMatrix(Matrix* mat) {
    free(mat->data);
    mat->data = NULL;
    mat->cols = 0;
    mat->rows = 0;
}

// use like freeMatrix((Matrix*[]) {&a, &b, &c}, 3);
void freeMatrices(Matrix* mats[], int count) {
    for (int i = 0; i < count; i++) {
        free(mats[i]->data);
        mats[i]->data = NULL;
        mats[i]->cols = 0;
        mats[i]->rows = 0;
    }
}

// make sure to free result after done.
// if error occurs, will return null matrix (rows/cols = 0, data = NULL)
Matrix mult(Matrix left, Matrix right) {
    if (right.rows != left.cols || left.data == NULL || right.data == NULL) {
        return (Matrix){0, 0, NULL}; // return null struct if invalid multiplication
    }

    Matrix result = newMatrix(left.rows, right.cols);
    if (result.data == NULL) {
        return (Matrix){0, 0, NULL}; // memory allocation failed
    }

    for (int row = 0; row < result.rows; row++) {
        for (int col = 0; col < result.cols; col++) {
            double element = 0;
            for (int pair = 0; pair < left.cols; pair++) { // pair of corrosponding elements in matrices
                element += get(left, row, pair) * get(right, pair, col);
            }
            set(&result, row, col, element);
        }
    }
    return result;
}

#include <stdio.h>
// FOR TESTING
void printMatrix(Matrix mat, const char* name) {
    if (mat.data == NULL || mat.rows == 0 || mat.cols == 0) {
        printf("%s: [NULL/INVALID MATRIX]\n", name);
        return;
    }
    
    printf("%s: %dx%d matrix\n", name, mat.rows, mat.cols);

    for (int i = 0; i < mat.rows; i++) {
        printf("  [");
        for (int j = 0; j < mat.cols; j++) {
            double value = mat.data[i * mat.cols + j];
            if (j == mat.cols - 1) {
                printf("%7.3f", value);
            } else {
                printf("%7.3f, ", value);
            }
        }
        printf("]\n");
    }
}
