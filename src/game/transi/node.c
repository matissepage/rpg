/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** node.c
*/

#include "rpg.h"

my_data_t create_datatransi(char *path, sfVector2f spawn, sfVector2f dest,
int time)
{
    my_data_t data;
    sfIntRect rect = initrect(16 * 8, 16, 16, 32);
    data.sprite = create_sprite(path);
    if (time == 31) {
        sfSprite_setTextureRect(data.sprite, rect);
        sfSprite_setScale(data.sprite, init_vector(2, 2));
    }
    data.pos = spawn;
    data.dest = dest;
    data.data_int = (time * 2);
    data.state = FALSE;
    data.clock = sfClock_create();
    return (data);
}

void add_pnjtransi(my_list_t **list, my_data_t data)
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