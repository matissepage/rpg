/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_charquest.c
*/

#include "rpg.h"

sfVector2f getpos_questchar(game_t *g, int id)
{
    my_list_t *tmp = g->obj.quest.all_quest;
    sfVector2f pos;
    int i = 0;

    while (tmp && i++ != id)
        tmp = tmp->next;
    pos.x = tmp->data_quest.x;
    pos.y = tmp->data_quest.y;
    return (pos);
}

void init_spriteinfopnj(game_t *g)
{
    sfVector2f pos = init_vector(-100, -100);

    g->obj.quest.info_pnj = create_text(PATH_FONT, STR_MSG_PNJ, pos.x, pos.y);
}

void init_spritecharquest(game_t *g)
{
    int nbr = get_nbrquest(g);
    sfIntRect rect = initrect(0, 16, 16, 32);
    char *pathsprite = "./assets/pnj/pnj1.png";

    for (int i = 0; i < nbr; i++) {
        BBUILD[i].sprite = create_sprite(pathsprite);
        sfSprite_setTextureRect(BBUILD[i].sprite, rect);
        sfSprite_setPosition(BBUILD[i].sprite, getpos_questchar(g, i));
        sfSprite_setScale(BBUILD[i].sprite, init_vector(2, 2));
    }
}

void init_charquest(game_t *g)
{
    g->obj.quest.pnj_quest = malloc(sizeof(sprite_t) * get_nbrquest(g));
    init_spriteinfopnj(g);
    init_spritecharquest(g);
}

void remove_charquest(game_t *g)
{
    free(g->obj.quest.pnj_quest);
    free(g->obj.quest.info_pnj);
}