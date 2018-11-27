/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "pixel.h"

#ifndef WINDOW_STRUCT
#define WINDOW_STRUCT

typedef struct s_window window_t;

struct s_picked_color {
    framebuffer_t color[2];
    sfSprite *sprite[2];
    sfTexture *texture;
};

struct s_window {
    framebuffer_t *picked_color[2];
};

#endif
