#include "video.h"

// returns status code. cleanup if fails
int video_init(VideoHandler* handler) {
    if (SDL_Init(SDL_INIT_VIDEO)) {
        fprintf(stderr, "Error initializing SDL: %s\n", SDL_GetError());
        return 1;
    }

    handler->window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if (handler->window == NULL) {
        fprintf(stderr, "Error creating window: %s\n", SDL_GetError());
        return 1;
    }

    handler->renderer = SDL_CreateRenderer(handler->window, -1, 0);
    if (handler->renderer == NULL) {
        fprintf(stderr, "Error creating renderer: %s\n", SDL_GetError());
        return 1;
    }

    return 0;
}

// use if error occurs and at end of program.
void video_cleanup(VideoHandler* handler) {
    SDL_DestroyRenderer(handler->renderer);
    SDL_DestroyWindow(handler->window);
    SDL_Quit();
}

// TODO: make triangle rasterizer
