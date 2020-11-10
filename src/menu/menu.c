/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** menu.c
*/

#include "rpg.h"

void drawsprite_menu(game_t *g);

void menu(game_t *game)
{
    move_background(game);
    check_click(game);

    for (int index = 0; index != PARTICLE_MAX; index++) {
        update_particle(&game->screen.particle_environment, \
        &game->screen.particle[index]);
    }

    for (int i = 0; i < 4; i++) {
        is_mouse_on_btn(game, btn_s, btn_r);
    }
    drawsprite_menu(game);
}