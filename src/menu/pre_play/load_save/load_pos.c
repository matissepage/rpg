/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** load_pos.c
*/

#include "rpg.h"

void load_positionplayer(game_t *g, char *str)
{
    char *f_parti = malloc(sizeof(char) * 1000);
    char *t_parti = malloc(sizeof(char) * 1000);
    sfVector2f vec;
    int i = 0;
    int j = 0;
    for (; str[i] && str[i] != ':'; i++)
        f_parti[i] = str[i];
    f_parti[i] = '\0';
    i++;
    for (; str[i] && str[i] != ':'; i++, j++)
        t_parti[j] = str[i];
    t_parti[j] = '\0';
    consolelog(OTHER, "Load Position of player :");
    vec.x = (float)my_getnbr(f_parti);
    vec.y = (float)my_getnbr(t_parti);
    g->player.pos = vec;
    g->save_pos = vec;
    my_printf("X : %d Y : %d\n", (int)g->player.pos.x, (int)g->player.pos.y);
    change_pos_player_g(g, vec);
    free(f_parti);
    free(t_parti);
}