/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** write invt ins save
*/

#include "rpg.h"

void put_in_file(char c, int fd)
{
    write(fd, &c, 1);
}

void write_in_file(char *str, int fd, int space)
{
    for (int i = 0; str[i]; i++)
        put_in_file(str[i], fd);
    if (space == 1)
        put_in_file(' ', fd);
}

void write_data_save(node_t *node, int fd, int end)
{
    write_in_file("name:", fd, 0);
    write_in_file(node->name, fd, 1);
    write_in_file("path:", fd, 0);
    write_in_file(node->path, fd, 1);
    write_in_file("rect_top:", fd, 0);
    write_in_file(my_atoi(node->rect.top), fd, 1);
    write_in_file("rect_left:", fd, 0);
    write_in_file(my_atoi(node->rect.left), fd, 1);
    write_in_file("rect_height:", fd, 0);
    write_in_file(my_atoi(node->rect.height), fd, 1);
    write_in_file("rect_width:", fd, 0);
    write_in_file(my_atoi(node->rect.width), fd, 1);
    write_in_file("id:", fd, 0);
    write_in_file(node->id, fd, 1);
    write_in_file("gold:", fd, 0);
    write_in_file(my_atoi(node->gold), fd, 1);
    write_in_file("dammage:", fd, 0);
    write_in_file(my_atoi(node->dammage), fd, 0);
    if (end == 1) return;
    write_in_file("\n", fd, 0);
}