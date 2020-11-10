/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** manage_type.c
*/

#include "rpg.h"

void manage_type(game_t *game)
{
    if (game->obj.fight.ennemis.type == WATER)
        SRWDS(game->window.window, game->obj.fight.type[0].sprite, NULL);
    if (game->obj.fight.ennemis.type == FIRE)
        SRWDS(game->window.window, game->obj.fight.type[1].sprite, NULL);
    if (game->obj.fight.ennemis.type == MANA)
        SRWDS(game->window.window, game->obj.fight.type[2].sprite, NULL);
}