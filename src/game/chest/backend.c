/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** backend.c
*/

#include "rpg.h"

node_t *get_dataitem(int id, link_t *link)
{
    node_t *node = link->head;
    int id_local = 0;

    while (node != NULL) {
        if (id_local == id)
            return (node);
        id_local++;
        node = node->next;
    }
    return (NULL);
}

void add_object(link_t *link, node_t *node)
{
    node_t *current = NULL;

    if (link->head == NULL) {
        link->head = cpy_data_node(node);
    }
    else {
        current = link->head;
        while (current->next != NULL)
            current = current->next;
        current->next = cpy_data_node(node);
    }
}

void try_openchest(game_t *g, my_list_t *tmp)
{
    char *name = malloc(sizeof(char) * 1000);

    name = my_strcpy(name, "+ 1 :");
    name = my_strcat(name, tmp->data.str);
    if (sfKeyboard_isKeyPressed(sfKeyN)) {
        node_t *node = get_dataitem(item_exist(g->obj.item, tmp->data.str), \
        g->obj.item);
        add_object(INV, node);
        tmp->data.open = TRUE;
        move_rect(&tmp->data.rect, 32 / 2, 32);
        add_popup(&g->obj.anim, create_datapopup(5, name, LEFT));
        sfSprite_setTextureRect(tmp->data.sprite, tmp->data.rect);
    }
}

void check_interaction_chest(game_t *g)
{
    const int range = 40;
    sfVector2f ps = sfSprite_getPosition(g->player.player.hair);
    sfVector2f actu;
    sfVector2f pos = ps;
    pos.x -= 150;
    pos.y -= 75;
    int id = 0;

    for (my_list_t *tmp = g->obj.quest.chest_list; tmp; tmp = tmp->next) {
        actu = tmp->data.pos;
        if (ps.x > actu.x - range && ps.x < actu.x + range &&
        ps.y > actu.y - range && ps.y < actu.y + range &&
        tmp->data.open == FALSE) {
            sfText_setPosition(g->obj.quest.notif_chest, pos);
            sfRenderWindow_drawText(W, g->obj.quest.notif_chest, NULL);
            try_openchest(g, tmp);
        }
        id++;
    }
}

void manage_chest(game_t *g)
{
    display_chest(g);
    check_interaction_chest(g);
}