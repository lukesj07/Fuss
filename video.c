#include "video.h"

int video_init(VideoHandler* handler) {
    if (SDL_Init(SDL_INIT_VIDEO)) {
        fprintf(stderr, "Error initializing SDL: %s\n", SDL_GetError());
        return 1;
    }
}
