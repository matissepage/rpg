/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** shop
*/

#include "rpg.h"

void reset_pos_game(game_t *g)
{
    sfText_setPosition(g->player.text[1], g->player.tmp_vec);
    sfText_setCharacterSize(g->player.text[1], 30);
}

void event_shop(game_t *g, sfEvent evt)
{
    if (g->etat == SHOP) {
        if (evt.key.code == sfKeyB) {
            change_view(g, 650, 1200);
            reset_pos_game(g);
            g->etat = GAME;
        }
        if (evt.type == sfEvtMouseButtonPressed)
            check_item_select(g, evt.mouseButton.x, evt.mouseButton.y);
    }
}

void shop(game_t *g)
{
    g->window.time = sfClock_getElapsedTime(g->window.clock);
    g->window.sec = g->window.time.microseconds / 10000.0;
    if (g->window.sec > 1) {
        sfText_setString(g->player.text[1], my_atoi(g->player.gold));
        sfRenderWindow_clear(W, sfBlack);
        D(g->window.window, g->shop.shop.sprite, NULL);
        D(g->window.window, g->shop.hud.sprite, NULL);
        draw_item_shop(g);
        T(g->window.window, g->player.text[1], NULL);
        sfRenderWindow_display(W);
        sfClock_restart(g->window.clock);
    }
}