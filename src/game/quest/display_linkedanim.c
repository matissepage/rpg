/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** display_linkedanim.c
*/

#include "rpg.h"

void remove_popup(my_list_t **list, int position)
{
    my_list_t *tmp1 = NULL;
    my_list_t *tmp2 = (*list);
    my_list_t *tmp3 = NULL;

    if (position == 0) {
        tmp1 = (*list);
        *list = (*list)->next;
        return;
    }
    for (int i = 0; i < position - 1; i += 1) {
        tmp2 = tmp2->next;
    }
    tmp1 = tmp2->next->next;
    tmp3 = tmp2->next;
    tmp2->next = tmp1;
    free (tmp3);
}

my_data_t create_datapopup(int time, char *texte, int state)
{
    my_data_t data;
    sfColor color = sfColor_fromRGBA(255, 255, 255, 150);

    data.state = state;
    data.text = create_text(PATH_FONT, texte, 1920 / 2, 0);
    data.clock = sfClock_create();
    data.data_int = time;
    if (state == TOP) {
        data.sprite = create_sprite(PATH_POPUP);
        sfSprite_setPosition(data.sprite, (sfVector2f) {1920 / 2 - 300, 0});
    } else {
        data.rectangle = sfRectangleShape_create();
        sfRectangleShape_setFillColor(data.rectangle, color);
        sfRectangleShape_setSize(data.rectangle, (sfVector2f){130, 40});
    }
    consolelog(INIT, "Création d'une notification");
    return (data);
}

void add_popup(my_list_t **list, my_data_t data)
{
    my_list_t *elem = malloc(sizeof(my_list_t));
    my_list_t *tmp = *list;

    elem->data = data;
    elem->next = NULL;

    if (!(*list)) {
        *list = elem;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = elem;
}

void display_linkedanim(game_t *g)
{
    int time = 0;
    int pos = 0;
    sfVector2f vec = sfView_getCenter(g->window.view_game);
    vec.y -= 300;
    vec.x -= 400;

    for (my_list_t *tmp = g->obj.anim; tmp; tmp = tmp->next, pos++) {
        if (tmp->data.state == TOP) {
            time = sfClock_getElapsedTime(tmp->data.clock).microseconds / 10000;
            sfSprite_setPosition(tmp->data.sprite, vec);
            vec.x += 180;
            vec.y += 200;
            sfText_setPosition(tmp->data.text, vec);
            D(W, tmp->data.sprite, NULL);
            T(W, tmp->data.text, NULL);
            if (time > (tmp->data.data_int * 100)) {
                sfClock_destroy(tmp->data.clock);
                sfSprite_destroy(tmp->data.sprite);
                sfText_destroy(tmp->data.text);
                remove_popup(&g->obj.anim, pos);
            }
        }
    }
}