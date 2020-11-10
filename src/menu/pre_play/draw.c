/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** draw.c
*/

#include "rpg.h"

void draw_preplay1(game_t *g)
{
    T(W, BUILD_PREPLAY.modif_skin, NULL);
    T(W, BUILD_PREPLAY.modif_hair, NULL);
    T(W, BUILD_PREPLAY.name_text, NULL);
    for (int i = 0; i < 5; i++) {
        D(W, BUILD_PREPLAY.button[i].sprite, NULL);
        T(W, BUILD_PREPLAY.button_text[i], NULL);
    }
    D(W, BUILD_PREPLAY.btn[0].sprite, NULL);
    D(W, BUILD_PREPLAY.btn[1].sprite, NULL);
    T(W, BUILD_PREPLAY.text[0], NULL);
    T(W, BUILD_PREPLAY.text[1], NULL);
}

void draw_preplay(game_t *g)
{
    for (int i = 1; i < 3; i++)
        R(W, BUILD_PREPLAY.cadre[i], NULL);
    D(W, g->player.player.cloth, NULL);
    D(W, g->player.player.cape, NULL);
    D(W, g->player.player.eyes, NULL);
    D(W, g->player.player.skin, NULL);
    D(W, g->player.player.hair, NULL);
    T(W, BUILD_PREPLAY.modif_cape, NULL);
    T(W, BUILD_PREPLAY.modif_cloth, NULL);
    T(W, BUILD_PREPLAY.modif_eyes, NULL);
    draw_preplay1(g);
}