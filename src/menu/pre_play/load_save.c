/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** load_save.c
*/

#include "rpg.h"

void load_saverecolor2(game_t *g, int *nbr)
{
    if (nbr[2] != VALUE_NOINIT) {
        sfColor color2 = RGF(BUILD_PREPLAY.panel_color[nbr[2]]);
        sfSprite_setColor(g->player.player.hair, color2);
    }
    if (nbr[3] != VALUE_NOINIT) {
        sfColor color3 = RGF(BUILD_PREPLAY.panel_color[nbr[3]]);
        sfSprite_setColor(g->player.player.cape, color3);
    }
    if (nbr[4] != VALUE_NOINIT) {
        sfColor color4 = RGF(BUILD_PREPLAY.panel_color[nbr[4]]);
        sfSprite_setColor(g->player.player.cloth, color4);
    }
    g->obj.menu.preplay.etat_preplay = 1;
}

void load_saverecolor(game_t *g, int *nbr)
{
    if (nbr[0] != VALUE_NOINIT) {
        sfColor color = RGF(BUILD_PREPLAY.panel_color[nbr[0]]);
        sfSprite_setColor(g->player.player.eyes, color);
    }
    if (nbr[1] != VALUE_NOINIT) {
        sfColor color1 = RGF(BUILD_PREPLAY.panel_color[nbr[1]]);
        sfSprite_setColor(g->player.player.skin, color1);
    }
    load_saverecolor2(g, nbr);
}