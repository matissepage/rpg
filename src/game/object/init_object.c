/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** init all object
*/

#include "rpg.h"

link_t *create_link_item(void)
{
    struct stat info;
    char **tab = read_files_invt(&info, "./save/object/object.txt");
    link_t *link = init_list();

    for (int i = 0; tab[i] != NULL; i++)
        add_node_invt(tab[i], link);
    return (link);
}

void init_all_item(game_t *game)
{
    game->obj.item = create_link_item();
}