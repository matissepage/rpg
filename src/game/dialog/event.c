/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** event.c
*/

#include "rpg.h"

void analyse_indialog(game_t *g, sfEvent event)
{
    g->etat = g->etat;
    if (event.type == sfEvtMouseButtonPressed) {

    }
}

void manage_interaction_dialog(game_t *g)
{
    if (BUILD_DIALOG.status_btn2 == FALSE) {
        button_higllightdialog(g, 0);
        button_checkpressdialog(g);
        button_checkexitdialog(g);
        g->var.pos_mouse_click = init_vector(-100, -100);
    } else {
        button_higllightdialog(g, 1);
        button_checkexitdialog(g);
        checkclickbtntrue(g);
        g->var.pos_mouse_click = init_vector(-100, -100);
    }
}

void button_checkpressdialog2(game_t *g)
{
    if (test_hitbox(M, RGP(BUILD_DIALOG.btn[0]), 600, 100) == 1) {
        if (BUILD_DIALOG.linked_dialog->next == NULL) {
            consolelog(OTHER, "Last Dialog");
            BUILD_DIALOG.status_btn2 = TRUE;
            sfText_setString(BUILD_DIALOG.text_btn[0], "Je rends la quete !");
            sfText_setString(BUILD_DIALOG.text_btn[1], \
            "J'ai encore des choses a faire... !");
            g->var.pos_mouse_click = init_vector(-100, -100);
            return;
        }
            BUILD_DIALOG.linked_dialog = BUILD_DIALOG.linked_dialog->next;
    }
}

void manage_interaction_dialogend(game_t *g)
{
    if (BUILD_DIALOG.status_btn2 == FALSE) {
        button_higllightdialog(g, 0);
        button_checkpressdialog2(g);
        button_checkexitdialog(g);
        g->var.pos_mouse_click = init_vector(-100, -100);
    } else {
        button_higllightdialog(g, 1);
        button_checkexitdialog(g);
        checkclickbtntrue2(g);
        g->var.pos_mouse_click = init_vector(-100, -100);
    }
}