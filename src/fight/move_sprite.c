/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** move_sprite.c
*/

#include "rpg.h"

void move_life_simple(game_t *game, int i)
{
    game->obj.fight.life[i].rect.left += 204;
    sfSprite_setTextureRect(game->obj.fight.life[i].sprite, game->obj.fight.life[i].rect);
}

void move_rect_attack(game_t *game, int i)
{
    game->obj.fight.attack[i].time = sfClock_getElapsedTime(game->obj.fight.attack[i].clock);
    game->obj.fight.attack[i].sec = game->obj.fight.attack[i].time.microseconds / 1000000.0;

    if (game->obj.fight.attack[i].sec > 0.18) {
        game->obj.fight.attack[i].rect.left += 512;
        if (game->obj.fight.attack[i].rect.left > (512 * 5.9))
            game->obj.fight.attack[i].rect.left = 0;
        sfSprite_setTextureRect(game->obj.fight.attack[i].sprite, game->obj.fight.attack[i].rect);
        sfClock_restart(game->obj.fight.attack[i].clock);
    }
}