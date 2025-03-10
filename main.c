#include "linear.h"

int main() {
    Matrix* mat1 = matrix_new(3, 3);
    double mat1vals[] = {
        1, 0, 0,
        0, 1, 0,
        1, 0, 1
    };
    matrix_init(mat1, mat1vals);

    Matrix* mat2 = matrix_new(3, 3);
    double mat2vals[] = {
        1, 2, 3,
        1, 2, 3,
        0, 0, 0
    };
    matrix_init(mat2, mat2vals);

    Matrix* result = matrix_mult(mat1, mat2);
    matrix_print(result, "Result");
    return 0;
}
