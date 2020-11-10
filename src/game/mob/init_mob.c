/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** init_mob
*/

#include "rpg.h"

void init_mob_map1(game_t *g)
{
    init_sprite_game(MOB_F, initrect(0, 0, 160 / 2, 256 / 2), &g->obj.mob[0]);
    g->obj.mob[0].vector = g->player.player.skin_v;
    sfSprite_setPosition(g->obj.mob[0].sprite, g->obj.mob[0].vector);
}

void draw_mob(game_t *game)
{
    D(W_g, game->obj.mob[0].sprite, NULL);
}