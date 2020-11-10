/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** move_pnj.c
*/

#include "rpg.h"
#include <math.h>

sfVector2f calc_newvel(sfVector2f start, sfVector2f target, int speed)
{
    sfVector2f ret;
    float a = 0;
    float b = 0;
    float c = 0;

    a = target.y - start.y;
    b = target.x - start.x;
    c = sqrtf(a * a + b * b);
    ret.y = a / c * speed;
    ret.x = b / c * speed;
    return (ret);
}

sfVector2f where_ispnj(game_t *g)
{
    return (sfSprite_getPosition(g->obj.quest.pnj_quest[0].sprite));
}

void setpospnj(game_t *g, int id, sfVector2f vec)
{
    my_list_t *tmp = BUILD_QUEST.all_quest;

    while (tmp) {
        if (tmp->data_quest.id == id) {
            tmp->data_quest.x = vec.x;
            tmp->data_quest.y = vec.y;
            sfSprite_setPosition(g->obj.quest.pnj_quest[0].sprite, vec);
            return;
        }
        tmp = tmp->next;
    }
}

void move_allpnj(game_t *g)
{
    my_list_t *tmp = BUILD_QUEST.animation_on;
    sfVector2f vec;
    sfVector2f vec1;
    int id = 0;

    while (tmp) {
        vec = where_ispnj(g);
        if (vec.x == tmp->animation.where.x && \
            vec.y == tmp->animation.where.y) {
            remove_node_pos(&BUILD_QUEST.animation_on, id);
            return;
        }
        vec1 = calc_newvel(vec, tmp->animation.where, 1);
        vec.x = vec.x + vec1.x;
        vec.y = vec.y + vec1.y;
        setpospnj(g, tmp->animation.id_pnj, vec);
        id++;
        tmp = tmp->next;
    }
}