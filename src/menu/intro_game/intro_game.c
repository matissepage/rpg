/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** intro_game.c
*/

#include "rpg.h"

void event_intro(game_t *g, sfEvent evt)
{
    if (evt.key.code == sfKeySpace)
        g->etat = GAME;
}

void intro_game(game_t *g)
{
    int time = sfClock_getElapsedTime(g->window.clock).microseconds / 100000;

    sfRenderWindow_clear(g->window.window, sfBlack);
    sfRenderWindow_drawSprite(W, BUILD_INTRO.bg.sprite, NULL);
    T(W, BUILD_INTRO.press_skip, NULL);
    sfRenderWindow_display(g->window.window);
    if (time > 100) {
        g->etat = GAME;
        sfClock_restart(g->window.clock);
    }
}