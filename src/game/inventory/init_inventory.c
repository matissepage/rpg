/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** inventory
*/

#include "rpg.h"

#define INIT_S(SPRITE, PATH, X, Y) init_one_sprite_game(SPRITE, PATH, X, Y);

void init_one_sprite_game(sprite_t *sprite, char const *path, int x, int y)
{
    sprite->texture = sfTexture_createFromFile(path, NULL);
    sprite->sprite = sfSprite_create();
    sprite->vector.x = x;
    sprite->vector.y = y;
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfClose);
    sfSprite_setPosition(sprite->sprite, sprite->vector);
}

void init_item_sprite(sprite_t *sprite, char const *path, sfIntRect rect)
{
    sprite->texture = sfTexture_createFromFile(path, NULL);
    sprite->sprite = sfSprite_create();
    sprite->vector.x = -1000;
    sprite->vector.y = -1000;
    sprite->rect = rect;
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    sfSprite_setPosition(sprite->sprite, sprite->vector);
}

link_t *create_link_invt(game_t *game)
{
    struct stat info;
    char *path = my_strcat("./save/inventory/", game->player.name);
    char **tab_inv = 0;
    link_t *link = init_list();

    path = my_strcat(path, ".txt");
    if (check_save_exist(game->player.name) == 0)
        return (link);
    tab_inv = read_files_invt(&info, path);
    if (tab_inv == NULL) return (link);
    for (int i = 0; tab_inv[i] != NULL; i++)
        add_node_invt(tab_inv[i], link);
    return (link);
}

void init_inventory(game_t *game)
{
    INIT_S(&game->obj.invt.inventory, "./assets/inventory_arm/invt.png", \
    200, 10);
    sfSprite_setScale(game->obj.invt.inventory.sprite, (sfVector2f){1.3, 1.3});
    game->obj.invt.etat = 0;
    game->obj.invt.link = create_link_invt(game);
}