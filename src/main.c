/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "rpg.h"

void init_view_map(game_t *game)
{
    game->window.mini_map = sfView_create();
    sfView_setCenter(game->window.view_game, game->window.vc_view);
    sfView_zoom(game->window.mini_map, 1.5);
    game->obj.mini_map_wood.sprite = create_sprite(PATH_WOOD);
    sfSprite_setPosition(game->obj.mini_map_wood.sprite, init_vector(0, 0));
}

void create_window(game_t *game)
{
    sfVideoMode mode = {1920, 1080, 60};
    sfVector2u tmp;
    game->window.clock = sfClock_create();
    game->window.window = sfRenderWindow_create(mode, "My RPG", \
    sfDefaultStyle, NULL);
    game->window.sec = 0;
    tmp = sfRenderWindow_getSize(game->window.window);
    game->window.size_window.x = (float)tmp.x;
    game->window.size_window.y = (float)tmp.y;
    sfRenderWindow_setFramerateLimit(game->window.window, 60);
    sfRenderWindow_setVerticalSyncEnabled(game->window.window, sfTrue);
    game->var.music = sfTrue;
}

int info(void)
{
    my_printf("This Project, is a RPG like by\n");
    return (0);
}

int main(int ac, char **av)
{
    game_t game;

    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        return (info());
    if (ac == 2 && my_strcmp(av[1], "--name") == 0)
        game.obj.menu.preplay.bool_name = TRUE;
    else
        game.obj.menu.preplay.bool_name = FALSE;
    create_window(&game);
    game.etat = MENU;
    manage_scene(&game);
    sfRenderWindow_destroy(game.window.window);
}