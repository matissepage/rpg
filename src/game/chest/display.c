/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** display.c
*/

#include "rpg.h"

void display_chest(game_t *g)
{
    my_list_t *tmp = g->obj.quest.chest_list;

    while (tmp) {
        sfRenderWindow_drawSprite(W, tmp->data.sprite, NULL);
        tmp = tmp->next;
    }
}