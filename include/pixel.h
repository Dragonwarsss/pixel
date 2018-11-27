/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include <SFML/Graphics.h>

typedef struct s_framebuffer {
    int height;
    int width;
    sfUint8 *pixel;
} framebuffer_t;

framebuffer_t *create_buffer(int, int);
framebuffer_t *set_pixel(framebuffer_t *buffer, int, int, sfColor);
