/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** set_panelrect.c
*/

#include "rpg.h"

char *create_myposjoueur(sfVector2f pos)
{
    char *to_return = malloc(sizeof(char) * 1000);
    int j = 0;

    char *x = my_itc(pos.x);
    char *y = my_itc(pos.y);
    for (int i = 0; x[i]; i++)
        to_return[j++] = x[i];
    to_return[j++] = ':';
    for (int i = 0; y[i]; i++)
        to_return[j++] = x[i];
    to_return[j++] = '\n';
    to_return[j] = '\0';
    consolelog(OTHER, "Pos player detect is : ");
    my_printf("[%s]\n", to_return);
    return (to_return);
}

void set_panelrect(game_t *g)
{
    sfVector2f size1 = I(getpourcentage_x(g, 17), getpourcentage_y(g, 15));
    sfVector2f size2 = I(getpourcentage_x(g, 30), getpourcentage_y(g, 7));
    sfVector2f size3 = I(getpourcentage_x(g, 25), getpourcentage_y(g, 60));
    sfVector2f pos1 = I(getpourcentage_x(g, 2), getpourcentage_y(g, 48));
    sfVector2f pos2 = I(getpourcentage_x(g, 33), getpourcentage_y(g, 8));
    sfVector2f pos3 = I(getpourcentage_x(g, 60), getpourcentage_y(g, 26));
    g->obj.menu.preplay.cadre[0] = sfRectangleShape_create();
    g->obj.menu.preplay.cadre[1] = sfRectangleShape_create();
    g->obj.menu.preplay.cadre[2] = sfRectangleShape_create();
    sfRectangleShape_setSize(g->obj.menu.preplay.cadre[0], size1);
    sfRectangleShape_setSize(g->obj.menu.preplay.cadre[1], size2);
    sfRectangleShape_setSize(g->obj.menu.preplay.cadre[2], size3);
    sfRectangleShape_setPosition(g->obj.menu.preplay.cadre[0], pos1);
    sfRectangleShape_setPosition(g->obj.menu.preplay.cadre[1], pos2);
    sfRectangleShape_setPosition(g->obj.menu.preplay.cadre[2], pos3);
    for (int i = 0; i < 3; i++)
        A(g->obj.menu.preplay.cadre[i], sfColor_fromRGBA(4, 181, 253, 150));
}