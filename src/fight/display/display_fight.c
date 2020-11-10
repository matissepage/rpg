/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** display_fight.c
*/

#include "rpg.h"

void display_hero(game_t *g)
{
    D(W, g->player.player.cloth, NULL);
    D(W, g->player.player.cape, NULL);
    D(W, g->player.player.skin, NULL);
    D(W, g->player.player.hair, NULL);
}

void display_ennemis(game_t *g, sfSprite *sprite)
{
    SRWDS(g->window.window, sprite, NULL);
}

void display_life(game_t *g)
{
    for (int i = 0; i < 2; i++)
        SRWDS(g->window.window, g->obj.fight.life[i].sprite, NULL);
}

void display_attack(game_t *g, int i)
{
    SRWDS(g->window.window, g->obj.fight.attack[i].sprite, NULL);
}

void display_fight(game_t *game)
{
    sfRenderWindow_clear(game->window.window, sfBlack);
    SRWDS(game->window.window, game->obj.fight.bg_fight.sprite, NULL);
    display_ennemis(game, game->obj.fight.ennemis.sprite);
    display_hero(game);
    display_life(game);
    display_bg_button(game);
    manage_type(game);
    display_button_atk(game);
    sfRenderWindow_drawText(game->window.window, game->obj.fight.warning, NULL);
    sfRenderWindow_drawText(game->window.window, game->obj.fight.ennemis.text, NULL);
    sfRenderWindow_drawText(game->window.window, game->obj.fight.life_player, NULL);
}