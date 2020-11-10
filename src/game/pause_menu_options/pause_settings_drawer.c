/*
** EPITECH PROJECT, 2020
** pause_settings_drawer.c
** File description:
** pause_settings_drawer.c
*/

#include "rpg.h"

void draw_pause_settings(game_t *game)
{
    sfRenderWindow_clear(game->window.window, sfBlack);
    for (int i = 0; i < 3; i++) {
        sfRenderWindow_drawSprite(game->window.window, \
        game->pause_s.button[i].sprite, NULL);
        sfRenderWindow_drawSprite(game->window.window, \
        game->pause_s.sprite[i].sprite, NULL);
    }
    for (int i = 0; i < 3; i++) {
        sfRenderWindow_drawText(game->window.window, \
        game->pause_s.button[i].text, NULL);
    }
    sfRenderWindow_drawText(game->window.window, game->pause_s.volume, NULL);
    sfRenderWindow_display(game->window.window);

}

void pause_menu_settings(game_t *game)
{
    static int i = 0;

    if (game->var.music == sfFalse && i == 0) {
        move_rect(&game->pause_s.rect[0], 21, 42);
        sfSprite_setTextureRect(game->pause_s.sprite[0].sprite, \
        game->pause_s.rect[0]);
        i++;
    }

    game->window.time = sfClock_getElapsedTime(game->window.clock);
    game->window.sec = game->window.time.microseconds / 10000.0;

    is_mouse_on_btn(game, game->pause_s.button[2].sprite, \
    game->pause_s.button[2].rect);

    check_pause_settings_click(game);
    if (game->window.sec > 1) {
        draw_pause_settings(game);
    }
}