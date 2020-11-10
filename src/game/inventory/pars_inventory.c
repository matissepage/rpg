/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** inventory pars
*/

#include "rpg.h"
#include <string.h>

char *cpy_object(char *str)
{
    char *object = malloc(sizeof(char) * (my_strlen(str) + 1));
    int j = 0;
    int r = 0;

    for (; str[j] != ':'; j++);
    j += 1;
    for (; str[j]; j++, r++)
        object[r] = str[j];
    object[r] = '\0';
    return (object);
}

char *pars_data_invt(char **tab, char *id)
{
    char *str = 0;
    int i = 0;
    int ind = 0;
    int obj_ok = 0;

    for (; tab[i] != NULL; i++) {
        str = malloc(sizeof(char) * (my_strlen(tab[i]) + 1));
        for (int j = 0; tab[i][j] != ':'; j++) {
            str[ind] = tab[i][j];
            ind += 1;
        }
        str[ind] = '\0';
        if ((obj_ok = my_strcmp(str, id)) == 0) break;
        ind = 0;
        free(str);
    }
    free(str);
    str = cpy_object(tab[i]);
    return (str);
}