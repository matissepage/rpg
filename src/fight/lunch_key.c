/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** lunch_key.c
*/

#include "rpg.h"

void lunchattackwithkey(game_t *g)
{
    int where = 0;

    if (sfKeyboard_isKeyPressed(sfKeyA)) {
        g->obj.fight.atk = 1;
        where++;
    }
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        g->obj.fight.atk = 2;
        where++;
    }
    if (sfKeyboard_isKeyPressed(sfKeyE)) {
        g->obj.fight.atk = 3;
        where++;
    }
    if (where == 0)
        return;
    g->var.pos_mouse_click = (sfVector2f) {0, 0};
    g->obj.fight.etat = 1;
    gestion_attack_time(g);
}