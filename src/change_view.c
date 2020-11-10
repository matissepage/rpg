/*
** EPITECH PROJECT, 2020
** change_view.c
** File description:
** change_view.c
*/

#include "rpg.h"

void change_view(game_t *game, int height, int width)
{
    game->window.rect_view.left = 0;
    game->window.rect_view.height = height;
    game->window.rect_view.top = 0;
    game->window.rect_view.width = width;
    game->window.view_game = sfView_createFromRect(game->window.rect_view);
    sfRenderWindow_setView(game->window.window, game->window.view_game);
    sfView_setCenter(game->window.view_game, game->window.vc_view);
}