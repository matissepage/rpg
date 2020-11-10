/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** pause_menu.c
*/

#include "../include/rpg.h"

void init_psprites(game_t *game)
{
    game->pause.button[0].sprite = create_sprite("assets/menu/buttons.png");
    game->pause.button[1].sprite = create_sprite("assets/menu/buttons.png");
    game->pause.button[2].sprite = create_sprite("assets/menu/buttons.png");
    game->pause.button[3].sprite = create_sprite("assets/menu/buttons.png");
    game->pause.button[3].rect = (sfIntRect){0, 0, 340, 88};
    game->pause.button[2].rect = (sfIntRect){0, 0, 340, 88};
    game->pause.button[1].rect = (sfIntRect){0, 0, 340, 88};
    game->pause.button[0].rect = (sfIntRect){0, 0, 340, 88};

}

void set_my_rect(game_t *game)
{
    SSTR(game->pause.button[0].sprite, game->pause.button[0].rect);
    SSTR(game->pause.button[1].sprite, game->pause.button[1].rect);
    SSTR(game->pause.button[2].sprite, game->pause.button[2].rect);
    SSTR(game->pause.button[3].sprite, game->pause.button[3].rect);
    sfSprite_setOrigin(game->pause.button[0].sprite, (sfVector2f){170, 44});
    sfSprite_setOrigin(game->pause.button[1].sprite, (sfVector2f){170, 44});
    sfSprite_setOrigin(game->pause.button[2].sprite, (sfVector2f){170, 44});
    sfSprite_setOrigin(game->pause.button[3].sprite, (sfVector2f){170, 44});
}

void set_my_texts(game_t *game, sfVector2f *pos)
{
    char text1[7] = "Resume";
    char text2[8] = "Options";
    char text3[5] = "Save";
    char text4[5] = "Menu";

    for (int i = 0; i < 4; i++) {
        game->pause.button[i].text = sfText_create();
    }

    game->pause.button[0].text =\
    create_text(ffont, text1, pos[1].x - 40, pos[1].y - 20);
    game->pause.button[1].text =\
    create_text(ffont, text2, pos[2].x - 40, pos[2].y - 20);
    game->pause.button[2].text =\
    create_text(ffont, text3, pos[3].x - 25, pos[3].y - 20);
    game->pause.button[3].text =\
    create_text(ffont, text4, pos[4].x - 25, pos[4].y - 20);
}

void init_ppos(game_t *game)
{
    sfVector2f *pos = malloc(sizeof(sfVector2f) * 5);
    pos[0].x = getpourcentage_x(game, 50);
    pos[0].y = getpourcentage_y(game, 50);
    pos[1].x = getpourcentage_x(game, 50);
    pos[1].y = getpourcentage_y(game, 20);
    pos[2].x = getpourcentage_x(game, 50);
    pos[2].y = getpourcentage_y(game, 40);
    pos[3].x = getpourcentage_x(game, 50);
    pos[3].y = getpourcentage_y(game, 60);
    pos[4].x = getpourcentage_x(game, 50);
    pos[4].y = getpourcentage_y(game, 80);

    sfSprite_setPosition(game->pause.button[0].sprite, pos[1]);
    sfSprite_setPosition(game->pause.button[1].sprite, pos[2]);
    sfSprite_setPosition(game->pause.button[2].sprite, pos[3]);
    sfSprite_setPosition(game->pause.button[3].sprite, pos[4]);
    set_my_texts(game, pos);
}

void init_pause_menu(game_t *game)
{
    init_psprites(game);
    set_my_rect(game);
    init_ppos(game);
}