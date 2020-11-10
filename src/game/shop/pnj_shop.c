/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** shop
*/

#include "rpg.h"

void change_place(game_t *g)
{
    g->player.tmp_vec = sfText_getPosition(g->player.text[1]);
    sfText_setPosition(g->player.text[1], (sfVector2f){1680, 85});
    sfText_setCharacterSize(g->player.text[1], 60);
}

void place_text_preshop(game_t *g, int index)
{
    sfVector2f vec_text;

    if (g->shop.info[index].etat == 1) return;
    vec_text = g->shop.pnj[index].vector;
    vec_text.y -= 50;
    vec_text.x -= 40;
    sfText_setPosition(g->shop.text[0], vec_text);
    g->shop.info[index].etat = 1;
    g->shop.info[index].index = index;
}

void check_shop(game_t *g)
{
    for (int i = 0; i < 1; i++) {
        if (g->player.player.skin_v.x > g->shop.pnj[i].vector.x - 80 &&  \
            g->player.player.skin_v.x < g->shop.pnj[i].vector.x + 80) {
            if (g->player.player.skin_v.y > g->shop.pnj[i].vector.y - 80 && \
                g->player.player.skin_v.y < g->shop.pnj[i].vector.y + 80) {
                place_text_preshop(g, i);
            } else
                g->shop.info[i].etat = 0;
        } else
            g->shop.info[i].etat = 0;
    }
}

void event_pnj_shop(game_t *g, sfEvent evt)
{
    for (int i = 0; i < 1; i++) {
        if (g->shop.info[i].etat == 1) {
            if (evt.key.code == sfKeyN) {
                change_view(g, 1080, 1920);
                change_place(g);
                g->etat = SHOP;
            }
        }
    }
}

void draw_pnj_shop(game_t *g)
{
    check_shop(g);
    for (int i = 0; i < 1; i++) {
        D(g->window.window, g->shop.pnj[i].sprite, NULL);
        if (g->shop.info[i].etat == 1)
            T(g->window.window, g->shop.text[i], NULL);
    }
}