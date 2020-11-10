/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** loop.c
*/

#include "rpg.h"

void dialog_initafter(game_t *g)
{
    if (g->obj.dialog.quest_actu.accept == FALSE) {
        get_parsedialoglinkedlist(g);
        BUILD_DIALOG.load_this = TRUE;
        BUILD_DIALOG.status_btn2 = FALSE;
    } else {
        get_parsedialoglinkedlistend(g);
        BUILD_DIALOG.load_this = TRUE;
        BUILD_DIALOG.status_btn2 = FALSE;
        /*
            Initialiser les dialogs / btn ect pour rendre les quêtes.
        */
    }
}

void loop_dialog(game_t *g)
{
    g->window.time = sfClock_getElapsedTime(g->window.clock);
    g->window.sec = g->window.time.microseconds / 10000.0;
    if (!BUILD_DIALOG.load_this) {
        dialog_initafter(g);
    } else if (g->obj.dialog.quest_actu.accept == FALSE) {
        if (g->window.sec > 1) {
            sfRenderWindow_clear(W, sfBlack);
            draw_spritedialog(g);
            manage_interaction_dialog(g);
            sfRenderWindow_display(W);
            sfClock_restart(g->window.clock);
        }
    } else {
        if (g->window.sec > 1) {
            sfRenderWindow_clear(W, sfBlack);
            draw_spritedialog(g);
            manage_interaction_dialogend(g);
            sfRenderWindow_display(W);
            sfClock_restart(g->window.clock);
        }
    }
}