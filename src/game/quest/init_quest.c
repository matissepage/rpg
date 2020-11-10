/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_quest.c
*/

#include "rpg.h"

void init_linkedquest(game_t *g)
{
    g->obj.quest.all_quest = NULL;
    fill_quest(g, 1);
    g->obj.quest.can_pressenter = FALSE;
    g->obj.quest.press_enter = FALSE;
}

void init_textquest(game_t *g)
{
    BUILD_QUEST.quest[0] = create_text(PATH_FONT, NONE, 10, 10);
    BUILD_QUEST.quest[1] = create_text(PATH_FONT, NONE, 10, 10);
    BUILD_QUEST.quest[2] = create_text(PATH_FONT, NONE, 10, 10);
    BUILD_QUEST.quest[3] = create_text(PATH_FONT, NONE, 10, 10);
    BUILD_QUEST.first_quest = sfText_create();
}

void init_quest(game_t *g)
{
    sfVector2f size = init_vector(300, 150);
    sfColor color = sfColor_fromRGBA(4, 181, 253, 150);

    BUILD_QUEST.etat = 0;
    BUILD_QUEST.info = sfRectangleShape_create();
    sfRectangleShape_setSize(BUILD_QUEST.info, size);
    sfRectangleShape_setFillColor(BUILD_QUEST.info, color);
    init_textquest(g);
    init_linkedquest(g);
    init_charquest(g);
    init_questactu(g);
}