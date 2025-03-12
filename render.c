#include "render.h"

double edge_function(const Matrix* a, const Matrix* b, const Matrix* c) {
    return ((matrix_get(b, 0, 0) - matrix_get(a, 0, 0)) *
        (matrix_get(c, 1, 0) - matrix_get(a, 1, 0))) -
        ((matrix_get(b, 1, 0) - matrix_get(a, 1, 0)) *
        (matrix_get(c, 0, 0) - matrix_get(a, 0, 0)));
}
