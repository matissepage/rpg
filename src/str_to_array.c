/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** str to array
*/

#include "rpg.h"

int size_malloc_y(char *str, char sep)
{
    int size_malloc = 0;
    
    for (int i = 0; str[i]; i++) {
        if (str[i] == sep)
            size_malloc += 1;
    }
    return (size_malloc);
}

char **malloc_array(char *str, char sep)
{
    char **array = malloc(sizeof(char *) * (size_malloc_y(str, sep) + 2));
    int j = 0;
    int y = 0;

    for (int i = 0; i != my_strlen(str) + 1; i++) {
        if (str[i] == sep || str[i] == '\0') {
            array[y] = malloc(sizeof(char) * (j + 1));
            j = 0;
            y += 1;
            continue;
        }
        j += 1;
    }
    return (array);
}

char **str_to_array(char *str, char sep)
{
    char **array = malloc_array(str, sep);
    int j = 0;
    int index = 0;

    for (int i = 0; i != my_strlen(str) + 1; i++) {
        if (str[i] == ' ' || str[i] == '[' || str[i] == ']') continue;
        if (str[i] == sep || str[i] == '\0') {
            array[index][j] = '\0';
            index += 1;
            j = 0;
            continue;
        }
        array[index][j] = str[i];
        j += 1;
    }
    array[index] = NULL;
    return (array);
}