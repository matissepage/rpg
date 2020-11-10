/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** settings.c
*/

#include "rpg.h"

void draw_spritesett(game_t *g)
{
    D(W, g->obj.settings.bool_music.sprite, NULL);
    D(W, g->obj.settings.volume_music.sprite, NULL);
    D(W, g->obj.settings.size_windows.sprite, NULL);
    D(W, g->obj.settings.check_music.sprite, NULL);
    D(W, g->obj.settings.go_back.sprite, NULL);
    sfRenderWindow_drawText(W, g->obj.settings.bool_music.text, NULL);
    sfRenderWindow_drawText(W, g->obj.settings.volume_music.text, NULL);
    sfRenderWindow_drawText(W, g->obj.settings.slide_volume.text, NULL);
    sfRenderWindow_drawText(W, g->obj.settings.go_back.text, NULL);
}

void settings(game_t *g)
{
    is_mouse_on_btn(g, btn_ss, btn_rr);
    int time = sfClock_getElapsedTime(g->window.clock).microseconds / 10000;
    if (time > 10) {
        sfRenderWindow_clear(W, sfBlack);
        move_background(g);
        D(g->window.window, g->background.sprite, NULL);
        interaction_settings(g);
        draw_spritesett(g);
        sfRenderWindow_display(W);
        sfClock_restart(g->window.clock);
    }
}