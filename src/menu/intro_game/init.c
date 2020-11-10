/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init.c
*/

#include "rpg.h"

void create_texteintro(game_t *g)
{
    BUILD_INTRO.press_skip = create_text(PATH_FONT, MESSAGE_SKIP, 0, 80);
}

void create_spriteinintro(game_t *g)
{
    BUILD_INTRO.bg.sprite = create_sprite(PATH_BGINTRO);
    sfSprite_setPosition(BUILD_INTRO.bg.sprite, init_vector(0, 0));
}

void init_intro(game_t *g)
{
    consolelog(INIT, "Begin Init Intro");
    create_spriteinintro(g);
    consolelog(INIT, "[50%] Init Intro");
    create_texteintro(g);
    consolelog(INIT, "End Init Intro");
}