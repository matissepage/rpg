/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** mygetline
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "rpg.h"

static void	fill_buffer(char **buffer, const int fd)
{
    int i = 0;

    if ((*buffer = malloc(sizeof(char) * (1 + 1))) == NULL)
        return ;
    if ((i = read(fd, *buffer, 1)) == -1)
        return ;
    (*buffer)[i] = 0;
}

static int	fill_result(char **result, char **buffer)
{
    int i = 0;

    if ((*result = malloc(sizeof(char) * (1 + 1))) == NULL)
        return (-1);
    while (**buffer != 0 && (i == 0 || *(*buffer - 1) != '\n')) {
        (*result)[i] = **buffer;
        (*buffer) += 1;
        i += 1;
    }
    return (i);
}

static char	*strmcat(char *str1, char *str2)
{
    char *result;
    int len1 = 0;
    int len2 = 0;
    int i = 0;
    int j = 0;

    if (str2 == NULL)
        return (str1);
    if (str1 == NULL)
        return (str2);
    len1 = -1;
    while (str1[++len1]);
    len2 = -1;
    while (str2[++len2]);
    if ((result = malloc(sizeof(char) * (len1 + len2 + 1))) == NULL)
        return (NULL);
    i = -1;
    j = -1;
    while (str1[++i])
        result[++j] = str1[i];
    i = -1;
    while (str2[++i])
        result[++j] = str2[i];
    result[++j] = 0;
    return (result);
}

char *get_next_line(const int fd)
{
    static char *buffer;
    char *result = NULL;
    int i = 0;

    if (fd == -1)
        return (NULL);
    if (buffer == NULL || buffer[0] == 0)
        fill_buffer(&buffer, fd);
    if (buffer == NULL)
        return (NULL);
    if (buffer[0] == 0)
        return (NULL);
    i = fill_result(&result, &buffer);
    if (i == -1)
        return (NULL);
    result[i] = 0;
    if (i != 0 && result[i - 1] == '\n')
        result[i - 1] = 0;
    else
        result = strmcat(result, get_next_line(fd));
    return (result);
}