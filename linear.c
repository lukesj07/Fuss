#include "linear.h"

// creates a row-major matrix struct.
// make sure to free after done with matrix.
// returns null matrix struct if error.
Matrix* matrix_new(int rows, int cols) {
    Matrix* mat = (Matrix*)malloc(sizeof(Matrix));
    if (mat == NULL) {
        fprintf(stderr, "Error allocating memory for matrix struct\n");
        return NULL;
    }
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (double*) malloc(rows * cols * sizeof(double));
    if (mat->data == NULL) {
        fprintf(stderr, "Error allocating memory for matrix data\n");
        free(mat);
        return NULL;
    }
    return mat;
}

// ensure that vals[] matches the size of the matrix.
void matrix_init(Matrix* mat, const double vals[]) {
    if (!matrix_is_valid(mat, 0, 0) || vals == NULL) {
        return;
    }

    for (int i = 0; i < mat->rows * mat->cols; i++) {
        mat->data[i] = vals[i];
    }
}

// set pointer to null after using.
void free_matrix(Matrix* mat) {
    if (mat == NULL) {
        return;
    }

    free(mat->data);
    free(mat);
}

// eg. matrix_free((Matrix*[]) {a, b, c}, 3);
void free_matrices(Matrix* mats[], int count) {
    for (int i = 0; i < count; i++) {
        free_matrix(mats[i]);
        mats[i] = NULL;
    }
}

// checks if matrix/data is null and if is in bounds.
// 1 = true, 0 = false
int matrix_is_valid(const Matrix* mat, int row, int col) {
    if (mat == NULL || mat->data == NULL) {
        fprintf(stderr, "Error: NULL matrix or data\n");
        return 0;
    }
    
    if (row < 0 || row >= mat->rows || col < 0 || col >= mat->cols) {
        fprintf(stderr, "Error: Index out of bounds. (%d,%d) in %dx%d matrix\n", 
                row, col, mat->rows, mat->cols);
        return 0;
    }

    return 1;
}

double matrix_get(const Matrix* mat, int row, int col) {
    if (!matrix_is_valid(mat, row, col)) {
        return 0.0;
    }

    return mat->data[row * mat->cols + col];
}

void matrix_set(Matrix* mat, int row, int col, double val) {
    if (!matrix_is_valid(mat, row, col)) {
        return;
    }

    mat->data[row * mat->cols + col] = val;
}


// make sure to free result after done.
// returns null matrix struct if error.
Matrix* matrix_mult(const Matrix* left, const Matrix* right) {
    if (!matrix_is_valid(left, 0, 0) || !matrix_is_valid(right, 0, 0)) {
        return NULL;
    }

    if (right->rows != left->cols) {
        fprintf(stderr, "Invalid sizes during matrix multiplication: %dx%d * %dx%d\n",
                left->rows, left->cols, right->rows, right->cols);
        return NULL;
    }

    Matrix* result = matrix_new(left->rows, right->cols);

    for (int row = 0; row < result->rows; row++) {
        for (int col = 0; col < result->cols; col++) {
            double element = 0;
            for (int pair = 0; pair < right->rows; pair++) { // pair of corresponding elements in matrices
                element += matrix_get(left, row, pair) * matrix_get(right, pair, col);
            }
            matrix_set(result, row, col, element);
        }
    }
    return result;
}

void matrix_print(const Matrix* mat, const char* name) {
    if (mat == NULL || mat->data == NULL || mat->rows == 0 || mat->cols == 0) {
        printf("%s: [NULL/INVALID MATRIX]\n", name);
        return;
    }
    
    printf("%s: %dx%d matrix\n", name, mat->rows, mat->cols);

    for (int i = 0; i < mat->rows; i++) {
        printf("  [");
        for (int j = 0; j < mat->cols; j++) {
            double value = mat->data[i * mat->cols + j];
            if (j == mat->cols - 1) {
                printf("%7.3f", value);
            } else {
                printf("%7.3f, ", value);
            }
        }
        printf("]\n");
    }
}

// TODO: add cross (and maybe dot) product function
