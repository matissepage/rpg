/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** btn2true2
*/

#include "rpg.h"

void checkclickbtntrue2(game_t *g)
{
    if (test_hitbox(M, RGP(BUILD_DIALOG.btn[0]), 600, 100) == 1) {
        rendre_quest(g);
    }
    if (test_hitbox(M, RGP(BUILD_DIALOG.btn[1]), 600, 100) == 1) {
        dialoggotogame(g);
    }
}