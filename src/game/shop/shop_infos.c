/*
** EPITECH PROJECT, 2020
** shop_infos.c
** File description:
** shop_infos.c
*/

#include "rpg.h"

void display_infos_items(game_t *game, node_t *node)
{
    char *name = NULL;
    char *price = NULL;
    char *damages = NULL;

    name = my_strdup(node->name);
    price = my_strdup(my_itc(node->gold));
    damages = my_strdup(my_itc(node->dammage));
    sfText_setString(game->shop.infos[0], name);
    sfText_setString(game->shop.infos[1], price);
    sfText_setString(game->shop.infos[3], damages);
    free(name);
    free(price);
    free(damages);
}

void reset_infos_items(game_t *game)
{
    sfText_setString(game->shop.infos[0], "");
    sfText_setString(game->shop.infos[1], "");
    sfText_setString(game->shop.infos[3], "");
}

void display_checked_item_select(game_t *g, int x, int y)
{
    node_t *node = g->obj.item->head;
    sfVector2f vec;

    for (int i = 0; node != NULL; i++) {
        vec = sfSprite_getPosition(node->sprite.sprite);
        if ((float)x > vec.x && (float)x < vec.x + 32*3) {
            if ((float)y > vec.y && (float)y < vec.y + 32*3) {
                display_infos_items(g, node);
                break;
            } else {
                reset_infos_items(g);
            }
        } else {
            reset_infos_items(g);
        }
        node = node->next;
    }
}