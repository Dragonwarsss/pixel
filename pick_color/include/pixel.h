/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include <SFML/Graphics.h>

#ifndef PIXEL_HEADER
#define PIXEL_HEADER

typedef struct s_framebuffer {
    int height;
    int width;
    sfUint8 *pixel;
} framebuffer_t;

framebuffer_t *create_buffer(int, int);
framebuffer_t *set_pixel(framebuffer_t *buffer, int, int, sfColor const color);
framebuffer_t *fill_buffer(framebuffer_t *buffer, sfColor const color);

framebuffer_t *draw_square_buffer(framebuffer_t *buffer, int const size, sfVector2f const pos, sfColor const color);
framebuffer_t *draw_circle_buffer(framebuffer_t *buffer, int const size, sfVector2f const pos, sfColor const color);

int curr_point(sfVector2f const ref, int const x, int const y);

int my_pow(int nb, int p);
int my_sqrt(int nb);

#endif
