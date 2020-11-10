/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** destroy_dialog.c
*/

#include "rpg.h"

void destroy_dialog(game_t *g)
{
    my_list_t *next = NULL;

    consolelog(DESTROY, "Linked List of Dialog");
    for (my_list_t *curr = BUILD_DIALOG.linked_dialog; curr; curr = next) {
        next = curr->next;
        free(curr);
    }

    BUILD_DIALOG.linked_dialog = NULL;
}