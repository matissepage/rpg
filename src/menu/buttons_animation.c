/*
** EPITECH PROJECT, 2020
** buttons_animation.c
** File description:
** buttons_animation.c
*/

#include "rpg.h"

void is_mouse_on_btn(game_t *game, sfSprite *sprite, sfIntRect rect)
{
    if (test_hitbox_o(game->var.pos_mouse, sfSprite_getPosition(sprite),\
    340, 88) == 1)
        anim_button(game, sprite, rect);
    else
        reset_anim_button(sprite, rect);
}

sfIntRect move_my_rect(sfIntRect rect, int basic, int max)
{
    if (rect.left == max - basic)
        return (rect);
    else
        rect.left += basic;
    return (rect);
}

void anim_button(game_t *game, sfSprite *sprite, sfIntRect rect)
{
    btn_anim.time = sfClock_getElapsedTime(btn_anim.clock);
    btn_anim.seconds = btn_anim.time.microseconds / 100000.0;
    if (btn_anim.seconds > 0.5) {
        if (rect.left < 1010) {
            rect = move_my_rect(rect, 340, 1020);
            sfSprite_setTextureRect(sprite, rect);
        }
        sfClock_restart(btn_anim.clock);
    }
}

void reset_anim_button(sfSprite *sprite, sfIntRect rect)
{
    rect = (sfIntRect){0, 0, 340, 88};
    sfSprite_setTextureRect(sprite, rect);
}