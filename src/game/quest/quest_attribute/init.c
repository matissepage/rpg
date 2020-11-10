/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init.c
*/

#include "rpg.h"

dataquestactu_t init_dataquestactu(char *name)
{
    dataquestactu_t data;

    data.name = malloc(sizeof(char) * (my_strlen(name) + 1));
    data.name = my_strcpy(data.name, name);
    data.pourcentage = 0;
    data.status = 0;
    data.next = NULL;

    return (data);
}

void add_nodequestactu(my_list_t **list, dataquestactu_t data)
{
    my_list_t *elem = malloc(sizeof(my_list_t));
    my_list_t *tmp = *list;

    elem->data_actu = data;
    elem->next = NULL;

    if (!(*list)) {
        *list = elem;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = elem;
}

void init_questactu(game_t *g)
{
    BUILD_QUEST.quest_actu = NULL;
}