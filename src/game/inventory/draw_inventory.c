/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** draw inventory
*/

#include "rpg.h"

void init_pos_item_invt(link_t *link)
{
    node_t *currrent = link->head;
    sfVector2f vector;

    vector.x = 236;
    vector.y = 725;
    if (link->head == NULL) return;
    currrent->sprite.vector.x = vector.x;
    currrent->sprite.vector.y = vector.y;
    for (int i = 0; currrent != NULL; i++) {
        currrent->sprite.vector.x = vector.x;
        currrent->sprite.vector.y = vector.y;
        sfSprite_setPosition(currrent->sprite.sprite, currrent->sprite.vector);
        vector.x += 120;
        if (i == 11 || i == 23) {
            vector.y += 118;
            vector.x = 236;
            currrent->sprite.vector.x = vector.x;
        }
        currrent = currrent->next;
    }
}

void event_invt_game(game_t *game, sfEvent evt)
{
    if (evt.key.code == sfKeyI) {
        change_view(game, 1089, 1920);
        init_pos_item_invt(game->obj.invt.link);
        game->etat = INVT;
    }
}

void event_inventory(game_t *game, sfEvent event)
{
    if (game->etat == INVT) {
        if (event.key.code == sfKeyB) {
            change_view(game, 650, 1200);
            game->etat = GAME;
        }
        if (event.type == sfEvtMouseButtonPressed) {
            check_item_select_invt(game, event.mouseButton.x, \
            event.mouseButton.y);
        }
    }
}

void draw_inventory(game_t *game)
{
    node_t *node = game->obj.invt.link->head;

    game->window.time = sfClock_getElapsedTime(game->window.clock);
    game->window.sec = game->window.time.microseconds / 10000.0;
    if (game->window.sec > 1) {
        sfRenderWindow_clear(game->window.window, sfBlack);
        D(game->window.window, game->obj.invt.inventory.sprite, NULL);
        while (node != NULL) {
            D(game->window.window, node->sprite.sprite, NULL);
            node = node->next;
        }
        sfRenderWindow_display(game->window.window);
        sfClock_restart(game->window.clock);
    }
}