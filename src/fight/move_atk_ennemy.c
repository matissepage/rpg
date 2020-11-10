/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** move_sprite3.c
*/


#include "rpg.h"

void move_fireball_ennemy(game_t *g)
{
    if (g->obj.fight.attack_ennemis[0].vector.x < 1920) {
        g->obj.fight.attack_ennemis[0].vector.x -= 15;
        g->obj.fight.attack_ennemis[0].vector.y += 10;
        sfSprite_setPosition(g->obj.fight.attack_ennemis[0].sprite, g->obj.fight.attack_ennemis[0].vector);
    }
    if (g->obj.fight.attack_ennemis[0].vector.x == 590) {
        gest_life_ennemy(g);
    }
}

void reset_pos_fireball_ennemy(game_t *g)
{
    g->obj.fight.attack_ennemis[0].vector.x = 1730;
    g->obj.fight.attack_ennemis[0].vector.y = 350;
    sfSprite_setPosition(g->obj.fight.attack[1].sprite, g->obj.fight.attack[1].vector);
}