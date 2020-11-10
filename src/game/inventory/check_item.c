/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** check invt
*/

#include "rpg.h"

int item_exist(link_t *link, char *name)
{
    node_t *node = link->head;
    int index = 0;

    while (node != NULL) {
        if (my_strcmp(node->name, name) == 0)
            return (index);
        index += 1;
        node = node->next;
    }
    return (-1);
}