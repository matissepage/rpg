/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** destroy_all.c
*/

#include "rpg.h"

void destroy_player(game_t *game)
{
    sfSprite_destroy(player_.cape);
    sfSprite_destroy(player_.cloth);
    sfSprite_destroy(player_.eyes);
    sfSprite_destroy(player_.hair);
    sfSprite_destroy(player_.skin);
    sfClock_destroy(game->player.clock);
    free (game->player.name);
    consolelog(DESTROY, "End of destroy Pause");
}

void destroy_credit(game_t *g)
{
    sfSprite_destroy(g->credit.button[0].sprite);
    for (int i = 0; i < 6; i++)
        sfText_destroy(g->credit.text[i]);
    consolelog(DESTROY, "End of destroy Credit");
}

void destroy_pause(game_t *g)
{
    for (int i = 0; i < 1; i++)
        sfSprite_destroy(g->pause.button[i].sprite);
    sfSprite_destroy(g->pause.sback);
    consolelog(DESTROY, "End of destroy Pause");
}

void destroy_other(game_t *g)
{
    consolelog(DESTROY, "Begin of all destroy");
}