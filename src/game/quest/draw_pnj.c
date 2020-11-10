/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** draw_pnj.c
*/

#include "rpg.h"

void display_pageinfo(game_t *g)
{
    g->etat = g->etat;
    return;
}

void dislay_infoquestpnj(game_t *g, sfVector2f pos)
{
    pos.y -= 50;
    pos.x -= 75;
    sfText_setPosition(g->obj.quest.info_pnj, pos);
    sfRenderWindow_drawText(W, g->obj.quest.info_pnj, NULL);
    g->obj.quest.can_pressenter = TRUE;
}

void draw_pnj(game_t *g)
{
    if (g->obj.quest.press_enter == TRUE)
        display_pageinfo(g);
    for (int i = 0; i < get_nbrquest(g); i++)
        sfRenderWindow_drawSprite(W, g->obj.quest.pnj_quest[i].sprite, NULL);
}