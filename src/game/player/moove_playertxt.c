/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** moove player map txt
*/

#include "rpg.h"

void moove_player_dtxt(char **map, game_t *g)
{
    int x = g->map.x;
    int y = g->map.y;
    int limit = my_strlen(map[y]);

    move_rect_right(g);
    if (limit == x) return;
    if (map[y][x+1] == '3')
        init_other_map(g, 2);
    if (map[y][x+1] == 'N')
        init_other_map(g, 4);
    if (map[y][x+1] == '0') {
        map[y][x] = '0';
        map[y][x+1] = '2';
        g->map.x += 1;
        move_player_right(g, g->map.coef_x);
    } else
        play_on_wall(g);
}

void moove_player_qtxt(char **map, game_t *g)
{
    int x = g->map.x;
    int y = g->map.y;

    move_rect_left(g);
    if (x-1 <= 0) return;
    if (map[y][x-1] == '3')
        init_other_map(g, 2);
    if (map[y][x-1] == 'N')
        init_other_map(g, 4);
    if (map[y][x-1] == '0') {
        map[y][x] = '0';
        map[y][x-1] = '2';
        g->map.x -= 1;
        move_player_left(g, g->map.coef_x);
    } else
        play_on_wall(g);
}

void moove_player_stxt(char **map, game_t *g)
{
    int x = g->map.x;
    int y = g->map.y;
    int limit = nb_line_map_txt(map);

    move_rect_down(g);
    if (limit == y+1) return;
    if (map[y+1][x] == '3')
        init_other_map(g, 2);
    if (map[y+1][x] == 'N')
        init_other_map(g, 4);
    if (map[y+1][x] == '0') {
        map[y][x] = '0';
        map[y+1][x] = '2';
        g->map.y += 1;
        move_player_down(g, g->map.coef_y);
    } else
        play_on_wall(g);
}

void moove_player_ztxt(char **map, game_t *g)
{
    int x = g->map.x;
    int y = g->map.y;
    int limit = 0;

    move_rect_up(g);
    if (limit == y) return;
    if (map[y-1][x] == '3')
        init_other_map(g, 2);
    if (map[y-1][x] == 'N')
        init_other_map(g, 4);
    if (map[y-1][x] == '0') {
        map[y][x] = '0';
        map[y-1][x] = '2';
        g->map.y -= 1;
        move_player_up(g, g->map.coef_y);
    } else
        play_on_wall(g);
}