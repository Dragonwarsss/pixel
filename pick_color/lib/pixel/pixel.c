/*
** EPITECH PROJECT, 2018
** CPool_Day13_2018
** File description:
** pixel.c
*/

#include "pixel.h"
#include <math.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>

framebuffer_t *create_buffer(int height, int width)
{
    framebuffer_t *buffer = malloc(sizeof(framebuffer_t));
    unsigned int buffer_size = height * width * 4;

    if (!buffer)
        return (NULL);
    buffer->pixel = malloc(sizeof(sfUint8) * buffer_size);
    for (unsigned int i = 0; i != buffer_size; i += 1)
        buffer->pixel[i] = 0;
    buffer->height = height;
    buffer->width = width;
    return (buffer);
}

framebuffer_t *set_pixel(framebuffer_t *buffer, int x, int y, sfColor const color)
{
    int pos_pixel = (y * buffer->width + x) * 4;

    buffer->pixel[pos_pixel] = color.r;
    buffer->pixel[pos_pixel + 1] = color.g;
    buffer->pixel[pos_pixel + 2] = color.b;
    buffer->pixel[pos_pixel + 3] = color.a;
    return (buffer);
}

framebuffer_t *fill_buffer(framebuffer_t *buffer, sfColor const color)
{
    int i = 0;
    int j = 0;
    int pos_pixel = (i * buffer->width + j) * 4;

    for (i = 0; i < buffer->width; i += 1)
        for (j = 0; j < buffer->height; j += 1) {
            pos_pixel = (i * buffer->width + j) * 4;
            buffer->pixel[pos_pixel] = color.r;
            buffer->pixel[pos_pixel + 1] = color.g;
            buffer->pixel[pos_pixel + 2] = color.b;
            buffer->pixel[pos_pixel + 3] = color.a;
        }
    return (buffer);
}

framebuffer_t *draw_square_buffer(framebuffer_t *buffer, int const size, sfVector2f const pos, sfColor const color)
{
    int i = pos.y;
    int j = pos.x;
    int pos_pixel = (i * buffer->width + j) * 4;

    for (; i < pos.y + size; i += 1)
        for (j = pos.x; j < pos.x + size; j += 1) {
            pos_pixel = (i * buffer->width + j) * 4;
            buffer->pixel[pos_pixel] = color.r;
            buffer->pixel[pos_pixel + 1] = color.g;
            buffer->pixel[pos_pixel + 2] = color.b;
            buffer->pixel[pos_pixel + 3] = color.a;
        }
    return (buffer);
}

framebuffer_t *draw_circle_buffer(framebuffer_t *buffer, int const size, sfVector2f const pos, sfColor const color)
{
    int i = pos.y - size;
    int j = pos.x - size;
    int pos_pixel = (i * buffer->width + j) * 4;

    for (; i <= pos.y + size; i += 1)
        for (j = pos.x - size; j <= pos.x + size; j += 1) {
            pos_pixel = (i * buffer->width + j) * 4;
            if (curr_point(pos, j, i) <= size) {
                pos_pixel = (i * buffer->width + j) * 4;
                buffer->pixel[pos_pixel] = color.r;
                buffer->pixel[pos_pixel + 1] = color.g;
                buffer->pixel[pos_pixel + 2] = color.b;
                buffer->pixel[pos_pixel + 3] = color.a;
            }
        }
    return (buffer);
}

int curr_point(sfVector2f const ref, int const x, int const y)
{
    int res = pow(x - ref.x, 2) + pow(y - ref.y, 2);

    res = sqrt(res);
    if (res < 0)
        res *= -1;
    return (res);
}
