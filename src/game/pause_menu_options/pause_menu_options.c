/*
** EPITECH PROJECT, 2020
** pause_menu_options.c
** File description:
** pause_menu_options.c
*/

#include "rpg.h"

void inits_sprites(game_t *game)
{
    char *btn = "./assets/menu/buttons.png";
    char *button = "./assets/menu/minus_plus.png";

    game->pause_s.button[0].sprite = create_sprite(btn);
    game->pause_s.button[1].sprite = create_sprite(btn);
    game->pause_s.button[2].sprite = create_sprite(btn);
    game->pause_s.sprite[0].sprite = create_sprite(SHEET);
    game->pause_s.sprite[1].sprite = create_sprite(button);
    game->pause_s.sprite[2].sprite = create_sprite(button);
    game->pause_s.button[0].rect = (sfIntRect){0, 0, 340, 88};
    game->pause_s.button[1].rect = (sfIntRect){0, 0, 340, 88};
    game->pause_s.button[2].rect = (sfIntRect){0, 0, 340, 88};
    game->pause_s.rect[0] = (sfIntRect){0, 0, 21, 20};
    game->pause_s.rect[1] = (sfIntRect){0, 0, 107, 109};
    game->pause_s.rect[2] = (sfIntRect){0, 0, 107, 109};
    move_rect(&game->pause_s.rect[2], 107, 214);
    for (int i = 0; i < 3; i++) {
        SSTR(game->pause_s.sprite[i].sprite, game->pause_s.rect[i]);
        SSTR(game->pause_s.button[i].sprite, game->pause_s.button[2].rect);
    }
}

void inits_texts(game_t *game)
{
    float pos_x = getpourcentage_x(game, 50);
    char text1[6] = "Music";
    char text2[7] = "Volume";
    char volume[33] = "0\n10\n20\n30\n40\n50\n60\n70\n80\n90\n100";
    char resume[7] = "Return";

    game->pause_s.vol = str_to_array(volume, '\n');
    game->pause_s.volume = sfText_create();
    game->pause_s.button[0].text = sfText_create();
    game->pause_s.button[1].text = sfText_create();
    game->pause_s.button[2].text = sfText_create();
    game->pause_s.volume = create_text(ffont, text2, \
    (pos_x - 40), (getpourcentage_y(game, 43) - 20));
    game->pause_s.button[0].text = create_text(ffont, text1, \
    (pos_x - 70), (getpourcentage_y(game, 20) - 20));
    game->pause_s.button[1].text = create_text(ffont, game->pause_s.vol[10], \
    (pos_x - 25), (getpourcentage_y(game, 50) - 20));
    game->pause_s.button[2].text = create_text(ffont, resume, \
    (pos_x - 40), (getpourcentage_y(game, 80) - 20));
}

void inits_buttons(game_t *game)
{
    float pos_x = getpourcentage_x(game, 50);
    sfVector2f *pos = malloc(sizeof(sfVector2f) * 6);

    pos[0] = (sfVector2f){pos_x, getpourcentage_y(game, 20)};
    pos[1] = (sfVector2f){pos_x, getpourcentage_y(game, 50)};
    pos[2] = (sfVector2f){pos_x, getpourcentage_y(game, 80)};
    pos[3] = (sfVector2f){(pos_x + 30), (getpourcentage_y(game, 20) - 10)};
    pos[4] = (sfVector2f){(pos_x + 85), (getpourcentage_y(game, 50) - 30)};
    pos[5] = (sfVector2f){(pos_x - 140), (getpourcentage_y(game, 50) - 30)};
    inits_sprites(game);
    sfSprite_setPosition(game->pause_s.button[0].sprite, pos[0]);
    sfSprite_setPosition(game->pause_s.button[1].sprite, pos[1]);
    sfSprite_setPosition(game->pause_s.button[2].sprite, pos[2]);
    sfSprite_setPosition(game->pause_s.sprite[0].sprite, pos[3]);
    sfSprite_setPosition(game->pause_s.sprite[1].sprite, pos[4]);
    sfSprite_setPosition(game->pause_s.sprite[2].sprite, pos[5]);
}

void init_pause_menu_option(game_t *game)
{
    game->pause_s.index = 10;
    inits_buttons(game);
    inits_texts(game);
    sfSprite_setOrigin(game->pause_s.button[0].sprite, (sfVector2f){170, 44});
    sfSprite_setOrigin(game->pause_s.button[1].sprite, (sfVector2f){170, 44});
    sfSprite_setOrigin(game->pause_s.button[2].sprite, (sfVector2f){170, 44});
    sfSprite_setScale(game->pause_s.sprite[1].sprite, (sfVector2f){0.5, 0.5});
    sfSprite_setScale(game->pause_s.sprite[2].sprite, (sfVector2f){0.5, 0.5});
}