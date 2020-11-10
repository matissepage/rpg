/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** link inventory
*/

#include "rpg.h"

node_t *create_node(char *str)
{
    node_t *new_node = malloc(sizeof(*new_node));
    int i = 0;
    char **tab = my_str_to_word_array(str, &i);

    new_node->name = pars_data_invt(tab, "name");
    new_node->id = pars_data_invt(tab, "id");
    new_node->path = pars_data_invt(tab, "path");
    new_node->gold = my_getnbr(pars_data_invt(tab, "gold"));
    new_node->rect.left = my_getnbr(pars_data_invt(tab, "rect_left"));
    new_node->rect.width = my_getnbr(pars_data_invt(tab, "rect_width"));
    new_node->rect.height = my_getnbr(pars_data_invt(tab, "rect_height"));
    new_node->rect.top = my_getnbr(pars_data_invt(tab, "rect_top"));
    new_node->dammage = my_getnbr(pars_data_invt(tab, "dammage"));
    new_node->etat = 0;
    init_item_sprite(&new_node->sprite, new_node->path, new_node->rect);
    sfSprite_setScale(new_node->sprite.sprite, (sfVector2f){2.3, 2.3});
    new_node->next = NULL;
    for (int j = 0; tab[j]; j++)
        free(tab[j]);
    return (new_node);
}

link_t *init_list(void)
{
    link_t *link = malloc(sizeof(link));

    if (!link)
        return (NULL);
    link->head = NULL;
    return (link);
}

void display_invt_link(link_t *link)
{
    node_t *current = link->head;

    while (current != NULL) {
        current = current->next;
    }
}

void add_node_invt(char *str, link_t *link)
{
    node_t *current = NULL;

    if (link->head == NULL) {
        link->head = create_node(str);
    }
    else {
        current = link->head;
        while (current->next != NULL)
            current = current->next;
        current->next = create_node(str);
    }
}

void delete_node(int size, link_t *link)
{
    node_t *current = link->head;
    node_t *prev = current;
    int i = 0;

    while (current != NULL) {
        if (i == size) {
            prev->next = current->next;
            if (current == link->head)
                link->head = current->next;
            free(current);
            return;
        }
        prev = current;
        current = current->next;
        i += 1;
    }
}