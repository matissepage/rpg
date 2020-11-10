/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** animation
*/

#include "rpg.h"

void animation_right(game_t *g)
{
    sfVector2f vec = sfView_getCenter(g->window.view_game);
    sfVector2f anim = init_vector(0, 0);
    float tmp = 0;

    if (g->player.etat == 1) return;
    anim.x = vec.x;
    anim.y = vec.y;
    tmp = anim.x+120;
    while (anim.x != tmp) {
        sfView_setCenter(g->window.view_game, anim);
        anim.x += 10;
    }
    while (anim.x != vec.x) {
        sfView_setCenter(g->window.view_game, anim);
        anim.x -= 10;
    }
    g->player.etat = 1;
}