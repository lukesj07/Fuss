#ifndef VIDEO_H
#define VIDEO_H

#include <SDL2/SDL.h>
#include <stdio.h>

#define WINDOW_TITLE "Window"
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#define ZNEAR 0.1
#define ZFAR 1000.0
#define FOV_DEG 60.0
#define ASPECT_RATIO ((double)SCREEN_HEIGHT / (double)SCREEN_WIDTH)

typedef struct {
    SDL_Window* window;
    SDL_Renderer* renderer;
} VideoHandler;

int video_init(VideoHandler* handler);
void video_cleanup(VideoHandler* handler);

#endif // ! VIDEO_H
