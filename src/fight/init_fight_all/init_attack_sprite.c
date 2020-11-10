/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_attack_sprite.c
*/

#include "rpg.h"

void init_attack_player_water(game_t *g)
{
    g->obj.fight.attack[0].vector.x = 400;
    g->obj.fight.attack[0].vector.y = 1000;
    char *str = "assets/fight/attack/boule_water.png";
    g->obj.fight.attack[0].sprite = create_sprite(str);
    g->obj.fight.attack[0].rect = (sfIntRect){0, 0, 512, 512};
    g->obj.fight.attack[0].clock = sfClock_create();
    sfSprite_setScale(g->obj.fight.attack[0].sprite, (sfVector2f){0.5, 0.5});
    SFTR(g->obj.fight.attack[0].sprite, g->obj.fight.attack[0].rect);
    SFSP(g->obj.fight.attack[0].sprite, g->obj.fight.attack[0].vector);
    sfSprite_rotate(g->obj.fight.attack[0].sprite, 320);
}

void init_attack_player_fire(game_t *g)
{
    g->obj.fight.attack[1].vector.x = 400;
    g->obj.fight.attack[1].vector.y = 1000;
    char *str = "assets/fight/attack/boule_feu.png";
    g->obj.fight.attack[1].sprite = create_sprite(str);
    g->obj.fight.attack[1].rect = (sfIntRect){0, 0, 512, 512};
    g->obj.fight.attack[1].clock = sfClock_create();
    sfSprite_setScale(g->obj.fight.attack[1].sprite, (sfVector2f){0.5, 0.5});
    SFTR(g->obj.fight.attack[1].sprite, g->obj.fight.attack[1].rect);
    SFSP(g->obj.fight.attack[1].sprite, g->obj.fight.attack[1].vector);
    sfSprite_rotate(g->obj.fight.attack[1].sprite, 320);
}


void init_attack_player_mana(game_t *g)
{
    g->obj.fight.attack[2].vector.x = 400;
    g->obj.fight.attack[2].vector.y = 1000;
    char *str = "assets/fight/attack/boule_mana.png";
    g->obj.fight.attack[2].sprite = create_sprite(str);
    g->obj.fight.attack[2].rect = (sfIntRect){0, 0, 512, 512};
    g->obj.fight.attack[2].clock = sfClock_create();
    sfSprite_setScale(g->obj.fight.attack[2].sprite, (sfVector2f){0.5, 0.5});
    SFTR(g->obj.fight.attack[2].sprite, g->obj.fight.attack[2].rect);
    SFSP(g->obj.fight.attack[2].sprite, g->obj.fight.attack[2].vector);
    sfSprite_rotate(g->obj.fight.attack[2].sprite, 320);
}