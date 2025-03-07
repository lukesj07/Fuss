#ifndef LINEAR_H
#define LINEAR_H

typedef struct {
    int rows;
    int cols;
    double* data; // used as 1d array (wraps around at each row)
} Matrix;

Matrix newMatrix(int rows, int cols);
void initMatrix(Matrix* mat, const double vals[]);
double get(Matrix mat, int row, int col);
void set(Matrix* mat, int row, int col, double val);
void freeMatrix(Matrix* mat);
void freeMatrices(Matrix* mats[], int count);
Matrix mult(Matrix left, Matrix right);

void printMatrix(Matrix mat, const char* name);

#endif
