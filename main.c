#include "geometry.h"
#include "linear.h"
#include "video.h"
#include <math.h>

int main() {
    Matrix* coord_vecs[8];
    for (int i = 0; i < 8; i++) {
        const double coord[] = {i & 1, i & 2, i & 4};
        coord_vecs[i] = matrix_new(3, 1);
        matrix_init(coord_vecs[i], coord);
    }

    const int triangle_indices[][3] = {
        // south
        {0, 2, 3}, {0, 3, 1},
        // east
        {1, 3, 7}, {1, 7, 5},
        // north
        {5, 7, 6}, {5, 6, 4},
        // wes
        {4, 6, 2}, {4, 2, 0},
        // top
        {2, 6, 7}, {2, 7, 3},
        // bottom
        {1, 5, 4}, {1, 4, 0}
    };
    
    Mesh* cube_mesh = mesh_new(12);
    for (int i = 0; i < cube_mesh->num_triangles; i++) {
        Matrix* vertices[3];
        for (int j = 0; j < 3; j++) {
            vertices[j] = coord_vecs[triangle_indices[i][j]];
        }
        Triangle* tri = triangle_new(vertices[0], vertices[1], vertices[2]);
        mesh_set(cube_mesh, i, tri);
        free(tri); // triangle gets copied so must be freed
    }



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

    free_mesh(cube_mesh);
    free_matrices(coord_vecs, 8);
    video_cleanup(&handler);
    return 0;
}

// TODO: make projection matrix and draw
