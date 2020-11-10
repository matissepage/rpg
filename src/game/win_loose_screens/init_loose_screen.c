/*
** EPITECH PROJECT, 2020
** init_loose_screen.c
** File description:
** init_loose_screen.c
*/

#include "rpg.h"

static void init_lsprites(game_t *game)
{
    game->loose_screen.sprite[0].sprite = create_sprite("assets/win_loose.png");
}

static void init_lbutton(game_t *g)
{
    char text[8] = "Restart";
    sfVector2f pos[2];

    pos[0] = (sfVector2f){getpourcentage_x(g, 50), getpourcentage_y(g, 85)};
    pos[1] = (sfVector2f){getpourcentage_x(g, 50), getpourcentage_y(g, 85)};
    g->loose_screen.button[0].sprite = create_sprite("assets/menu/buttons.png");
    g->loose_screen.button[0].rect = (sfIntRect){0, 0, 340, 88};
    sfSprite_setTextureRect(g->loose_screen.button[0].sprite,\
    g->loose_screen.button[0].rect);
    sfSprite_setOrigin(g->loose_screen.button[0].sprite, (sfVector2f){170, 44});
    sfSprite_setPosition(g->loose_screen.button[0].sprite, pos[0]);
    g->loose_screen.button[0].text =\
    create_text(ffont, text, (pos[1].x - 45), (pos[1].y - 20));
}

static void init_ltext(game_t *game)
{
    game->loose_screen.text = sfText_create();
    sfFont *font;
    sfVector2f pos = {getpourcentage_x(game, 50) - 170,\
    getpourcentage_y(game, 50) - 80};

    sfText_setString(game->loose_screen.text, "YOU LOSE !");
    font = sfFont_createFromFile(ffont);
    sfText_setFont(game->loose_screen.text, font);
    sfText_setCharacterSize(game->loose_screen.text, 70);
    sfText_setPosition(game->loose_screen.text, pos);
}

void init_loose_screen(game_t *game)
{
    init_lsprites(game);
    init_lbutton(game);
    init_ltext(game);
}