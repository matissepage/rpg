/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** check.c
*/

#include "rpg.h"

char *get_namequestactu(my_list_t **list, int nbr)
{
    my_list_t *tmp = *list;
    int id = 0;

    while (tmp) {
        id++;
        if (nbr == id)
            return (tmp->data_actu.name);
        tmp = tmp->next;
    }
    return (NULL);
}

void check_infoquestactu(game_t *g)
{
    if (BUILD_QUEST.quest_actu != NULL) {
        sfText_setString( BUILD_QUEST.quest[0],
        get_namequestactu(&BUILD_QUEST.quest_actu, 1));
    }
}