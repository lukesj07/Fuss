#ifndef LINEAR_H
#define LINEAR_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int rows;
    int cols;
    double* data; // used as 1d array (wraps around at each row)
} Matrix;

Matrix* matrix_new(int rows, int cols);
void matrix_init(Matrix* mat, const double vals[]);
void free_matrix(Matrix* mat);
void free_matrices(Matrix* mats[], int count);

int matrix_is_valid(const Matrix* mat, int row, int col);
double matrix_get(const Matrix* mat, int row, int col);
void matrix_set(Matrix* mat, int row, int col, double val);
Matrix* matrix_mult(const Matrix* left, const Matrix* right);
Matrix* matrix_subtract(const Matrix* left, const Matrix* right);
Matrix* cross_mult(const Matrix* left, const Matrix* right);

void matrix_print(const Matrix* mat, const char* name);

#endif // ! LINEAR_H
