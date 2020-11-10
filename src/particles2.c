/*
** EPITECH PROJECT, 2020
** particles2.c
** File description:
** particles2.c
*/

#include "rpg.h"

void get_event_particles(game_t *g, sfEvent event)
{
    if ((event.type == sfEvtMouseButtonPressed) && g->etat == MENU) {
        sfVector2i pos = sfMouse_getPositionRenderWindow(g->window.window);
        add_particle(&g->screen.particle_environment, g->screen.particle, \
        35, (sfVector2f){pos.x, pos.y});
    }
}

void *my_memset(void *ptr, int c, size_t length)
{
    char *start = NULL;

    if (ptr == NULL)
        return (NULL);
    start = ptr;
    while (length) {
        *start = c;
        start++;
        length--;
    }
    return (ptr);
}

void init_particles(game_t *game)
{
    my_memset(&game->screen, 0, sizeof(game->screen));
    init_particle_environment(&game->screen.particle_environment, \
    (sfVector2f){PARTICLE_ANGLE_MIN, PARTICLE_ANGLE_MAX}, \
    (sfVector2f){GRAVITY_X, GRAVITY_Y}, ALPHA);
}

void init_map_1(game_t *game, struct stat info)
{
    game->map.map = str_to_array(read_files(&info, \
    "./map/map_quest1.txt"), '\n');
    game->map.y = 16;
    game->map.x = 31;
    game->map.map[game->map.y][game->map.x] = '2';
    game->map.etat_map = 1;
    print_map_txt(game->map.map);
    init_sprite_wht_rect("./map/map_quest1.png", 0, 0, &game->obj.map[0]);
}