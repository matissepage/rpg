/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** save invt
*/

#include "rpg.h"

int check_save_exist(char *name)
{
    char *path = my_strcat(name, ".txt");
    DIR *dir = opendir("./save/inventory/");
    struct dirent *dirent;

    while ((dirent = readdir(dir))) {
        if (dirent->d_name[0] == '.')
            continue;
        if (my_strcmp(path, dirent->d_name) == 0) {
            closedir(dir);
            return (1);
        }
    }
    return (0);
}

void create_save_invt(game_t *game)
{
    char *path = my_strcat("./save/inventory/", game->player.name);
    node_t *node = game->obj.invt.link->head;
    int len = size_link(game->obj.invt.link);
    int fd = 0;

    path = my_strcat(path, ".txt");
    fd = open(path, O_WRONLY | O_CREAT, 0644);
    for (int i = 0, end = 0; node != NULL; node = node->next, i++) {
        if (i == len - 1)
            end = 1;
        write_data_save(node, fd, end);
    }
    consolelog(OTHER, "Save Done !");
}

void save_invt(game_t *game)
{
    int value_save = check_save_exist(game->player.name);

    if (value_save >= 0)
        create_save_invt(game);
}