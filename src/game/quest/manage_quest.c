/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** manage_quest.c
*/

#include "rpg.h"

void manage_quest(game_t *g)
{
    draw_pnj(g);
    interaction_pnjcheck(g);
    check_infoquestactu(g);
    manage_drawquest(g);
    manage_questactive(g);
}