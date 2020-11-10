/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** inti all
*/

#include "rpg.h"

void init_sprite_wht_rect(char const *path, int x, int y, sprite_t *sprite)
{
    sprite->texture = sfTexture_createFromFile(path, NULL);
    sprite->sprite = sfSprite_create();
    sprite->vector.x = x;
    sprite->vector.y = y;
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfClose);
    sfSprite_setPosition(sprite->sprite, sprite->vector);
}

void init_view_game(game_t *game, int x, int y)
{
    game->window.vc_view.x = x;
    game->window.vc_view.y = y;
    game->window.rect_view.left = 0;
    game->window.rect_view.height = 650;
    game->window.rect_view.top = 0;
    game->window.rect_view.width = 1200;
    game->window.view_game = sfView_create();
    game->window.view_game = sfView_createFromRect(game->window.rect_view);
    sfView_setCenter(game->window.view_game, game->window.vc_view);
}

void init_other_map(game_t *game, int map)
{
    struct stat info;

    sfSprite_destroy(game->obj.map[0].sprite);
    destroy_chest(game);
    destroy_quest(game);
    import_chest(game, map);
    fill_quest(game, map);
    remove_charquest(game);
    init_charquest(game);
    game->player.map_actu = map;
    for (int i = 0; game->map.map[i] != NULL; i++)
        free(game->map.map[i]);
    if (map == 2)
        init_map_2(game, info);
    if (map == 1)
        init_map_1(game, info);
    if (map == 3)
        init_map_3(game, info);
    if (map == 4)
        init_map_4(game, info);
    if (map == 5)
        init_map_5(game, info);
}

void init_varall(game_t *game)
{
    game->obj.status_minimap = FALSE;
    game->obj.quest.animation_on = NULL;
    game->obj.anim = NULL;
    game->map.etat_map = 1;
    game->player.map_actu = 1;
    game->player.bool_entermaisonmap2 = FALSE;
    for (int i = 0; i < 15; i++)
        game->player.bool_quest[i] = FALSE;
}

void init_all_game(game_t *game)
{
    init_sprite_wht_rect("./map/map_quest1.png", 0, 0, &game->obj.map[0]);
    sfSprite_setScale(game->obj.map[0].sprite, (sfVector2f){1.7, 1.55});
    init_view_game(game, game->window.size_window.x/2, \
    game->window.size_window.y/2);
    init_view_map(game);
    init_player_rect_g(game);
    sfFloatRect rect = {-0.1f, 0, 0.25f, 0.25f};
    sfView_setViewport(game->window.mini_map, rect);
    sfView_setViewport(game->window.view_game, (sfFloatRect){0, 0, 1, 1});
    init_map_txt(game);
    init_varall(game);
    init_chest(game);
    init_shop(game);
    init_ui_player(game);
    init_mob_map1(game);
}