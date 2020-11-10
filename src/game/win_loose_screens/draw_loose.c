/*
** EPITECH PROJECT, 2020
** draw_loose.c
** File description:
** draw_loose.c
*/

#include "rpg.h"

static void loose(game_t *game)
{
    sfRenderWindow_clear(game->window.window, sfBlack);
    sfRenderWindow_drawSprite(game->window.window,\
    game->loose_screen.sprite[0].sprite, NULL);
    sfRenderWindow_drawSprite(game->window.window,\
    game->loose_screen.button[0].sprite, NULL);
    sfRenderWindow_drawText(game->window.window,\
    game->loose_screen.button[0].text, NULL);
    sfRenderWindow_drawText(game->window.window, game->loose_screen.text, NULL);
    sfRenderWindow_display(game->window.window);
}

void draw_loose(game_t *game)
{
    game->window.time = sfClock_getElapsedTime(game->window.clock);
    game->window.sec = game->window.time.microseconds / 10000.0;

    is_mouse_on_btn(game, game->loose_screen.button[0].sprite,\
    game->loose_screen.button[0].rect);

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (test_hitbox_o(game->var.pos_mouse_click,\
        sfSprite_getPosition(game->loose_screen.button[0].sprite),\
        340, 88) == 1) {
            init_other_map(game, game->player.map_actu);
            change_view(game, 650, 1200);
        }
    }

    if (game->window.sec > 1) {
        loose(game);
    }
}