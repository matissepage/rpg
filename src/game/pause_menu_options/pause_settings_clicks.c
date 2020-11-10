/*
** EPITECH PROJECT, 2020
** pause_settings_clicks.c
** File description:
** pause_settings_clicks.c
*/

#include "rpg.h"

void change_vol(game_t *game, int add)
{
    if ((game->pause_s.index == 10 && add != -1)
    || (game->pause_s.index == 0 && add != 1))
        return;
    game->pause_s.index += add;
    sfMusic_setVolume(game->background.music.music, \
    my_getnbr(game->pause_s.vol[game->pause_s.index]));
    sfText_setString(game->pause_s.button[1].text, \
    game->pause_s.vol[game->pause_s.index]);
}

void check_pause_settings_click2(game_t *game)
{
    if (test_hitbox_o(game->var.pos_mouse_click, \
    sfSprite_getPosition(game->pause_s.sprite[1].sprite), 107, 109) == 1) {
        change_vol(game, +1);
        game->var.pos_mouse_click = init_vector(-100, -100);
    }

    if (test_hitbox_o(game->var.pos_mouse_click, \
    sfSprite_getPosition(game->pause_s.sprite[2].sprite), 107, 109) == 1) {
        change_vol(game, -1);
        game->var.pos_mouse_click = init_vector(-100, -100);
    }
}

void check_pause_settings_click(game_t *game)
{
    if (test_hitbox_o(game->var.pos_mouse_click, \
    sfSprite_getPosition(game->pause_s.button[0].sprite), 340, 88) == 1) {
        move_rect(&game->pause_s.rect[0], 21, 42);
        sfSprite_setTextureRect(game->pause_s.sprite[0].sprite, \
        game->pause_s.rect[0]);
        if (game->var.music) {
            game->var.music = sfFalse;
            sfMusic_pause(game->background.music.music);
            sfMusic_pause(game->background.music2.music);
        } else {
            game->var.music = sfTrue;
            sfMusic_play(game->background.music.music);
        }
        game->var.pos_mouse_click = init_vector(-100, -100);
    } else if (test_hitbox_o(game->var.pos_mouse_click, \
    sfSprite_getPosition(game->pause_s.button[2].sprite), 340, 88) == 1) {
        game->var.pos_mouse_click = init_vector(-100, -100);
        game->etat = PAUSE;
    }
    check_pause_settings_click2(game);
}