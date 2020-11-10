/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** sprites.c
*/

#include "rpg.h"

sfText *create_text(char *path_font, char *str, int x, int y)
{
    sfText *text;
    sfFont *font;
    sfVector2f pos = init_vector(x, y);

    text = sfText_create();
    sfText_setString(text, str);
    font = sfFont_createFromFile(path_font);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 30);
    sfText_setPosition(text, pos);

    return (text);
}

sfSprite *create_sprite(char *path)
{
    sfSprite *sprite;
    sfTexture *texture;

    texture = sfTexture_createFromFile(path, NULL);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);

    return (sprite);
}

void move_rect(sfIntRect *rect, int offset, int max)
{
    rect->left = (rect->left + offset) % max;
}

sfIntRect initrect(int top, int left, int w, int h)
{
    sfIntRect rect;

    rect.top = top;
    rect.left = left;
    rect.width = w;
    rect.height = h;

    return (rect);
}