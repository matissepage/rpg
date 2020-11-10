/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** node_quest.c
*/

#include "rpg.h"

void add_quests(my_list_t **list, dataquests_t dataquest)
{
    my_list_t *elem = malloc(sizeof(my_list_t));
    my_list_t *tmp = *list;

    elem->data_quest = dataquest;
    elem->next = NULL;
    if (!(*list)) {
        *list = elem;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = elem;
}