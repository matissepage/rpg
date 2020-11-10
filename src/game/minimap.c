/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** minimap.c
*/

#include "rpg.h"

void analyse_eventmap(game_t *g, sfEvent evt)
{
    if (evt.key.code == sfKeyTab &&
    g->my_event.is_released == 1) {
        g->obj.status_minimap = g->obj.status_minimap == TRUE ? FALSE : TRUE;
        consolelog(OTHER, "Mini Map change value !");
        g->my_event.is_released = 0;
        return;
    }
}

void minimap_displaymanage(game_t *g)
{
    sfVector2f new_pos = sfView_getCenter(g->window.view_game);
    sfVector2f poste = init_vector(0, 0);

    if (g->obj.status_minimap == TRUE) {
        new_pos.x = new_pos.x + 260;
        new_pos.y = new_pos.y - 300;
        poste.x = new_pos.x;
        poste.y = new_pos.y + 50;
        sfSprite_setPosition(g->obj.mini_map_wood.sprite,
        init_vector(poste.x - 860, poste.y - 50));
        sfRenderWindow_drawSprite(W, g->obj.mini_map_wood.sprite, NULL);
        sfRenderWindow_setView(W, g->window.mini_map);
        draw_pnj(g);
        display_map(g);
    }
}