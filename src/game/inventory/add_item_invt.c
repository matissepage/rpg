/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** item
*/

#include "rpg.h"

node_t *create_item_node(item_t item)
{
    node_t *node = malloc(sizeof(*node));

    node->dammage = item.dammage;
    node->gold = item.gold;
    node->id = item.id;
    node->name = item.name;
    node->path = item.path;
    node->rect = item.rect;
    node->etat = 0;
    init_item_sprite(&node->sprite, node->path, node->rect);
    sfSprite_setScale(node->sprite.sprite, (sfVector2f){4, 4});
    node->next = NULL;
    return (node);
}

void add_node_item_invt(item_t item, link_t *link)
{
    node_t *current = NULL;

    if (link->head == NULL) {
        link->head = create_item_node(item);
    }
    else {
        current = link->head;
        while (current->next != NULL)
            current = current->next;
        current->next = create_item_node(item);
    }
}
