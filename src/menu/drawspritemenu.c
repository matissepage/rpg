/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** drawspritemenu.c
*/

#include "rpg.h"

void drawsprite_menu(game_t *g)
{
    sfRenderWindow_clear(g->window.window, sfBlack);
    sfRenderWindow_drawSprite(g->window.window, g->background.sprite, NULL);
    sfRenderWindow_drawSprite(g->window.window, bkg.buttons[0].sprite, NULL);
    sfRenderWindow_drawSprite(g->window.window, bkg.buttons[1].sprite, NULL);
    sfRenderWindow_drawSprite(g->window.window, bkg.buttons[2].sprite, NULL);
    sfRenderWindow_drawSprite(g->window.window, bkg.buttons[3].sprite, NULL);
    for (int i = 0; i < 4; i++) {
        sfRenderWindow_drawText(g->window.window, bkg.buttons[i].text, NULL);
    }
    for (size_t index = 0; index != PARTICLE_MAX; index++) {
        display_particle(g->window.window, &g->screen.particle[index], \
        g->screen.particle_environment.circle_shape);
    }
    sfRenderWindow_display(g->window.window);
}