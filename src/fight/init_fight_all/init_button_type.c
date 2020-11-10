/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_button_type.c
*/

#include "rpg.h"

void init_water_type(game_t *g)
{
    g->obj.fight.type[0].vector.x = 500;
    g->obj.fight.type[0].vector.y = 9;
    char *str = "assets/fight/buttonatk.png";
    g->obj.fight.type[0].sprite = create_sprite(str);
    g->obj.fight.type[0].rect = (sfIntRect){200, 0, 100, 100};
    sfSprite_setScale(g->obj.fight.type[0].sprite, (sfVector2f){0.7, 0.7});
    SFTR(g->obj.fight.type[0].sprite, g->obj.fight.type[0].rect);
    g->obj.fight.type[0].clock = sfClock_create();
    SFSP(g->obj.fight.type[0].sprite, g->obj.fight.type[0].vector);
}

void init_fire_type(game_t *g)
{
    int x = 500;
    int y = 9;
    sfVector2f tmp = init_vector(x, y);
    char *str = "assets/fight/buttonatk.png";
    g->obj.fight.type[1].sprite = create_sprite(str);
    g->obj.fight.type[1].rect = (sfIntRect){100, 0, 100, 100};
    sfSprite_setScale(g->obj.fight.type[1].sprite, (sfVector2f){0.7, 0.7});
    SFTR(g->obj.fight.type[1].sprite, g->obj.fight.type[1].rect);
    g->obj.fight.type[1].clock = sfClock_create();
    SFSP(g->obj.fight.type[1].sprite, tmp);
}

void init_purple_type(game_t *g)
{
    int x = 500;
    int y = 9;
    sfVector2f tmp = init_vector(x, y);
    char *str = "assets/fight/buttonatk.png";
    g->obj.fight.type[2].sprite = create_sprite(str);
    g->obj.fight.type[2].rect = (sfIntRect){400, 100, 100, 100};
    sfSprite_setScale(g->obj.fight.type[2].sprite, (sfVector2f){0.7, 0.7});
    SFTR(g->obj.fight.type[2].sprite, g->obj.fight.type[2].rect);
    g->obj.fight.type[2].clock = sfClock_create();
    SFSP(g->obj.fight.type[2].sprite, tmp);
}

void init_all_type(game_t *game)
{
    init_water_type(game);
    init_fire_type(game);
    init_purple_type(game);
}