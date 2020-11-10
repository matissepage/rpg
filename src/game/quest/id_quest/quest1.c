/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** quest1.c
*/

#include "rpg.h"

void init_dataquest1(game_t *g, my_list_t *tmp)
{
    add_movementpnj(g, 1, (sfVector2f){700, 600});
    tmp->data_quest.init_beginquest = TRUE;
}

void quest1_main(game_t *g, my_list_t *tmp)
{
    if (tmp->data_quest.init_beginquest == FALSE) {
        init_dataquest1(g, tmp);
    } else {
        move_allpnj(g);
    }
}