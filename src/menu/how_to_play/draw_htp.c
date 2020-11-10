/*
** EPITECH PROJECT, 2020
** draw_htp.c
** File description:
** draw_htp.c
*/

#include "rpg.h"

static void htp(game_t *game)
{
    sfRenderWindow_clear(game->window.window, sfBlack);
    sfRenderWindow_drawSprite(game->window.window,\
    game->htp.button[0].sprite, NULL);
    for (int i = 0; i < 7; i++) {
        sfRenderWindow_drawText(game->window.window, game->htp.text[i], NULL);
    }
    sfRenderWindow_drawText(game->window.window,\
    game->htp.button[0].text, NULL);
    sfRenderWindow_display(game->window.window);
}

void draw_htp(game_t *game)
{
    game->window.time = sfClock_getElapsedTime(game->window.clock);
    game->window.sec = game->window.time.microseconds / 10000.0;

    is_mouse_on_btn(game, game->htp.button[0].sprite,\
    game->htp.button[0].rect);

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (test_hitbox_o(game->var.pos_mouse_click,\
        sfSprite_getPosition(game->htp.button[0].sprite),\
        340, 88) == 1) {
            game->etat = PREPLAY;
        }
    }

    if (game->window.sec > 1) {
        htp(game);
    }
}