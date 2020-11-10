/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** manage_interaction.c
*/

#include "rpg.h"

void colorchange(game_t *g, int i, sfColor color, int c)
{
    if (i == 0) {
        g->player.player.id_cape = c;
        sfSprite_setColor(g->player.player.cape, color);
    }
    if (i == 1) {
        g->player.player.id_hair = c;
        sfSprite_setColor(g->player.player.hair, color);
    }
    if (i == 2) {
        g->player.player.id_cloth = c;
        sfSprite_setColor(g->player.player.cloth, color);
    }
    if (i == 3) {
        g->player.player.id_eyes = c;
        sfSprite_setColor(g->player.player.eyes, color);
    }
    if (i == 4) {
        g->player.player.id_skin = c;
        sfSprite_setColor(g->player.player.skin, color);
    }
}

void change_color(game_t *g, int e)
{
    sfColor color;
    R(g->window.window, g->obj.menu.preplay.cadre[0], NULL);
    for (int i = 0; i < 65; i++)
        R(g->window.window, g->obj.menu.preplay.panel_color[i], NULL);
    for (int i = 0; i < 65; i++) {
        if (test_hitbox(g->var.pos_mouse_click,
        g->obj.menu.preplay.panel_pos[i], 20, 20) == 1) {
            color = RGF(g->obj.menu.preplay.panel_color[i]);
            colorchange(g, e, color, i);
        }
    }
}

void set_panelcolor(game_t *g)
{
    RSC(g->obj.menu.preplay.panel_color[0], sfRed);
    RSC(g->obj.menu.preplay.panel_color[1], sfBlue);
    RSC(g->obj.menu.preplay.panel_color[2], sfGreen);
    RSC(g->obj.menu.preplay.panel_color[3], sfYellow);
    RSC(g->obj.menu.preplay.panel_color[4], sfBlack);
    RSC(g->obj.menu.preplay.panel_color[5], sfColor_fromRGB(255, 121, 0));
    RSC(g->obj.menu.preplay.panel_color[6], sfColor_fromRGB(157, 207, 204));
    RSC(g->obj.menu.preplay.panel_color[8], sfColor_fromRGB(42, 207, 204));
    RSC(g->obj.menu.preplay.panel_color[9], sfColor_fromRGB(42, 207, 130));
    RSC(g->obj.menu.preplay.panel_color[10], sfColor_fromRGB(42, 207, 253));
    RSC(g->obj.menu.preplay.panel_color[11], sfColor_fromRGB(42, 74, 127));
    RSC(g->obj.menu.preplay.panel_color[12], sfColor_fromRGB(136, 74, 127));
    RSC(g->obj.menu.preplay.panel_color[14], sfColor_fromRGB(91, 60, 17));
    RSC(g->obj.menu.preplay.panel_color[15], sfColor_fromRGB(167, 103, 38));
    init_color(g);
}

void set_panel(game_t *g)
{
    sfVector2f size = init_vector(20, 20);
    sfVector2f pos;
    pos.x = getpourcentage_x(g, 4);
    pos.y = getpourcentage_y(g, 50);
    for (int i = 0, j = 0; i < 65; i++, j++) {
        g->obj.menu.preplay.panel_color[i] = sfRectangleShape_create();
        sfRectangleShape_setSize(g->obj.menu.preplay.panel_color[i], size);
        g->obj.menu.preplay.panel_pos[i] = pos;
        sfRectangleShape_setPosition(g->obj.menu.preplay.panel_color[i], pos);
        pos.x = pos.x + getpourcentage_x(g, 1);
        if (j == 13) {
            pos.y = pos.y + getpourcentage_y(g, 2);
            j = 0;
            pos.x = getpourcentage_x(g, 4);
        }
    }
    set_panelcolor(g);
}

void manage_colorselection(game_t *g)
{
    sfVector2f m = g->var.pos_mouse_click;
    sfVector2f tmp;
    for (int i = 0; i < 6; i++) {
        tmp = g->obj.menu.preplay.button[i].vector;
        if (test_hitbox(m , tmp, 340, 88) == 1) {
            sfMusic_play(g->obj.click);
            g->var.pos_mouse_click = init_vector(-100, -100);
            g->obj.menu.preplay.etat = i;
        }
    }
    if (g->obj.menu.preplay.etat != -1)
        change_color(g, g->obj.menu.preplay.etat);
}