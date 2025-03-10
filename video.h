#ifndef VIDEO_H
#define VIDEO_H

#include <SDL2/SDL.h>
#include <stdio.h>

#define WINDOW_TITLE "Window"
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

typedef struct {
    SDL_Window* window;
    SDL_Renderer* renderer;
} VideoHandler;

int video_init(VideoHandler* handler);
void video_cleanup(VideoHandler* handler);

#endif // ! VIDEO_H
