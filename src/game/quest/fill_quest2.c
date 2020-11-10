/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** fill_quest2
*/

#include "rpg.h"

char *get_namedialog(char *str)
{
    int i = 0;
    int j = 0;
    char *new_str = malloc(sizeof(char) * 100);

    for (int nbr = 0; str[i] && nbr < 9; i++)
        if (str[i] == ':')
            nbr++;
    for (; str[i]; i++)
        new_str[j++] = str[i];
    new_str[j] = '\0';
    return (new_str);
}

int get_iconiddialog(char *str)
{
    int i = 0;
    int j = 0;
    char *new_str = malloc(sizeof(char) * 10);

    for (int nbr = 0; str[i] && nbr < 8; i++)
        if (str[i] == ':')
            nbr++;
    for (; str[i]; i++)
        new_str[j++] = str[i];
    new_str[j] = '\0';
    return (my_getnbr(new_str));
}

sfVector2f get_posquest(char *str)
{
    int i = 0;
    int j = 0;
    char *new_str = malloc(sizeof(char) * 100);
    char *next_str = malloc(sizeof(char) * 100);
    sfVector2f pos;

    for (int nbr_p = 0; nbr_p < 6; i++)
        if (str[i] == ':') nbr_p++;
    for (; str[i] && str[i] != ':'; i++, j++)
        new_str[j] = str[i];
    new_str[j] = '\0';
    for (i++, j = 0; str[i] && str[i] != ':'; i++, j++)
        next_str[j] = str[i];
    next_str[j] = '\0';
    pos = init_vector(my_getnbr(next_str), my_getnbr(new_str));
    free(new_str);
    free(next_str);
    return (pos);
}