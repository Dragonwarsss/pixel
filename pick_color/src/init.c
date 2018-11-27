/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "window.h"
#include "pixel.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

window_t *init(void)
{
    window_t *window = malloc(sizeof(window));

    if (!window)
        return (NULL);
    window->picked_color[0] = create_buffer(50, 25);
}
