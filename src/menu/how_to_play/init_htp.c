/*
** EPITECH PROJECT, 2020
** init_htp.c
** File description:
** init_htp.c
*/

#include "rpg.h"

static void init_hbutton(game_t *game)
{
    sfVector2f pos[2];
    pos[0].x = getpourcentage_x(game, 50);
    pos[0].y = getpourcentage_y(game, 85);
    pos[1].x = (getpourcentage_x(game, 50) - 30);
    pos[1].y = (getpourcentage_y(game, 85) - 20);

    game->htp.button[0].text = create_text(ffont, "Play", pos[1].x, pos[1].y);
    game->htp.button[0].sprite = create_sprite("assets/menu/buttons.png");
    game->htp.button[0].rect = (sfIntRect){0, 0, 340, 88};

    SSTR(game->htp.button[0].sprite, game->htp.button[0].rect);
    sfSprite_setOrigin(game->htp.button[0].sprite, (sfVector2f){170, 44});
    sfSprite_setPosition(game->htp.button[0].sprite, pos[0]);
}

static void init_htext(game_t *g)
{
    char tt[60] = "When in shop, press B to return or MouseLeft to buy an item";
    char text1[20] = "Welcome to our Game";
    char text2[30] = "Press ECHAP to pause the game";
    char text3[31] = "Press ZQSD to move your player";

    sfVector2f pos[4];
    pos[0] = (sfVector2f){getpourcentage_x(g, 50) - 150,\
    getpourcentage_y(g, 8)};
    pos[1] = (sfVector2f){getpourcentage_x(g, 50) - 182.5,\
    getpourcentage_y(g, 16)};
    pos[2] = (sfVector2f){getpourcentage_x(g, 50) - 180,\
    getpourcentage_y(g, 24)};
    pos[3] = (sfVector2f){getpourcentage_x(g, 50) - 350,\
    getpourcentage_y(g, 32)};

    g->htp.text[0] = create_text(ffont, text1, pos[0].x, pos[0].y);
    g->htp.text[1] = create_text(ffont, text2, pos[1].x, pos[1].y);
    g->htp.text[2] = create_text(ffont, text3, pos[2].x, pos[2].y);
    g->htp.text[3] = create_text(ffont, tt, pos[3].x, pos[3].y);
}

static void init_htext2(game_t *g)
{
    char text[30] = "Press tab to open the Minimap";
    char text1[58] = "Press i to open the inventory & B to return to the game";
    char text2[49] = "Click on one item inside the inventory to use it";
    sfVector2f pos[3];
    pos[0] = (sfVector2f){getpourcentage_x(g, 50) - 180,\
    getpourcentage_y(g, 40)};
    pos[1] = (sfVector2f){getpourcentage_x(g, 50) - 300,\
    getpourcentage_y(g, 48)};
    pos[2] = (sfVector2f){getpourcentage_x(g, 50) - 240,\
    getpourcentage_y(g, 56)};

    g->htp.text[4] = create_text(ffont, text, pos[0].x, pos[0].y);
    g->htp.text[5] = create_text(ffont, text1, pos[1].x, pos[1].y);
    g->htp.text[6] = create_text(ffont, text2, pos[2].x, pos[2].y);
}

void init_htp(game_t *game)
{
    init_hbutton(game);
    init_htext(game);
    init_htext2(game);
}