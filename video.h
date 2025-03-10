#include <SDL2/SDL.h>
#include <stdio.h>

typedef struct {
    SDL_Window* window;
    SDL_Renderer* renderer;
} VideoHandler;

int video_init(VideoHandler* handler);
