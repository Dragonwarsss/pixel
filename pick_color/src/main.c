/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "pixel.h"
#include "sprite.h"
#include "window.h"
#include <math.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>

window_t *init(void);

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
    sfVector2f pos = {220, 20};
    sfColor color = sfBlue;
    sfVector2f posi = {100, 100};
    sfVector2f post = {250, 250};
    sfImage *image;
    sfVector2i posx;

    framebuffer_t *picked_color = create_buffer(50, 25);
    sfSprite *color_s = sfSprite_create();
    sfTexture *texture_t = sfTexture_create(50, 25);
    picked_color = fill_buffer(picked_color, color);
    sfSprite_setTexture(color_s, texture_t, sfTrue);
    sfTexture_updateFromPixels(texture_t, picked_color->pixel, 50, 25, 0, 0);
    sfSprite_setPosition(color_s, pos);

    buffer = create_buffer(mode.height, mode.width);
    for (int i = 0; i != 600; i += 1)
        buffer = set_pixel(buffer, i, i, sfRed);
    buffer = draw_square_buffer(buffer, 300, posi, sfRed);
    buffer = draw_circle_buffer(buffer, 150, post, sfGreen);
    post = (sfVector2f) {150, 150};
    buffer = draw_square_buffer(buffer, 300, post, sfBlue);


    window = sfRenderWindow_create(mode, "window", sfDefaultStyle, NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfTexture_updateFromPixels(texture, buffer->pixel, mode.width, mode.height, 0, 0);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
        while (sfRenderWindow_pollEvent(window, &event))
            event_handler(&event, window);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_drawSprite(window, color_s, NULL);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            posx = sfMouse_getPositionRenderWindow(window);
            pos.x = posx.x;
            pos.y = posx.y;
            buffer = draw_circle_buffer(buffer, 10, pos, sfBlue);
            sfTexture_updateFromPixels(texture, buffer->pixel, mode.width, mode.height, 0, 0);
        }
    }
    image = sfImage_createFromPixels(buffer->width, buffer->height, buffer->pixel);
    sfImage_saveToFile(image, "image.png");
    free(picked_color->pixel);
    free(picked_color);
    free(buffer->pixel);
    free(buffer);
    sfSprite_destroy(color_s);
    sfTexture_destroy(texture_t);
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    sfRenderWindow_destroy(window);
}
