/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** tool
*/

#include "rpg.h"

char *my_atoi(int nb)
{
    int rem = 0;
    int i = 0;
    char *str = malloc(sizeof(char) * 200);

    if (nb == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return (str);
    }
    while (nb != 0) {
        rem = nb % 10;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        nb = nb / 10;
    }
    str[i] = '\0';
    my_revstr(str);
    return (str);
}

int size_link(link_t *link)
{
    node_t *node = link->head;
    int i = 0;

    for (; node != NULL; node = node->next, i++);
    return (i);
}

int nb_line_map_txt(char **map)
{
    int i = 0;

    for (; map[i] != NULL; i++);
    return (i-1);
}

void print_map_txt(char **map)
{
    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j]; j++) {
            if (map[i][j] == '1')
                my_printf("\033[1;31m%c\033[1;34m", map[i][j]);
            else if (map[i][j] == '2')
                my_printf("\033[1;32m%c\033[1;34m", map[i][j]);
            else
                my_printf("%c", map[i][j]);
        }
        my_printf("\n");
    }
}