/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** buy_item
*/

#include "rpg.h"

node_t *cpy_data_node(node_t *node)
{
    node_t *new_node = malloc(sizeof(*new_node));

    new_node->dammage = node->dammage;
    new_node->gold = node->gold;
    new_node->id = node->id;
    new_node->path = node->path;
    new_node->name = node->name;
    new_node->rect = node->rect;
    new_node->etat = node->etat;
    init_item_sprite(&new_node->sprite, new_node->path, new_node->rect);
    sfSprite_setScale(new_node->sprite.sprite, (sfVector2f){4, 4});
    new_node->next = NULL;
    return (new_node);
}

void add_in_invt(link_t *link, node_t *node, game_t *g)
{
    node_t *current = NULL;

    if (g->player.gold < node->gold) {
        my_printf("impossible\n");
        return;
    }
    if (link->head == NULL) {
        link->head = cpy_data_node(node);
    }
    else {
        current = link->head;
        while (current->next != NULL)
            current = current->next;
        current->next = cpy_data_node(node);
    }
    g->player.gold -= node->gold;
    play_on_buy(g);
}

void check_item_select(game_t *g, int x, int y)
{
    node_t *node = g->obj.item->head;
    sfVector2f vec;

    for (int i = 0; node != NULL; i++) {
        vec = sfSprite_getPosition(node->sprite.sprite);
        if ((float)x > vec.x && (float)x < vec.x + 32*3) {
            if ((float)y > vec.y && (float)y < vec.y + 32*3) {
                add_in_invt(g->obj.invt.link, node, g);
                break;
            }
        }
        node = node->next;
    }
}