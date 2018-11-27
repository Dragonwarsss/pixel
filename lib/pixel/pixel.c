/*
** EPITECH PROJECT, 2018
** CPool_Day13_2018
** File description:
** pixel.c
*/

#include "pixel.h"
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

framebuffer_t *set_pixel(framebuffer_t *buffer, int x, int y, sfColor color)
{
    int pos_pixel = (y * buffer->width + x) * 4;

    buffer->pixel[pos_pixel] = color.r;
    buffer->pixel[pos_pixel + 1] = color.g;
    buffer->pixel[pos_pixel + 2] = color.b;
    buffer->pixel[pos_pixel + 3] = color.a;
    return (buffer);
}
