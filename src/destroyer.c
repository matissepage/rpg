/*
** EPITECH PROJECT, 2020
** destroyer.c
** File description:
** destroyer.c
*/

#include "rpg.h"

void init_menu_destroyer(game_t *game)
{
    for (int i = 0; i < 11; i++) {
        sfTexture_destroy(game->background.texture[i]);
    }
    sfSprite_destroy(game->background.sprite);
    sfClock_destroy(game->background.clock);
    sfSprite_destroy(game->obj.menu.buttons[0].sprite);
    sfSprite_destroy(game->obj.menu.buttons[1].sprite);
    sfSprite_destroy(game->obj.menu.buttons[2].sprite);
    sfSprite_destroy(game->obj.menu.buttons[3].sprite);
    sfText_destroy(game->obj.menu.buttons[0].text);
    sfText_destroy(game->obj.menu.buttons[1].text);
    sfText_destroy(game->obj.menu.buttons[2].text);
    sfText_destroy(game->obj.menu.buttons[3].text);
    sfClock_destroy(game->obj.menu.anim_btn.clock);
}

void music_destroyer(game_t *game)
{
    sfMusic_destroy(game->background.music.music);
}

void credits_destroyer(game_t *game)
{
    sfSprite_destroy(game->credit.button[0].sprite);
    sfText_destroy(game->credit.button[0].text);
    for (int i = 0; i < 5; i++) {
        sfText_destroy(game->credit.text[i]);
    }
}

void pause_menu_destroyer(game_t *game)
{
    sfSprite_destroy(game->pause.button[0].sprite);
    sfSprite_destroy(game->pause.button[1].sprite);
    sfSprite_destroy(game->pause.button[2].sprite);
    sfSprite_destroy(game->pause.button[3].sprite);
    sfText_destroy(game->pause.button[0].text);
    sfText_destroy(game->pause.button[1].text);
    sfText_destroy(game->pause.button[2].text);
    sfText_destroy(game->pause.button[3].text);
}

void destroy_all(game_t *game)
{
    init_menu_destroyer(game);
    music_destroyer(game);
    credits_destroyer(game);
    pause_menu_destroyer(game);
    destroy_other(game);
}