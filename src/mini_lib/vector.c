/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** vector.c
*/

#include "rpg.h"

int test_hitbox(sfVector2f pos, sfVector2f posobject, int w, int h)
{
    int enter_compteur = 0;
    if (pos.x >= posobject.x)
        enter_compteur++;
    if (pos.x <= posobject.x + w)
        enter_compteur++;
    if (pos.y >= posobject.y)
        enter_compteur++;
    if (pos.y <= posobject.y + h)
        enter_compteur++;
    if (enter_compteur == 4)
        return 1;
    return 0;
}

sfVector2f init_vector(int x, int y)
{
    sfVector2f buff;

    buff.x = x;
    buff.y = y;

    return (buff);
}

float getpourcentage_x(game_t *game, float pourcentage)
{
    float x = game->window.size_window.x;
    float res = x * pourcentage;
    return (res / 100);
}

float getpourcentage_y(game_t *game, float pourcentage)
{
    float y = game->window.size_window.y;
    float res = y * pourcentage;
    return (res / 100);
}