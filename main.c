#include "linear.h"
#include "video.h"

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

    int running = 1;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT:
                    running = 0;
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.scancode) {
                        case SDL_SCANCODE_ESCAPE:
                            running = 0;
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
        }
        SDL_RenderClear(handler.renderer);
        // draw
        SDL_RenderPresent(handler.renderer);
        SDL_Delay(16);
    }

    video_cleanup(&handler);
    return 0;
}

// TODO: make projection matrix, sample mesh (rotate?), and draw
