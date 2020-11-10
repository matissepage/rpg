/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** rect plauer
*/

#include "rpg.h"

void set_top_rect(game_t *g, int top)
{
    g->player.player.skin_r.top = top;
    g->player.player.cloth_r.top = top;
    g->player.player.hair_r.top = top;
    g->player.player.cape_r.top = top;
}

void move_rect_up(game_t *g)
{
    set_top_rect(g, 64*3);
    if (g->player.player.cape_r.left > 160-96) {
        g->player.player.skin_r.left = 0;
        g->player.player.cloth_r.left = 0;
        g->player.player.hair_r.left = 0;
        g->player.player.cape_r.left = 0;
    }
    g->player.player.skin_r.left += 32;
    g->player.player.cloth_r.left += 32;
    g->player.player.hair_r.left += 32;
    g->player.player.cape_r.left += 32;
    STR(g->player.player.skin, g->player.player.skin_r);
    STR(g->player.player.cloth, g->player.player.cloth_r);
    STR(g->player.player.hair, g->player.player.hair_r);
    STR(g->player.player.cape, g->player.player.cape_r);
}

void move_rect_down(game_t *g)
{
    set_top_rect(g, 64*2);
    if (g->player.player.cape_r.left > 160-96) {
        g->player.player.skin_r.left = 0;
        g->player.player.cloth_r.left = 0;
        g->player.player.hair_r.left = 0;
        g->player.player.cape_r.left = 0;
    }
    g->player.player.skin_r.left += 32;
    g->player.player.cloth_r.left += 32;
    g->player.player.hair_r.left += 32;
    g->player.player.cape_r.left += 32;
    STR(g->player.player.skin, g->player.player.skin_r);
    STR(g->player.player.cloth, g->player.player.cloth_r);
    STR(g->player.player.hair, g->player.player.hair_r);
    STR(g->player.player.cape, g->player.player.cape_r);
}

void move_rect_left(game_t *g)
{
    set_top_rect(g, 64);
    if (g->player.player.skin_r.left < 32) {
        g->player.player.skin_r.left = 160-64;
        g->player.player.cloth_r.left = 160-64;
        g->player.player.hair_r.left = 160-64;
        g->player.player.cape_r.left = 160-64;
    }
    g->player.player.skin_r.left -= 32;
    g->player.player.cloth_r.left -= 32;
    g->player.player.hair_r.left -= 32;
    g->player.player.cape_r.left -= 32;
    STR(g->player.player.skin, g->player.player.skin_r);
    STR(g->player.player.cloth, g->player.player.cloth_r);
    STR(g->player.player.hair, g->player.player.hair_r);
    STR(g->player.player.cape, g->player.player.cape_r);
}

void move_rect_right(game_t *g)
{
    set_top_rect(g, 0);
    if (g->player.player.cape_r.left > 160-64) {
        g->player.player.skin_r.left = 0;
        g->player.player.cloth_r.left = 0;
        g->player.player.hair_r.left = 0;
        g->player.player.cape_r.left = 0;
    }
    g->player.player.skin_r.left += 32;
    g->player.player.cloth_r.left += 32;
    g->player.player.hair_r.left += 32;
    g->player.player.cape_r.left += 32;
    STR(g->player.player.skin, g->player.player.skin_r);
    STR(g->player.player.cloth, g->player.player.cloth_r);
    STR(g->player.player.hair, g->player.player.hair_r);
    STR(g->player.player.cape, g->player.player.cape_r);
}