/*
** EPITECH PROJECT, 2020
** draw_win.c
** File description:
** draw_win.c
*/

#include "rpg.h"

static void win(game_t *game)
{
    sfRenderWindow_clear(game->window.window, sfBlack);
    sfRenderWindow_drawSprite(game->window.window,\
    game->win_screen.sprite[0].sprite, NULL);
    sfRenderWindow_drawSprite(game->window.window,\
    game->win_screen.button[0].sprite, NULL);
    sfRenderWindow_drawText(game->window.window,\
    game->win_screen.button[0].text, NULL);
    sfRenderWindow_drawText(game->window.window, game->win_screen.text, NULL);
    sfRenderWindow_display(game->window.window);
}

void draw_win(game_t *game)
{
    game->window.time = sfClock_getElapsedTime(game->window.clock);
    game->window.sec = game->window.time.microseconds / 10000.0;

    is_mouse_on_btn(game, game->win_screen.button[0].sprite,\
    game->win_screen.button[0].rect);

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (test_hitbox_o(game->var.pos_mouse_click,\
        sfSprite_getPosition(game->win_screen.button[0].sprite),\
        340, 88) == 1) {
            game->etat = END;
        }
    }

    if (game->window.sec > 1) {
        win(game);
    }
}