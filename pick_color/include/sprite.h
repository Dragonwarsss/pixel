/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include <SFML/Graphics.h>

#ifndef SPRITE_STRUCT
#define SPRITE_STRUCT

typedef struct s_sprite sprite_t;

struct s_sprite {
    sfSprite *sprite;
    sfTexture *texture;
};

#endif
