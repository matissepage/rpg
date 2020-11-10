/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** log.c
*/

#include "rpg.h"

void consolelog(int id, char *str)
{
    if (id == OTHER)
        my_printf("[OTHER]");
    if (id == DESTROY)
        my_printf("[DESTROY]");
    if (id == GAME_ETAT)
        my_printf("[CHANGE GAME ETAT]");
    if (id == INIT)
        my_printf("[INIT]");
    if (id == ERROR)
        my_printf("[ERROR] !");
    my_printf(" => %s\n", str);
}