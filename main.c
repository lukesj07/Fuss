#include "linear.h"

int main() {
    Matrix mat1 = newMatrix(3, 3);
    double mat1Vals[] =
        {1, 0, 0,
         0, 1, 0,
         1, 0, 1};
    initMatrix(&mat1, mat1Vals);

    Matrix mat2 = newMatrix(3, 3);
    double mat2Vals[] = 
        {1, 2, 3,
         1, 2, 3,
         0, 0, 0};
    initMatrix(&mat2, mat2Vals);

    Matrix result = mult(mat1, mat2);
    printMatrix(result, "Result");
    freeMatrices((Matrix*[]) {&mat1, &mat2, &result}, 3);
    
    return 0;
}
