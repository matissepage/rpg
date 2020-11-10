/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** event.c
*/

#include "rpg.h"

dataquests_t get_questactivep(game_t *g)
{
    my_list_t *tmp = g->obj.quest.all_quest;
    int id = 0;
    int id_get = g->obj.quest.id_select;

    while (tmp) {
        if (id == id_get)
            return (tmp->data_quest);
        id++;
        tmp = tmp->next;
    }
    return (tmp->data_quest);
}

void analyse_questevent(game_t *g, sfEvent evt)
{
    if (evt.key.code == sfKeyH && g->obj.quest.etat > 0 &&
    g->my_event.is_released == 1) {
        g->obj.quest.etat = 0;
        consolelog(OTHER, "Quest_Etat == 0");
        g->my_event.is_released = 0;
        return;
    }
    if (evt.key.code == sfKeyH && g->obj.quest.etat == 0 &&
    g->my_event.is_released == 1) {
        g->obj.quest.etat = 1;
        consolelog(OTHER, "Quest_Etat == 1");
        g->my_event.is_released = 0;
        return;
    }
}

void quest_pnjevent(game_t *g, sfEvent evt)
{
    if (g->obj.quest.can_pressenter == FALSE)
        return;
    if (evt.key.code == sfKeySpace) {
        g->etat = DIALOG;
        g->obj.dialog.quest_actu = get_questactivep(g);
        change_view(g, 1080, 1920);
    }
}