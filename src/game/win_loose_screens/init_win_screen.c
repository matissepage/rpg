/*
** EPITECH PROJECT, 2020
** init_win_screen.c
** File description:
** init_win_screen.c
*/

#include "rpg.h"

static void init_wsprites(game_t *game)
{
    game->win_screen.sprite[0].sprite = create_sprite("assets/win_loose.png");
}

static void init_wbutton(game_t *g)
{
    char text[5] = "QUIT";
    sfVector2f pos[2];
    pos[0] = (sfVector2f){getpourcentage_x(g, 50), getpourcentage_y(g, 85)};
    pos[1] = (sfVector2f){getpourcentage_x(g, 50), getpourcentage_y(g, 85)};
    g->win_screen.button[0].sprite = create_sprite("assets/menu/buttons.png");
    g->win_screen.button[0].rect = (sfIntRect){0, 0, 340, 88};
    sfSprite_setTextureRect(g->win_screen.button[0].sprite,\
    g->win_screen.button[0].rect);
    sfSprite_setOrigin(g->win_screen.button[0].sprite, (sfVector2f){170, 44});
    sfSprite_setPosition(g->win_screen.button[0].sprite, pos[0]);
    g->win_screen.button[0].text =\
    create_text(ffont, text, (pos[1].x - 30), (pos[1].y - 20));
}

static void init_wtext(game_t *game)
{
    game->win_screen.text = sfText_create();
    sfFont *font;
    sfVector2f pos = {getpourcentage_x(game, 50) - 160,\
    getpourcentage_y(game, 50) - 80};

    sfText_setString(game->win_screen.text, "YOU WIN !");
    font = sfFont_createFromFile(ffont);
    sfText_setFont(game->win_screen.text, font);
    sfText_setCharacterSize(game->win_screen.text, 70);
    sfText_setPosition(game->win_screen.text, pos);
}

void init_win_screen(game_t *game)
{
    init_wsprites(game);
    init_wbutton(game);
    init_wtext(game);
}