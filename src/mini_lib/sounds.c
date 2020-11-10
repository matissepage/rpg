/*
** EPITECH PROJECT, 2020
** sounds.c
** File description:
** sounds.c
*/

#include "rpg.h"

void init_sounds(game_t *game)
{
    game->sounds.bought = sfSound_create();
    game->sounds.hit = sfSound_create();

    game->sounds.buf = sfSoundBuffer_createFromFile("./assets/sounds/buy.ogg");
    game->sounds.buf1 = \
    sfSoundBuffer_createFromFile("./assets/sounds/hurt.ogg");

    sfSound_setBuffer(game->sounds.bought, game->sounds.buf);
    sfSound_setBuffer(game->sounds.hit, game->sounds.buf1);
}

void play_second_music(game_t *game)
{
    sfMusic_play(game->background.music2.music);
}

void play_first_music(game_t *game)
{
    sfMusic_play(game->background.music.music);
}

void play_on_wall(game_t *game)
{
    sfSound_play(game->sounds.hit);
}

void play_on_buy(game_t *game)
{
    sfSound_play(game->sounds.bought);
}