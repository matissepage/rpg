/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_hero_fight.c
*/

#include "rpg.h"

void init_life_text_hero(game_t *game)
{
    char *msg = my_itc(game->player.life);
    int x = 300;
    int y = 780;
    char *pathfont = "./assets/fonts/Pacifico.ttf";
    game->obj.fight.life_player = create_text(pathfont, msg, x, y);
}

void init_life_hero(game_t *g)
{
    g->obj.fight.life[0].vector.x = 200;
    g->obj.fight.life[0].vector.y = 750;
    char *str = "assets/fight/life/free_life.png";
    g->obj.fight.life[0].sprite = create_sprite(str);
    g->obj.fight.life[0].rect = (sfIntRect){0, 0, 512, 173};
    g->obj.fight.life[0].clock = sfClock_create();
    sfSprite_setScale(g->obj.fight.life[0].sprite, (sfVector2f){0.5, 0.5});
    SFTR(g->obj.fight.life[0].sprite, g->obj.fight.life[0].rect);
    SFSP(g->obj.fight.life[0].sprite, g->obj.fight.life[0].vector);
    init_life_text_hero(g);
}

void init_player_fight(game_t *g)
{
    int x = 500; 
    int y = 800;

    sfVector2f tmp = init_vector(x, y);
    SFTR(g->obj.fight.bg_fight.sprite, g->obj.fight.bg_fight.rect);
    SFTR(g->player.player.cloth, initrect(192, 0, 32, 88));
    SFTR(g->player.player.cape, initrect(192, 0, 32, 88));
    SFTR(g->player.player.skin, initrect(192, 0, 32, 88));
    SFTR(g->player.player.hair, initrect(192, 0, 32, 88));
    SFSP(g->player.player.cape, tmp);
    SFSP(g->player.player.cloth, tmp);
    SFSP(g->player.player.eyes, tmp);
    SFSP(g->player.player.hair, tmp);
    SFSP(g->player.player.skin, tmp);
    SFSS(g->player.player.cape, init_vector(5, 5));
    SFSS(g->player.player.cloth, init_vector(5, 5));
    SFSS(g->player.player.eyes, init_vector(5, 5));
    SFSS(g->player.player.hair, init_vector(5, 5));
    SFSS(g->player.player.skin, init_vector(5, 5));
    init_life_hero(g);
}
