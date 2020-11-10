/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** event2
*/

#include "rpg.h"

void button_checkexitdialog(game_t *g)
{
    if (test_hitbox(M, RGP(BUILD_DIALOG.btn[2]), 600, 100) == 1) {
        dialoggotogame(g);
    }
}

void button_checkpressdialog(game_t *g)
{
    if (test_hitbox(M, RGP(BUILD_DIALOG.btn[0]), 600, 100) == 1) {
        if (BUILD_DIALOG.linked_dialog->next == NULL) {
            consolelog(OTHER, "Last Dialog");
            gotodialogbtn2(g);
            g->var.pos_mouse_click = init_vector(-100, -100);
            return;
        }
            BUILD_DIALOG.linked_dialog = BUILD_DIALOG.linked_dialog->next;
    }
}

void button_higllightdialog(game_t *g, int id)
{
    sfColor color = sfColor_fromRGB(91, 60, 17);
    sfVector2f m = g->var.pos_mouse;

    for (int i = 0; i < 3; i++) {
        if (i == 1 && id == 0)
            continue;
        if (test_hitbox(m, RGP(BUILD_DIALOG.btn[i]), 600, 100) == 1)
            sfRectangleShape_setFillColor(BUILD_DIALOG.btn[i], color);
        else
            sfRectangleShape_setFillColor(BUILD_DIALOG.btn[i], MARRON);
    }
}