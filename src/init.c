/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include <SFML/Graphics.h>

sfSprite *create_image(char const *path, sfIntRect rect);

sfSprite *init(void)
{
    sfIntRect rect;
    sfSprite *sprite;

    rect.left = 0;
    rect.top = 0;
    rect.height = 200;
    rect.width = 200;
    sprite = create_image("assets/palette.png", rect);
    return (sprite);
}
