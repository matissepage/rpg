/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** open file inventory
*/

#include "rpg.h"

char **my_malloc_invt(char *map)
{
    int len_y = 0;
    int len_x = 0;
    int tmp = 0;
    char **map_malloc = NULL;

    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == '\n')
            len_y += 1;
    }
    len_y += 1;
    map_malloc = malloc(sizeof(char *) * (len_y + 1));
    len_y = 0;
    for (int j = 0; map[j] != '\0'; j++) {
        if (map[j] == '\n') {
            map_malloc[len_y] = malloc(sizeof(char) * len_x + 2);
            tmp = len_x;
            len_x = 0;
            len_y += 1;
        } else
            len_x += 1;
    }
    map_malloc[len_y] = malloc(sizeof(char) * tmp + 2);
    return (map_malloc);
}

char **create_tab_invt(char *map)
{
    char **new_map = my_malloc_invt(map);
    int y = 0;
    int x = 0;
    int tmp = 0;

    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == '\n') {
            new_map[y][x] = '\0';
            tmp = x;
            x = 0;
            y += 1;
        } else {
            new_map[y][x] = map[i];
            x += 1;
        }
    }
    new_map[y][x] = '\0';
    new_map[y+1] = NULL;
    return (new_map);
}

int open_file_invt(char const *path)
{
    int fd = open(path, O_RDONLY);

    if (fd < 0) {
        write(2, "ERROR: Failed open file inventory\n", 35);
        return (84);
    }
    return (fd);
}

char **read_files_invt(struct stat *file_info, char *path)
{
    int fd = open_file_invt(path);
    char **tab = 0;
    int a = 0;
    stat(path, file_info);
    char *buffer = malloc(sizeof(char) * (file_info->st_size + 1));

    a = read(fd, buffer, file_info->st_size);
    if (a <= 0) {
        return (NULL);
    }
    buffer[file_info->st_size] = '\0';
    tab = create_tab_invt(buffer);
    return (tab);
}