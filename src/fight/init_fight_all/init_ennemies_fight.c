/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_ennemies.c
*/

#include "rpg.h"

void init_ennemies_fight(game_t *g)
{
    sfSprite_setScale(g->obj.fight.ennemis.sprite, (sfVector2f){4, 4});
    SFSP(g->obj.fight.ennemis.sprite, g->obj.fight.ennemis.vector);
}

void init_life_ennemies(game_t *g)
{
    g->obj.fight.life[1].vector.x = 1200;
    g->obj.fight.life[1].vector.y = 100;
    char *str = "assets/fight/life/free_life.png";
    g->obj.fight.life[1].sprite = create_sprite(str);
    g->obj.fight.life[1].rect = (sfIntRect){0, 0, 512, 173};
    g->obj.fight.life[1].clock = sfClock_create();
    sfSprite_setScale(g->obj.fight.life[1].sprite, (sfVector2f){0.5, 0.5});
    SFTR(g->obj.fight.life[1].sprite, g->obj.fight.life[1].rect);
    SFSP(g->obj.fight.life[1].sprite, g->obj.fight.life[1].vector);
    init_life_text_ennemie(g);
}

void init_life_text_ennemie(game_t *game)
{
    char *msg = my_itc(game->obj.fight.ennemis.pv);
    int x = 1330;
    int y = 125;
    char *pathfont = "./assets/fonts/Pacifico.ttf";
    game->obj.fight.ennemis.text = create_text(pathfont, msg, x, y);
}