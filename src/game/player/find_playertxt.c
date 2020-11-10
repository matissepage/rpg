/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** moove player in txt map
*/

#include "rpg.h"

int recup_pos_player_x(char **map)
{
    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++) {
            if (map[i][j] == '2')
                return (j);
        }
    }
    return (0);
}

int recup_pos_player_y(char **map)
{
    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++) {
            if (map[i][j] == '2')
                return (i);
        }
    }
    return (0);
}