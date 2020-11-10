/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_template.c
*/

#include "rpg.h"

void init_bg_button(game_t *g)
{
    int x = 1370;
    int y = 715;
    sfVector2f tmp = init_vector(x, y);
    char *str = "assets/fight/bg_attack_2.png";
    g->obj.fight.bg_button[0].sprite = create_sprite(str);
    g->obj.fight.bg_button[0].rect = (sfIntRect){0, 0, 1700, 500};
    sfSprite_setScale(g->obj.fight.bg_button[0].sprite, (sfVector2f){0.7, 0.7});
    SFTR(g->obj.fight.bg_button[0].sprite, g->obj.fight.bg_button[0].rect);
    SFSP(g->obj.fight.bg_button[0].sprite, tmp);
}

void init_bg_fight(game_t *g)
{
    char *str = "assets/fight/bg_fight.png";
    g->obj.fight.bg_fight.sprite = create_sprite(str);
    g->obj.fight.bg_fight.rect = (sfIntRect){0, 0, 398, 240};
    sfSprite_setScale(g->obj.fight.bg_fight.sprite, (sfVector2f){5, 4.5});
    SFTR(g->obj.fight.bg_fight.sprite, g->obj.fight.bg_fight.rect);
}

void init_bg_type(game_t *g)
{
    int x = 100;
    int y = -5;
    sfVector2f tmp = init_vector(x, y);
    char *str = "assets/fight/template_atk2.png";
    g->obj.fight.bg_button[1].sprite = create_sprite(str);
    g->obj.fight.bg_button[1].rect = (sfIntRect){0, 0, 1700, 500};
    sfSprite_setScale(g->obj.fight.bg_button[1].sprite, (sfVector2f){0.4, 0.4});
    SFTR(g->obj.fight.bg_button[1].sprite, g->obj.fight.bg_button[1].rect);
    SFSP(g->obj.fight.bg_button[1].sprite, tmp);
}