/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** init txt map and set pos player
*/

#include "rpg.h"

void search_nb_map(game_t *game, char nb)
{
    for (int i = 0; game->map.map[i]; i++) {
        for (int j = 0; game->map.map[i][j]; j++) {
            if (game->map.map[i][j] == nb)
                my_printf("x: %d y: %d\n", i, j);
        }
    }
}

void init_map_txt(game_t *game)
{
    struct stat info;

    game->map.map = str_to_array(read_files(&info, \
    "./map/map_quest1.txt"), '\n');
    search_nb_map(game, '5');
    game->map.y = 16;
    game->map.x = 31;
    game->map.map[game->map.y][game->map.x] = '2';
    game->map.coef_x = 26.0;
    game->map.coef_y = 24.0;
}