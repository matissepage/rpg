/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** display_button.c
*/

#include "rpg.h"

void display_button_atk(game_t *game)
{
    for (int i = 0; i < 4; i++)
        SRWDS(game->window.window, game->obj.fight.buttonatk[i].sprite, NULL);
}

void display_bg_button(game_t *game)
{
    SRWDS(game->window.window, game->obj.fight.bg_button[0].sprite, NULL);
    SRWDS(game->window.window, game->obj.fight.bg_button[1].sprite, NULL);
}