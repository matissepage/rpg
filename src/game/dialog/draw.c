/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** draw.c
*/

#include "rpg.h"

void draw_spritedialog(game_t *g)
{
    int id = BUILD_DIALOG.quest_actu.icon;

    D(W, BUILD_DIALOG.background.sprite, NULL);
    D(W, BUILD_DIALOG.icon_pnj[id].sprite, NULL);
    T(W, BUILD_DIALOG.linked_dialog->data_dial.text.text, NULL);
    for (int i = 0; i < 3; i++) {
        if (BUILD_DIALOG.status_btn2 == FALSE && i == 1)
            continue;
        sfRenderWindow_drawRectangleShape(W, BUILD_DIALOG.btn[i], NULL);
    }
    for (int i = 0; i < 3; i++) {
        if (BUILD_DIALOG.status_btn2 == FALSE && i == 1)
            continue;
        T(W, BUILD_DIALOG.text_btn[i], NULL);
    }
}