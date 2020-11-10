/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** init_player
*/

#include "rpg.h"

void init_sprite_game(char const *path, sfIntRect rect, sprite_t *sprite)
{
    sprite->texture = sfTexture_createFromFile(path, NULL);
    sprite->sprite = sfSprite_create();
    sprite->rect = rect;
    sprite->clock = sfClock_create();
    sprite->sec = 0;
}

void init_player_rect_g(game_t *g)
{
    g->player.player.cape_r = initrect(0, 0, 160/5, 256/4);
    g->player.player.cloth_r = initrect(0, 0, 160/5, 256/4);
    g->player.player.hair_r = initrect(0, 0, 160/5, 256/4);
    g->player.player.skin_r = initrect(0, 0, 160/5, 256/4);
    g->player.clock = sfClock_create();
    g->player.sec = 0;
    sfSprite_setScale(g->player.player.cape, (sfVector2f){1, 1});
    sfSprite_setScale(g->player.player.cloth, (sfVector2f){1, 1});
    sfSprite_setScale(g->player.player.skin, (sfVector2f){1, 1});
    sfSprite_setScale(g->player.player.eyes, (sfVector2f){1, 1});
    sfSprite_setScale(g->player.player.hair, (sfVector2f){1, 1});
    g->player.etat = 0;
    init_inventory(g);
    init_all_item(g);
    g->player.damage = 1;
}