/*
** EPITECH PROJECT, 2020
** init_waiting_screen.c
** File description:
** init_waiting_screen.c
*/

#include "rpg.h"

static void init_pos(game_t *game)
{
    sfVector2f pos = {getpourcentage_x(game, 95), getpourcentage_y(game, 92)};
    sfSprite_setPosition(game->waiting.sprite[0].sprite, pos);
}

static void init_text(game_t *game)
{
    char text[8] = "Loading";
    game->waiting.loading = create_text(ffont, text,\
    getpourcentage_x(game, 87), getpourcentage_y(game, 90));
}

void init_waiting_screen(game_t *game)
{
    game->waiting.sprite[0].sprite = create_sprite("assets/loading.png");
    game->waiting.sprite[0].rect = (sfIntRect){0, 0, 200, 200};
    SSTR(game->waiting.sprite[0].sprite, game->waiting.sprite[0].rect);
    sfSprite_setOrigin(game->waiting.sprite[0].sprite, (sfVector2f){100, 100});
    sfSprite_setScale(game->waiting.sprite[0].sprite, (sfVector2f){0.5, 0.5});
    init_text(game);
    init_pos(game);
}

static void drawer(game_t *game)
{
    game->window.time = sfClock_getElapsedTime(game->window.clock);
    game->window.sec = game->window.time.microseconds / 10000.0;

    if (game->window.sec > 1) {
        sfRenderWindow_clear(game->window.window, sfBlack);
        sfRenderWindow_drawSprite(game->window.window,\
        game->waiting.sprite[0].sprite, NULL);
        sfRenderWindow_drawText(game->window.window,\
        game->waiting.loading, NULL);
        sfClock_restart(game->window.clock);
        sfRenderWindow_display(game->window.window);
    }
}

void draw_waiting_screen(game_t *game)
{
    btn_anim.time = sfClock_getElapsedTime(btn_anim.clock);
    btn_anim.seconds = btn_anim.time.microseconds / 100000.0;

    if (btn_anim.seconds > 0.5) {
        if (game->waiting.sprite[0].rect.left <= 3190) {
            move_rect(&game->waiting.sprite[0].rect, 200, 3200);
            sfSprite_setTextureRect(game->waiting.sprite[0].sprite,\
            game->waiting.sprite[0].rect);
        } else {
            game->waiting.sprite[0].rect = (sfIntRect){0, 0, 200, 200};
            sfSprite_setTextureRect(game->waiting.sprite[0].sprite,\
            game->waiting.sprite[0].rect);
        }
        sfClock_restart(btn_anim.clock);
    }
    drawer(game);
}