/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** player
*/

#include "rpg.h"

void set_pos_player_default(game_t *g, float x, float y)
{
    sfVector2f vec;

    vec.x = x;
    vec.y = y;
    g->player.player.skin_v = vec;
    g->player.player.cloth_v = vec;
    g->player.player.eyes_v = vec;
    g->player.player.cape_v = vec;
    g->player.player.eyes_v = vec;
    g->player.player.hair_v = vec;
    g->window.vc_view = vec;
    sfView_setCenter(g->window.view_game, g->window.vc_view);
    SP(g->player.player.hair, g->player.player.hair_v);
    SP(g->player.player.cape, g->player.player.cape_v);
    SP(g->player.player.cloth, g->player.player.cloth_v);
    SP(g->player.player.eyes, g->player.player.eyes_v);
    SP(g->player.player.skin, g->player.player.skin_v);
}

void change_pos_player_g(game_t *g, sfVector2f vec)
{
    SP(g->player.player.hair, vec);
    SP(g->player.player.cape, vec);
    SP(g->player.player.cloth, vec);
    SP(g->player.player.eyes, vec);
    SP(g->player.player.skin, vec);
}

void move_player(game_t *g, sfEvent evt)
{
    if (evt.key.code == sfKeyZ)
        moove_player_ztxt(g->map.map, g);
    if (evt.key.code == sfKeyS)
        moove_player_stxt(g->map.map, g);
    if (evt.key.code == sfKeyQ)
        moove_player_qtxt(g->map.map, g);
    if (evt.key.code == sfKeyD)
        moove_player_dtxt(g->map.map, g);
}

void draw_basi_player(game_t *g)
{
    g->player.player.cape_r = initrect(0, 0, 160/5,256/4);
    g->player.player.cloth_r = initrect(0, 0, 160/5,256/4);
    g->player.player.hair_r = initrect(0, 0, 160/5,256/4);
    g->player.player.skin_r = initrect(0, 0, 160/5,256/4);
    STR(g->player.player.skin, g->player.player.skin_r);
    STR(g->player.player.cloth, g->player.player.cloth_r);
    STR(g->player.player.hair, g->player.player.hair_r);
    STR(g->player.player.cape, g->player.player.cape_r);
}

void draw_player_game(game_t *g)
{
    display_ui_player(g);
    D(g->window.window, g->player.player.cloth, NULL);
    D(g->window.window, g->player.player.cape, NULL);
    D(g->window.window, g->player.player.eyes, NULL);
    D(g->window.window, g->player.player.skin, NULL);
    D(g->window.window, g->player.player.hair, NULL);
}