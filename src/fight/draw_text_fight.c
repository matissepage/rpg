/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** draw_text_fight.c
*/

#include "rpg.h"

void draw_text_clock(game_t *game)
{
    sfRenderWindow_drawText(game->window.window, game->obj.fight.gest.text_clock, NULL);
}