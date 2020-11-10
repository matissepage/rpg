/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** node.c
*/

#include "rpg.h"

my_dataannim_t init_dataanimation(int type, int id_pnj, sfVector2f where)
{
    my_dataannim_t data;

    data.type = type;
    data.id_pnj = id_pnj;
    data.where = where;
    return (data);
}

void add_nodeanimationpnj(my_list_t **list, my_dataannim_t data)
{
    my_list_t *elem = malloc(sizeof(my_list_t));
    my_list_t *tmp = *list;

    elem->animation = data;
    elem->next = NULL;

    if (!(*list)) {
        *list = elem;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = elem;
}

void add_movementpnj(game_t *g, int id_pnj, sfVector2f where)
{
    my_dataannim_t data = init_dataanimation(MOVEMENT, id_pnj, where);
    add_nodeanimationpnj(&g->obj.quest.animation_on, data);
}

void remove_node_pos(my_list_t **list, int position)
{
    my_list_t *tmp1 = NULL;
    my_list_t *tmp2 = (*list);
    my_list_t *tmp3 = NULL;

    if (position == 0) {
        tmp1 = (*list);
        *list = (*list)->next;
        return;
    }
    for (int i = 0; i < position - 1; i += 1) {
        tmp2 = tmp2->next;
    }
    tmp1 = tmp2->next->next;
    tmp3 = tmp2->next;
    tmp2->next = tmp1;
    free (tmp3);
}