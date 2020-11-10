/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** check_conditionrendu.c
*/

#include "rpg.h"

int end_questmap2(game_t *g)
{
    init_other_map(g, 3);
    return (TRUE);
}

int condition_firstquest(game_t *g)
{
    int cp = 0;
    int nbr_objectif = 1;

    if (item_exist(INV, "waterflask") != -1)
        cp++;
    return (cp == nbr_objectif ? TRUE : FALSE);
}

int condition_7quest(game_t *g)
{
    int cp = 0;
    int nbr_objectif = 2;

    if (item_exist(INV, "key") != -1)
        cp++;
    if (item_exist(INV, "bougie") != -1)
        cp++;
    return (cp == nbr_objectif ? TRUE : FALSE);
}

int check_conditionrendu(game_t *g, int id)
{
    if (id == 1)
        return (condition_firstquest(g));
    if (id == 3)
        return (end_questmap2(g));
    if (id == 2)
        return (TRUE);
    if (id == 7)
        return (condition_7quest(g));
    return (TRUE);
}