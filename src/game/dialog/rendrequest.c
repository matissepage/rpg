/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** rendrequest.c
*/

#include "rpg.h"

void set_rendquestlink(my_list_t *list, int id)
{
    for (my_list_t *tmp = list; tmp ; tmp = tmp->next) {
        if (tmp->data_quest.id == id)
            tmp->data_quest.rendu = TRUE;
    }
}

void rendre_quest(game_t *g)
{
    int id = g->obj.dialog.quest_actu.id;
    if (check_conditionrendu(g, id) == TRUE) {
        g->player.bool_quest[id - 1] = TRUE;
        g->player.gold += g->obj.dialog.quest_actu.xp_win;
        if (id == 1)
            delete_node(item_exist(INV, "waterflask"), INV);
        if (id == 7) {
            delete_node(item_exist(INV, "key"), INV);
            delete_node(item_exist(INV, "bougie"), INV);
            init_other_map(g, 4);
        }
        if (id == 8) {
            g->win = TRUE;
        }
        dialoggotogame(g);
        set_rendquestlink(g->obj.quest.all_quest, id);
    } else {
        add_popup(&g->obj.anim, create_datapopup(5, \
        "Vous n'avez pas fini la quete !", TOP));
        dialoggotogame(g);
    }
}