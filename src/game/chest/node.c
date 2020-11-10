/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** node.c
*/

#include "rpg.h"

void change_datachest(my_list_t **list, int id)
{
    int id_local = 0;

    for (my_list_t *tmp = (*list); tmp; tmp = tmp->next) {
        if (id == id_local) {
            tmp->data.open = TRUE;
            return;
        }
        id_local++;
    }
}

my_data_t create_datachest(int money, char *object, sfVector2f pos)
{
    my_data_t data;
    int size = my_strlen(object) + 1;

    data.str = malloc(sizeof(char) * size);
    data.sprite = create_sprite(PATH_CHEST);
    data.rect = initrect(0, 0, 32 / 2, 12);
    sfSprite_setTextureRect(data.sprite, data.rect);
    sfSprite_setPosition(data.sprite, pos);
    sfSprite_setScale(data.sprite, (sfVector2f){2, 2});
    data.str = my_strcpy(data.str, object);
    data.pos = pos;
    data.data_int = money;
    data.open = FALSE;
    return (data);
}

void add_chest(my_list_t **list, my_data_t data)
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