/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "sprite.h"

sprite_t *create_image(char const *path, sfIntRect *rect)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));
    sfImage *image = sfImage_createFromFile(path);

    sprite->sprite = sfSprite_create();
    sprite->texture = sfTexture_createFromImage(image, rect);
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
    sfImage_destroy(image);
    return (sprite);
}
