/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_button_attack.c
*/

#include "rpg.h"

void init_water_button(game_t *g)
{
    g->obj.fight.buttonatk[0].vector.x = 1440;
    g->obj.fight.buttonatk[0].vector.y = 800;
    char *str = "assets/fight/buttonatk.png";
    g->obj.fight.buttonatk[0].sprite = create_sprite(str);
    g->obj.fight.buttonatk[0].rect = (sfIntRect){200, 0, 100, 100};
    SFTR(g->obj.fight.buttonatk[0].sprite, g->obj.fight.buttonatk[0].rect);
    g->obj.fight.buttonatk[0].clock = sfClock_create();
    SFSP(g->obj.fight.buttonatk[0].sprite, g->obj.fight.buttonatk[0].vector);
}

void init_fire_button(game_t *g)
{
    int x = 1550;
    int y = 800;
    sfVector2f tmp = init_vector(x, y);
    char *str = "assets/fight/buttonatk.png";
    g->obj.fight.buttonatk[1].sprite = create_sprite(str);
    g->obj.fight.buttonatk[1].rect = (sfIntRect){100, 0, 100, 100};
    SFTR(g->obj.fight.buttonatk[1].sprite, g->obj.fight.buttonatk[1].rect);
    g->obj.fight.buttonatk[1].clock = sfClock_create();
    SFSP(g->obj.fight.buttonatk[1].sprite, tmp);
}

void init_purple_button(game_t *g)
{
    int x = 1660;
    int y = 800;
    sfVector2f tmp = init_vector(x, y);
    char *str = "assets/fight/buttonatk.png";
    g->obj.fight.buttonatk[2].sprite = create_sprite(str);
    g->obj.fight.buttonatk[2].rect = (sfIntRect){400, 100, 100, 100};
    SFTR(g->obj.fight.buttonatk[2].sprite, g->obj.fight.buttonatk[2].rect);
    g->obj.fight.buttonatk[2].clock = sfClock_create();
    SFSP(g->obj.fight.buttonatk[2].sprite, tmp);
}

void init_leave_button(game_t *g)
{
    int x = 1550;
    int y = 910;
    sfVector2f tmp = init_vector(x, y);
    char *str = "assets/fight/leave.png";
    g->obj.fight.buttonatk[3].sprite = create_sprite(str);
    g->obj.fight.buttonatk[3].rect = (sfIntRect){0, 0, 150, 50};
    sfSprite_setScale(g->obj.fight.buttonatk[3].sprite, (sfVector2f){0.7, 0.7});
    SFTR(g->obj.fight.buttonatk[3].sprite, g->obj.fight.buttonatk[3].rect);
    g->obj.fight.buttonatk[3].clock = sfClock_create();
    SFSP(g->obj.fight.buttonatk[3].sprite, tmp);
}

void init_buttonatk_fight(game_t *game)
{
    init_water_button(game);
    init_fire_button(game);
    init_purple_button(game);
    init_leave_button(game);
    init_bg_button(game);
    init_bg_type(game);
}