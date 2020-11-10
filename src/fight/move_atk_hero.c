/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** move_sprite.c
*/

#include "rpg.h"

void move_fireball_player(game_t *g, int i)
{
    if (g->obj.fight.attack[i].vector.y > 0) {
        g->obj.fight.attack[i].vector.x += 20;
        g->obj.fight.attack[i].vector.y -= 13;
        sfSprite_setPosition(g->obj.fight.attack[i].sprite, g->obj.fight.attack[i].vector);
    }
    if (g->obj.fight.attack[i].vector.x == 1620) {
        gest_life(g);
    }
}

void reset_pos_fireball_player(game_t *g)
{
    g->obj.fight.attack[0].vector.x = 400;
    g->obj.fight.attack[0].vector.y = 1000;
    g->obj.fight.attack[1].vector.x = 400;
    g->obj.fight.attack[1].vector.y = 1000;
    g->obj.fight.attack[2].vector.x = 400;
    g->obj.fight.attack[2].vector.y = 1000;
    sfSprite_setPosition(g->obj.fight.attack[0].sprite, g->obj.fight.attack[0].vector);
    sfSprite_setPosition(g->obj.fight.attack[1].sprite, g->obj.fight.attack[1].vector);
    sfSprite_setPosition(g->obj.fight.attack[2].sprite, g->obj.fight.attack[2].vector);
}

