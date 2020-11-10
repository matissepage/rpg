/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** interaction_settings.c
*/

#include "rpg.h"

void new_sizewindow(game_t *g, int y, int x)
{
    sfRenderWindow_setSize(W, (sfVector2u){y, x});
    g->window.size_window.x = x;
    g->window.size_window.y = y;
}

void manage_listbelowsettings(game_t *g)
{
    sfVector2f m = g->var.pos_mouse_click;

    for (int i = 0; i < 4; i++)
        D(W, g->obj.settings.btn_size[i].sprite, NULL);
    for (int i = 0; i < 4; i++)
        sfRenderWindow_drawText(W, g->obj.settings.btn_size[i].text, NULL);
    if (test_hitbox(m, g_pos(BUILD.btn_size[1].sprite), 340, 88) == 1)
        new_sizewindow(g, 1920, 1080);
    if (test_hitbox(m, g_pos(BUILD.btn_size[2].sprite), 340, 88) == 1)
        new_sizewindow(g, 1920, 1280);
    if (test_hitbox(m, g_pos(BUILD.btn_size[3].sprite), 340, 88) == 1)
        new_sizewindow(g, 800, 600);
}

void change_volumeset(game_t *g)
{
    sfVector2f where = g->var.pos_mouse_click;
    where.y = BUILD.slider_findecousey;
    if (where.x < BUILD.slider_findecourse1)
        where.x = BUILD.slider_findecourse1;
    if (where.x > BUILD.slider_findecourse2)
        where.x = BUILD.slider_findecourse2;
    D(W, g->obj.settings.slide_volume.sprite, NULL);
    D(W, g->obj.settings.slider_right.sprite, NULL);
    sfSprite_setPosition(g->obj.settings.slider_right.sprite, where);
}

void change_boolmusic(game_t *g)
{
    move_rect(&BUILD.check_music.rect, 21, 42);
    sfSprite_setTextureRect(BUILD.check_music.sprite, BUILD.check_music.rect);
    if (g->var.music) {
        g->var.music = sfFalse;
        sfText_setString(BUILD.bool_music.text, "Music : OFF");
        sfMusic_pause(g->background.music.music);
    } else {
        g->var.music = sfTrue;
        sfText_setString(BUILD.bool_music.text, "Music : ON");
        sfMusic_play(g->background.music.music);
    }
}

void interaction_settings(game_t *g)
{
    sfVector2f m = g->var.pos_mouse_click;

    if (test_hitbox(m, g_pos(BUILD.size_windows.sprite), 340, 400) == 1)
        manage_listbelowsettings(g);
    if (test_hitbox(m, g_pos(BUILD.bool_music.sprite), 340, 88) == 1) {
        change_boolmusic(g);
        g->var.pos_mouse_click = init_vector(-100, -100);
        return;
    }
    if (test_hitbox(m, g_pos(BUILD.volume_music.sprite), 340, 88) == 1 ||
    test_hitbox(m, g_pos(BUILD.slide_volume.sprite), 340, 88) == 1) {
        change_volumeset(g);
        return;
    } else {

    }
    if (test_hitbox(m, g_pos(BUILD.go_back.sprite), 340, 88) == 1) {
        g->etat = MENU;
        g->var.pos_mouse_click = init_vector(-100, -100);
    }
}