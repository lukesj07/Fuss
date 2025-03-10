#include "linear.h"
#include "video.h"
#include <SDL2/SDL_render.h>

int main() {
    // Matrix test
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

    free_matrices((Matrix*[]){mat1, mat2, result}, 3);

    // SDL Test
    VideoHandler handler = {
        .window = NULL,
        .renderer = NULL
    };

    if (video_init(&handler)) {
        video_cleanup(&handler);
        return 1;
    }

    SDL_RenderClear(handler.renderer);
    SDL_RenderPresent(handler.renderer);
    SDL_Delay(5000);
    video_cleanup(&handler);

    return 0;
}
