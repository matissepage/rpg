/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** gest_life.c
*/

#include "rpg.h"

void gest_life(game_t *game)
{
    if (game->obj.fight.ennemis.type != game->obj.fight.tmp) {
        game->obj.fight.ennemis.pv -= game->player.damage;
        sfText_setString(game->obj.fight.ennemis.text, my_itc(game->obj.fight.ennemis.pv));
    }
    if (game->obj.fight.ennemis.pv <= 0)
        game->obj.fight.win = TRUE;
}

void gest_life_ennemy(game_t *game)
{
    if (game->player.life <= 0) {
        game->obj.fight.win = FALSE;
    }
    game->player.life -= game->obj.fight.ennemis.damage;
    sfText_setString(game->obj.fight.life_player, my_itc(game->player.life));
}