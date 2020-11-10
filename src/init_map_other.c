/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** init_map_other
*/

#include "rpg.h"

void re_init_ui(game_t *game)
{
    sfSprite_setPosition(game->player.ui.sprite, \
    init_vector(game->window.vc_view.x-(1143*0.7/2), \
    game->window.vc_view.y-(822*0.7/2)));
    sfText_setPosition(game->player.text[0], \
    init_vector(game->window.vc_view.x-(1143*0.7/2)+35, \
    game->window.vc_view.y-(822*0.7/2)-6));
    sfText_setPosition(game->player.text[1], \
    init_vector(game->window.vc_view.x-(1143*0.7/2)+116, \
    game->window.vc_view.y-(822*0.7/2)-6));
}

void init_map_4(game_t *game, struct stat info)
{
    game->shop.pnj[0].vector.x = 32 * 53;
    game->shop.pnj[0].vector.y = 32 * 38;
    sfSprite_setPosition(game->shop.pnj[0].sprite, game->shop.pnj[0].vector);
    game->map.map = str_to_array(read_files(&info, \
    MAP5TXT), '\n');
    game->map.x = 41;
    game->map.y = 52;
    game->map.coef_x = 32;
    game->map.coef_y = 32;
    game->map.etat_map = 3;
    game->map.map[game->map.y][game->map.x] = '2';
    init_sprite_wht_rect(MAP_5, 0, 0, &game->obj.map[0]);
    set_pos_player_default(game, 32 * 41, 32 * 51);
    re_init_ui(game);
}

void init_map_5(game_t *game, struct stat info)
{
    game->shop.pnj[0].vector.x = 32 * 56;
    game->shop.pnj[0].vector.y = 32 * 12;
    sfSprite_setPosition(game->shop.pnj[0].sprite, game->shop.pnj[0].vector);
    game->map.map = str_to_array(read_files(&info, \
    MAP6TXT), '\n');
    game->map.x = 53;
    game->map.y = 7;
    game->map.coef_x = 32;
    game->map.coef_y = 32;
    game->map.etat_map = 3;
    game->map.map[game->map.y][game->map.x] = '2';
    init_sprite_wht_rect(MAP_6, 0, 0, &game->obj.map[0]);
    set_pos_player_default(game, 32 * 53, 32 * 6);
    re_init_ui(game);
}

void init_map_3(game_t *game, struct stat info)
{
    game->shop.pnj[0].vector.x += 125;
    sfSprite_setPosition(game->shop.pnj[0].sprite, game->shop.pnj[0].vector);
    game->map.map = str_to_array(read_files(&info, \
    MAP4TXT), '\n');
    game->map.x = 38;
    game->map.y = 70;
    game->map.coef_x = 32;
    game->map.coef_y = 32;
    game->map.etat_map = 3;
    game->map.map[game->map.y][game->map.x] = '2';
    init_sprite_wht_rect(MAP_4, 0, 0, &game->obj.map[0]);
    set_pos_player_default(game, 32 * 38, 32 * 69);
    re_init_ui(game);
}

void init_map_2(game_t *game, struct stat info)
{
    game->shop.pnj[0].vector.x += 125;
    sfSprite_setPosition(game->shop.pnj[0].sprite, game->shop.pnj[0].vector);
    game->map.map = str_to_array(read_files(&info, \
    MAP2TXT), '\n');
    game->map.x = 38;
    game->map.y = 70;
    game->map.coef_x = 32;
    game->map.coef_y = 32;
    game->map.etat_map = 2;
    game->map.map[game->map.y][game->map.x] = '2';
    init_sprite_wht_rect(MAP_3, 0, 0, &game->obj.map[0]);
    set_pos_player_default(game, 32 * 38, 32 * 69);
    re_init_ui(game);
}