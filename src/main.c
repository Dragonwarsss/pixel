/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "pixel.h"
#include "sprite.h"
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>

//framebuffer_t *draw_palette(framebuffer_t *buffer);
//sfColor change_color(sfColor color);
sfSprite *init(void);

void event_handler(sfEvent *event, sfRenderWindow *window)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(window);
}

int main(void)
{
    sfRenderWindow *window;
    sfVideoMode mode = {800, 600, 32};
    sfEvent event;
    framebuffer_t *buffer;
    sfTexture *texture = sfTexture_create(mode.width, mode.height);
    sfSprite *sprite = sfSprite_create();
    sprite_t *test = init();

    buffer = create_buffer(mode.height, mode.width);
    for (int i = 0; i != 600; i += 1)
        buffer = set_pixel(buffer, i, i, sfRed);
    buffer = draw_palette(buffer);
    window = sfRenderWindow_create(mode, "window", sfDefaultStyle, NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfTexture_updateFromPixels(texture, buffer->pixel, mode.width, mode.height, 0, 0);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
        while (sfRenderWindow_pollEvent(window, &event))
            event_handler(&event, window);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_drawSprite(window, test->sprite, NULL);
    }
    free(buffer->pixel);
    free(buffer);
    sfSprite_destroy(test->sprite);
    sfTexture_destroy(test->texture);
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    free(test);
    sfRenderWindow_destroy(window);
}
