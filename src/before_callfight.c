/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** before_callfight.c
*/

#include "rpg.h"

void inlunch_animationopen(game_t *g, sfSprite *sprite1, sfSprite *sprite2)
{

    sfRenderWindow_clear(W, sfBlack);
    display_fight(g);
    sfRenderWindow_drawSprite(W, sprite1, NULL);
    sfRenderWindow_drawSprite(W, sprite2, NULL);
    sfRenderWindow_display(W); 
}

void lunch_animationopen(game_t *g)
{
    sfClock *clock = sfClock_create();
    sfSprite *sprite1 = create_sprite("./assets/loadbg.png");
    sfSprite *sprite2 = create_sprite("./assets/loadbgrev.png");
    sfVector2f pos1 = init_vector(0, 0);
    sfVector2f pos2 = init_vector(1920/2, 0);

    while (sfRenderWindow_isOpen(g->window.window) && pos2.x < 1920) {
        inlunch_animationopen(g, sprite1, sprite2);
        sfSprite_setPosition(sprite1, pos1);
        sfSprite_setPosition(sprite2, pos2);
        if (sfClock_getElapsedTime(clock).microseconds / 10000 > 1) {
            pos1.x -= 10;
            pos2.x += 10;
            sfClock_restart(clock);
        }
    }
    sfSprite_destroy(sprite1);
    sfSprite_destroy(sprite2);
    sfClock_destroy(clock);
}