/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** set_data.c
*/

#include "rpg.h"

void finishquest3(game_t *g)
{
    g->map.map[21][17] = '1';
    g->map.map[21][18] = '1';
    init_other_map(g, 3);
    g->map.etat_map = CIN_TRANSITION;
    g->allow_event = FALSE;
    init_transition(g);
    add_popup(&g->obj.anim, create_datapopup(4, "You Sleep...", TOP));
}

void action_accept(int id, game_t *g)
{
    sprite_t new_mob;
    if (id == 2)
        call_fightquest(g, sendmonster(1, 5, 1, FIRE));
    if (id == 3) {
        finishquest3(g);
    }
    if (id == 8)
        call_fightquest(g, sendmonster(2, 20, 3, WATER));
}

void set_accept(int id, game_t *g)
{
    my_list_t *tmp = BUILD_QUEST.all_quest;

    action_accept(id, g);
    while (tmp) {
        if (tmp->data_quest.id == id)
            tmp->data_quest.accept = TRUE;
        tmp = tmp->next;
    }
}