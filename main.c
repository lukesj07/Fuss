#include "linear.h"
#include "video.h"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_scancode.h>
#include <string.h>

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

    while (1) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT:
                    video_cleanup(&handler);
                    return 0;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.scancode) {
                        case SDL_SCANCODE_ESCAPE:
                            video_cleanup(&handler);
                            return 0;
                        default:
                            break;
                        }
                default:
                    break;
            }
        }

        SDL_RenderClear(handler.renderer);
        SDL_RenderPresent(handler.renderer);
        SDL_Delay(16);
    }
}
