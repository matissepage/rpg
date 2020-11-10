/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** pnj_interaction.c
*/

#include "rpg.h"

void interaction_pnjcheck(game_t *g)
{
    int id = 0;
    int a = 0;
    my_list_t *tmp = g->obj.quest.all_quest;
    sfVector2f ps = sfSprite_getPosition(g->player.player.hair);
    sfVector2f pos_pnj;

    for (;tmp; tmp = tmp->next) {
        if (ps.x >= tmp->data_quest.x - RANGE_QUEST && ps.x <= tmp->data_quest.x
        + 16 + RANGE_QUEST && ps.y >= tmp->data_quest.y - RANGE_QUEST &&
        ps.y <= tmp->data_quest.y + 32 + RANGE_QUEST &&
        tmp->data_quest.rendu == FALSE) {
            pos_pnj = (init_vector(tmp->data_quest.x, tmp->data_quest.y));
            dislay_infoquestpnj(g, pos_pnj);
            g->obj.quest.id_select = id;
            a = 1;
        }
        id++;
    }
    if (a == 0)
        g->obj.quest.can_pressenter = FALSE;
}