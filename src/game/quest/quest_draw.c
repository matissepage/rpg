/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** quest_draw.c
*/

#include "rpg.h"

void draw_1quest(game_t *g)
{
    sfVector2f new_pos = sfView_getCenter(g->window.view_game);
    sfVector2f poste = init_vector(0, 0);

    new_pos.x = new_pos.x + 260;
    new_pos.y = new_pos.y - 300;
    poste.x = new_pos.x;
    poste.y = new_pos.y + 50;
    sfRectangleShape_setPosition(BUILD_QUEST.info, new_pos);
    sfRenderWindow_drawRectangleShape(W, BUILD_QUEST.info, NULL);
    sfRenderWindow_drawText(W, BUILD_QUEST.quest[0], NULL);
    sfText_setPosition(BUILD_QUEST.quest[0], poste);
}

void manage_drawquest(game_t *g)
{
    if (BUILD_QUEST.etat == 0)
        return;
    if (BUILD_QUEST.etat == 1) {
        draw_1quest(g);
        return;
    }
    if (BUILD_QUEST.etat == 2) {
        return;
    }
    if (BUILD_QUEST.etat == 3) {
        return;
    }
}
