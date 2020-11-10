/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** manage_attack.c
*/

#include "rpg.h"

void choose_atk(game_t *game)
{
    if (test_hitbox_o(game->var.pos_mouse_click, \
    G(game->obj.fight.buttonatk[0].sprite), 90, 90) == 1) {
        game->obj.fight.atk = 1;
    }
    if (test_hitbox_o(game->var.pos_mouse_click, \
    G(game->obj.fight.buttonatk[1].sprite), 90, 90) == 1) {
        game->obj.fight.atk = 2;
    }
    if (test_hitbox_o(game->var.pos_mouse_click, \
    G(game->obj.fight.buttonatk[2].sprite), 90, 90) == 1) {
        game->obj.fight.atk = 3;
    }
    if (test_hitbox_o(game->var.pos_mouse_click, \
    G(game->obj.fight.buttonatk[3].sprite), 100, 100) == 1) {
        game->obj.fight.atk = 4;
    }
}

void fight_animation(game_t *game, int i)
{
    move_rect_attack(game, i);
    sfRenderWindow_drawSprite(game->window.window, \
    game->obj.fight.attack[i].sprite, NULL);
    move_fireball_player(game, i);
}

int manage_attack_fight(game_t *game)
{
    choose_atk(game);
    if (game->obj.fight.atk == 1) {
        game->obj.fight.tmp = WATER;
        fight_animation(game, 0);
        return (1);
    }
    if (game->obj.fight.atk == 2) {
        game->obj.fight.tmp = FIRE;
        fight_animation(game, 1);
        return (1);
    }
    if (game->obj.fight.atk == 3) {
        game->obj.fight.tmp = MANA;
        fight_animation(game, 2);
        return (1);
    }
    if (game->obj.fight.atk == 4) {
        game->obj.fight.win = 10;
    }
    return (0);
}