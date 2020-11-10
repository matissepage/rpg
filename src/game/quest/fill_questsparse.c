/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** fill_questsparse.c
*/

#include "rpg.h"

int get_xpwin(char *line_actu)
{
    int i = 0;
    int j = 0;
    int size = 0;
    char *str = malloc(sizeof(char) * 100);

    while (line_actu[i] && line_actu[i] != ':')
        i++;
    i++;
    while (line_actu[i] && line_actu[i] != ':')
        i++;
    i++;
    while (line_actu[i] && line_actu[i] != ':')
        str[j++] = line_actu[i++];
    str[j] = '\0';
    size = my_getnbr(str);
    free(str);
    return (size);
}

int get_lvlmin(char *line_actu)
{
    int i = 0;
    int j = 0;
    int size = 0;
    char *str = malloc(sizeof(char) * 100);

    while (line_actu[i] && line_actu[i] != ':')
        i++;
    i++;
    while (line_actu[i] && line_actu[i] != ':')
        str[j++] = line_actu[i++];
    str[j] = '\0';
    size = my_getnbr(str);
    free(str);
    return (size);
}

int get_idq(char *line_actu)
{
    int i = 0;
    int id = 0;
    char *str = malloc(sizeof(char) * 10);

    while (line_actu[i] && line_actu[i] != ':') {
        str[i] = line_actu[i];
        i++;
    }
    str[i] = '\0';
    id = my_getnbr(str);
    free(str);
    return (id);
}

char *get_objectwin(char *line_actu)
{
    int i = 0;
    int j = 0;
    char *str = malloc(sizeof(char) * 100);

    for (int nbr_p = 0; nbr_p < 3; i++)
        if (line_actu[i] == ':')
            nbr_p++;
    for (; line_actu[i] != ':' && line_actu[i]; i++, j++)
        str[j] = line_actu[i];
    str[j] = '\0';
    return (str);
}

char *get_dialog(char *line_actu, int id)
{
    int i = 0;
    int j = 0;
    char *str = malloc(sizeof(char) * 1000);

    for (int nbr_p = 0; nbr_p < (4 + id); i++)
        if (line_actu[i] == ':')
            nbr_p++;
    for (; line_actu[i] && line_actu[i] != ':'; i++, j++)
        str[j] = line_actu[i];
    str[j] = '\0';
    return (str);
}