/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** quest_info.c
*/

#include "rpg.h"

int get_nbrquest(game_t *g)
{
    my_list_t *tmp = g->obj.quest.all_quest;
    int i = 0;

    while (tmp) {
        i++;
        tmp = tmp->next;
    }
    return (i);
}