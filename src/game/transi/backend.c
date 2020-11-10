/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** backend.c
*/

#include "rpg.h"

void end_cinematic(game_t *g)
{
    g->allow_event = TRUE;
    g->map.etat_map = 4;
    init_other_map(g, 5);
    call_fightquest(g, sendmonster(2, 5, 1, WATER));
    call_fightquest(g, sendmonster(3, 2, 2, FIRE));
    free_transition(g);
}

void animationpnj(game_t *g)
{
    int time = 0;
    sfVector2f sortie;
    sfVector2f cev = sfSprite_getPosition(g->player.player.cape);

    for (my_list_t *tmp = g->transi.list; tmp ; tmp = tmp->next) {
        time = sfClock_getElapsedTime(tmp->data.clock).microseconds / 1000000;
        sfSprite_setPosition(tmp->data.sprite, tmp->data.pos);
        if (time > 15) {
            sortie = calc_newvel(tmp->data.pos, tmp->data.dest, 5);
            tmp->data.pos.x += sortie.x;
            tmp->data.pos.y += sortie.y;
            sfClock_restart(tmp->data.clock);
        }
    }
}