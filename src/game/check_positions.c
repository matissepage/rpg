/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** check_positions.c
*/

#include "rpg.h"

char get_positions_player(game_t *g)
{
    return (g->map.map[g->map.y][g->map.x]);
}

void check_positions1(game_t *g)
{
    g->map.map[31][25] = (g->player.bool_quest[0] == FALSE ? '1' : '0');
    g->map.map[31][26] = (g->player.bool_quest[0] == FALSE ? '1' : '0');
    g->map.map[46][24] = (g->player.bool_quest[1] == FALSE ? '1' : '0');
    g->map.map[46][25] = (g->player.bool_quest[1] == FALSE ? '1' : '0');
    g->map.map[46][26] = (g->player.bool_quest[1] == FALSE ? '1' : '0');
    g->map.map[46][27] = (g->player.bool_quest[1] == FALSE ? '1' : '0');
}

void redirection_cheat(game_t *g)
{
    if (sfKeyboard_isKeyPressed(sfKeyNumpad1))
        init_other_map(g, 1);
    if (sfKeyboard_isKeyPressed(sfKeyNumpad2))
        init_other_map(g, 2);
    if (sfKeyboard_isKeyPressed(sfKeyNumpad3))
        init_other_map(g, 3);
    if (sfKeyboard_isKeyPressed(sfKeyNumpad4))
        init_other_map(g, 4);
    if (sfKeyboard_isKeyPressed(sfKeyNumpad5))
        init_other_map(g, 5);
    if (g->win == TRUE)
        g->etat = WIN;
}

void check_positions(game_t *g)
{
    int map_actu = g->player.map_actu;
    redirection_cheat(g);
    if (map_actu == 1) {
        check_positions1(g);
        return;
    }
    if (map_actu == 2) {
        if ((g->map.y == 22 || g->map.y == 18) && g->map.x == 18
        && g->player.bool_entermaisonmap2 == FALSE) {
            add_popup(&g->obj.anim, create_datapopup(2, "you cannot return...", TOP));
            g->player.bool_entermaisonmap2 = TRUE;
            g->map.map[21][17] = '0';
            g->map.map[21][18] = '0';
        }
    } else if (map_actu == 5) {
        g->map.map[21][140] = (g->player.bool_quest[6] == FALSE ? '1' : '0');
        g->map.map[22][140] = (g->player.bool_quest[6] == FALSE ? '1' : '0');
        g->map.map[23][140] = (g->player.bool_quest[6] == FALSE ? '1' : '0');
        g->map.map[24][140] = (g->player.bool_quest[6] == FALSE ? '1' : '0');
    }
}