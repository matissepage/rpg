/*
** EPITECH PROJECT, 2020
** background.c
** File description:
** background.c
*/

#include "rpg.h"

void move_background(game_t *game)
{
    static int bol = 0;

    game->background.time = sfClock_getElapsedTime(game->background.clock);
    game->background.seconds = game->background.time.microseconds / 100000.0;
    if (game->background.seconds > 0.65) {
        SSST(game->background.sprite, bstruct.texture[bstruct.i], sfTrue);
        (game->background.i == 10) ? bol = 1 : 0;
        (game->background.i == 0) ? bol = 0 : 0;
        (bol == 0) ? game->background.i++ : game->background.i--;
        sfClock_restart(game->background.clock);
    }
}

void init_music(game_t *game)
{
    game->background.music.music =\
    sfMusic_createFromFile("assets/music/music1.ogg");
    sfMusic_setVolume(game->background.music.music, 30);
    sfMusic_setLoop(game->background.music.music, sfTrue);
    sfMusic_play(game->background.music.music);
    game->background.music2.music =\
    sfMusic_createFromFile("assets/music/music2.ogg");
    sfMusic_setVolume(game->background.music2.music, 30);
    sfMusic_setLoop(game->background.music2.music, sfTrue);
}

void init_background(game_t *game)
{
    game->background.texture = malloc(sizeof(sfTexture *) * 11);
    game->background.texture[0] = STCFF("assets/menu_bcg/b0.png", NULL);
    game->background.texture[1] = STCFF("assets/menu_bcg/b1.png", NULL);
    game->background.texture[2] = STCFF("assets/menu_bcg/b2.png", NULL);
    game->background.texture[3] = STCFF("assets/menu_bcg/b3.png", NULL);
    game->background.texture[4] = STCFF("assets/menu_bcg/b4.png", NULL);
    game->background.texture[5] = STCFF("assets/menu_bcg/b5.png", NULL);
    game->background.texture[6] = STCFF("assets/menu_bcg/b6.png", NULL);
    game->background.texture[7] = STCFF("assets/menu_bcg/b7.png", NULL);
    game->background.texture[8] = STCFF("assets/menu_bcg/b8.png", NULL);
    game->background.texture[9] = STCFF("assets/menu_bcg/b9.png", NULL);
    game->background.texture[10] = STCFF("assets/menu_bcg/b10.png", NULL);
    game->background.sprite = sfSprite_create();
    sfSprite_setScale(game->background.sprite, (sfVector2f){1.50, 1.45});
    SSST(game->background.sprite, game->background.texture[0], sfTrue);
    game->background.clock = sfClock_create();
    game->background.i = 0;
    init_music(game);
}