/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** set_object
*/

#include "rpg.h"

void moove_arm(sfVector2f vec, node_t *node, game_t *g)
{
    node_t *node2 = g->obj.invt.link->head;

    for (; node2 != NULL; node2 = node2->next) {
        if (node2->etat == 1) {
            node2->sprite.vector = g->obj.invt.tmp_vec;
            sfSprite_setPosition(node2->sprite.sprite, node2->sprite.vector);
            node2->etat = 0;
        }
    }
    g->obj.invt.tmp_vec = vec;
    vec.x = 240;
    vec.y = 86;
    node->sprite.vector = vec;
    node->etat = 1;
    g->player.damage += node->dammage;
    sfSprite_setPosition(node->sprite.sprite, vec);
}

void add_main_item(node_t *node, sfVector2f vec, game_t *g, int index)
{
    if (my_strcmp(node->id, "arme") == 0)
        moove_arm(vec, node, g);
    if (my_strcmp("waterflask", node->name) == 0) {
        if (g->player.life+1 > 10) return;
        g->player.life += node->dammage;
        delete_node(index, g->obj.invt.link);
    }
}

void check_item_select_invt(game_t *g, int x, int y)
{
    node_t *node = g->obj.invt.link->head;
    sfVector2f vec;

    for (int i = 0; node != NULL; i++) {
        vec = sfSprite_getPosition(node->sprite.sprite);
        if ((float)x > vec.x && (float)x < vec.x + 32*3) {
            if ((float)y > vec.y && (float)y < vec.y + 30*3) {
                add_main_item(node, vec, g, i);
                break;
            }
        }
        node = node->next;
    }
}