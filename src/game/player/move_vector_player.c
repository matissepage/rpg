/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** move vector player
*/

#include "rpg.h"

void move_vector(sfVector2f *vector, float x, float y)
{
    vector->x += x;
    vector->y += y;
}

void move_player_up(game_t *g, float coef)
{
    move_ui_z(g, coef);
    move_vector(&g->player.player.cape_v, 0, -coef);
    move_vector(&g->player.player.cloth_v, 0,- coef);
    move_vector(&g->player.player.skin_v, 0, -coef);
    move_vector(&g->player.player.eyes_v, 0, -coef);
    move_vector(&g->player.player.hair_v, 0, -coef);
    g->window.vc_view.y -= coef;
    SP(g->player.player.cape, g->player.player.cape_v);
    SP(g->player.player.cloth, g->player.player.cloth_v);
    SP(g->player.player.eyes, g->player.player.eyes_v);
    SP(g->player.player.skin, g->player.player.skin_v);
    SP(g->player.player.hair, g->player.player.hair_v);
    sfView_setCenter(g->window.view_game, g->window.vc_view);
    sfView_setCenter(g->window.mini_map, g->window.vc_view);
}

void move_player_down(game_t *g, float coef)
{
    move_ui_s(g, coef);
    move_vector(&g->player.player.cape_v, 0, coef);
    move_vector(&g->player.player.cloth_v, 0, coef);
    move_vector(&g->player.player.skin_v, 0, coef);
    move_vector(&g->player.player.eyes_v, 0, coef);
    move_vector(&g->player.player.hair_v, 0, coef);
    g->window.vc_view.y += coef;
    SP(g->player.player.cape, g->player.player.cape_v);
    SP(g->player.player.cloth, g->player.player.cloth_v);
    SP(g->player.player.eyes, g->player.player.eyes_v);
    SP(g->player.player.skin, g->player.player.skin_v);
    SP(g->player.player.hair, g->player.player.hair_v);
    sfView_setCenter(g->window.view_game, g->window.vc_view);
    sfView_setCenter(g->window.mini_map, g->window.vc_view);
}

void move_player_left(game_t *g, float coef)
{
    move_ui_q(g, coef);
    move_vector(&g->player.player.cape_v, -coef, 0);
    move_vector(&g->player.player.cloth_v, -coef, 0);
    move_vector(&g->player.player.skin_v, -coef, 0);
    move_vector(&g->player.player.eyes_v, -coef, 0);
    move_vector(&g->player.player.hair_v, -coef, 0);
    g->window.vc_view.x -= coef;
    SP(g->player.player.cape, g->player.player.cape_v);
    SP(g->player.player.cloth, g->player.player.cloth_v);
    SP(g->player.player.eyes, g->player.player.eyes_v);
    SP(g->player.player.skin, g->player.player.skin_v);
    SP(g->player.player.hair, g->player.player.hair_v);
    sfView_setCenter(g->window.view_game, g->window.vc_view);
    sfView_setCenter(g->window.mini_map, g->window.vc_view);
}

void move_player_right(game_t *g, float coef)
{
    moove_ui_d(g, coef);
    move_vector(&g->player.player.cape_v, coef, 0);
    move_vector(&g->player.player.cloth_v, coef, 0);
    move_vector(&g->player.player.skin_v, coef, 0);
    move_vector(&g->player.player.eyes_v, coef, 0);
    move_vector(&g->player.player.hair_v, coef, 0);
    g->window.vc_view.x += coef;
    SP(g->player.player.cape, g->player.player.cape_v);
    SP(g->player.player.cloth, g->player.player.cloth_v);
    SP(g->player.player.eyes, g->player.player.eyes_v);
    SP(g->player.player.skin, g->player.player.skin_v);
    SP(g->player.player.hair, g->player.player.hair_v);
    sfView_setCenter(g->window.view_game, g->window.vc_view);
    sfView_setCenter(g->window.mini_map, g->window.vc_view);
}