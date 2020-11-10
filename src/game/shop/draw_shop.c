/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** draw_shop
*/

#include "rpg.h"

void change_scale_item(game_t *g)
{
    node_t *node = g->obj.item->head;

    for (; node != NULL; node = node->next)
        sfSprite_setScale(node->sprite.sprite, (sfVector2f){5, 5});
}

void place_item_shop(game_t *g)
{
    node_t *node = g->obj.item->head;
    sfVector2f vec = {230, 190};
    if (node == NULL) return;
    for (int i = 1; node != NULL; node = node->next, i++) {
        node->sprite.vector = vec;
        sfSprite_setPosition(node->sprite.sprite, node->sprite.vector);
        vec.x += 128;
        if (i % 3 == 0) {
            vec.x = 230;
            vec.y += 128;
            node->sprite.vector.x = vec.x;
        }
    }
}

void display_checked_item_select(game_t *g, int x, int y);

void draw_item_shop(game_t *game)
{
    node_t *node = NULL;

    node = game->obj.item->head;
    for (int i = 0; node != NULL; node = node->next, i++) {
        if (i == 18) break;
        D(W_g, node->sprite.sprite, NULL);
    }
    D(game->window.window, game->shop.gold.sprite, NULL);
    sfRenderWindow_drawSprite(game->window.window, \
    game->shop.information.sprite, NULL);
    sfRenderWindow_drawText(game->window.window, game->shop.infos[0], NULL);
    sfRenderWindow_drawText(game->window.window, game->shop.infos[1], NULL);
    sfRenderWindow_drawText(game->window.window, game->shop.infos[2], NULL);
    sfRenderWindow_drawText(game->window.window, game->shop.infos[3], NULL);
    display_checked_item_select(game, game->var.pos_mouse.x, \
    game->var.pos_mouse.y);
}