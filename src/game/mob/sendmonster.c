/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** sendmonster.c
*/

#include "rpg.h"

char *genere_pathmob(int id)
{
    if (id == 1)
        return ("./assets/mob1.png");
    if (id == 2)
        return ("assets/fight/ennemies/boss_lvl1.png");
    if (id == 3)
        return ("./assets/mob2.png");
    return (NULL);
}

sprite_t sendmonster(int id, int pv, int damage, int type)
{
    sprite_t new_mob;
    char *path = genere_pathmob(id);

    if (id != 3) {
        new_mob.vector.x = 1380;
        new_mob.vector.y = 180;
    } else {
        new_mob.vector.x = 1020;
        new_mob.vector.y = 180;
    }
    new_mob.pv = pv;
    new_mob.damage = damage;
    new_mob.type = type;
    new_mob.clock = sfClock_create();
    new_mob.sprite = create_sprite(path);
    if (id == 2) {
        new_mob.rect = (sfIntRect){0, 0, 100, 80};
        sfSprite_setTextureRect(new_mob.sprite, new_mob.rect);
    }
    return (new_mob);
}