/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_attack_ennemis.c
*/

#include "rpg.h"

void init_ennemis_attack_fire(game_t *g)
{
    g->obj.fight.attack_ennemis[0].vector.x = 170;
    g->obj.fight.attack_ennemis[0].vector.y = 350;
    char *str = "assets/fight/attack/boule_feu.png";
    g->obj.fight.attack_ennemis[0].sprite = create_sprite(str);
    g->obj.fight.attack_ennemis[0].rect = (sfIntRect){0, 0, 512, 512};
    g->obj.fight.attack_ennemis[0].clock = sfClock_create();
    sfSprite_setScale(g->obj.fight.attack_ennemis[0].sprite, (sfVector2f){0.5, 0.5});
    SFTR(g->obj.fight.attack_ennemis[0].sprite, g->obj.fight.attack_ennemis[0].rect);
    SFSP(g->obj.fight.attack_ennemis[0].sprite, g->obj.fight.attack_ennemis[0].vector);
    sfSprite_rotate(g->obj.fight.attack_ennemis[0].sprite, 140);
}