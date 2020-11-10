/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** manage_questactive.c
*/

#include "rpg.h"

void manage_questactive(game_t *g)
{
    my_list_t *tmp = g->obj.quest.all_quest;

    while (tmp) {
        if (tmp->data_quest.id == 1 && tmp->data_quest.accept == TRUE)
            quest1_main(g, tmp);
        tmp = tmp->next;
    }
}