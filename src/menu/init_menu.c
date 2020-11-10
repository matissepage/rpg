/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_menu.c
*/

#include "rpg.h"

void init_background(game_t *game);

void init_sprites(game_t *game)
{
    game->obj.menu.buttons[0].sprite = create_sprite("assets/menu/buttons.png");
    game->obj.menu.buttons[1].sprite = create_sprite("assets/menu/buttons.png");
    game->obj.menu.buttons[2].sprite = create_sprite("assets/menu/buttons.png");
    game->obj.menu.buttons[3].sprite = create_sprite("assets/menu/buttons.png");

    game->obj.menu.buttons[0].rect = (sfIntRect){0, 0, 340, 88};
    game->obj.menu.buttons[1].rect = (sfIntRect){0, 0, 340, 88};
    game->obj.menu.buttons[2].rect = (sfIntRect){0, 0, 340, 88};
    game->obj.menu.buttons[3].rect = (sfIntRect){0, 0, 340, 88};
    SSTR(game->obj.menu.buttons[0].sprite, game->obj.menu.buttons[0].rect);
    SSTR(game->obj.menu.buttons[1].sprite, game->obj.menu.buttons[0].rect);
    SSTR(game->obj.menu.buttons[2].sprite, game->obj.menu.buttons[0].rect);
    SSTR(game->obj.menu.buttons[3].sprite, game->obj.menu.buttons[0].rect);
}

void set_sprite_origins(game_t *game)
{
    sfSprite_setOrigin(game->obj.menu.buttons[0].sprite, (sfVector2f){170, 44});
    sfSprite_setOrigin(game->obj.menu.buttons[1].sprite, (sfVector2f){170, 44});
    sfSprite_setOrigin(game->obj.menu.buttons[2].sprite, (sfVector2f){170, 44});
    sfSprite_setOrigin(game->obj.menu.buttons[3].sprite, (sfVector2f){170, 44});
}

void set_text(game_t *game, sfVector2f *pos)
{
    char text2[5] = "Play";
    char text6[9] = "Settings";
    char text3[8] = "Credits";
    char text4[5] = "Exit";
    for (int i = 0; i < 4; i++) {
        game->obj.menu.buttons[i].text = sfText_create();
    }
    game->obj.menu.buttons[0].text =\
    create_text(ffont, text2, pos[0].x - 20, pos[0].y - 20);
    game->obj.menu.buttons[1].text =\
    create_text(ffont, text6, pos[1].x - 50, pos[1].y - 20);
    game->obj.menu.buttons[2].text =\
    create_text(ffont, text3, pos[2].x - 45, pos[2].y - 20);
    game->obj.menu.buttons[3].text =\
    create_text(ffont, text4, pos[3].x - 30, pos[3].y - 20);
}

void init_buttons(game_t *game)
{
    sfVector2f *pos = malloc(sizeof(sfVector2f) * 4);
    pos[0].x = getpourcentage_x(game, 20);
    pos[0].y = getpourcentage_y(game, 85);
    pos[1].x = getpourcentage_x(game, 40);
    pos[1].y = getpourcentage_y(game, 85);
    pos[2].x = getpourcentage_x(game, 60);
    pos[2].y = getpourcentage_y(game, 85);
    pos[3].x = getpourcentage_x(game, 80);
    pos[3].y = getpourcentage_y(game, 85);

    init_sprites(game);
    set_sprite_origins(game);
    set_text(game, pos);
    sfSprite_setPosition(game->obj.menu.buttons[0].sprite, pos[0]);
    sfSprite_setPosition(game->obj.menu.buttons[1].sprite, pos[1]);
    sfSprite_setPosition(game->obj.menu.buttons[2].sprite, pos[2]);
    sfSprite_setPosition(game->obj.menu.buttons[3].sprite, pos[3]);
}

void init_menu(game_t *game)
{
    game->allow_event = TRUE;
    init_background(game);
    init_buttons(game);
    game->obj.menu.anim_btn.clock = sfClock_create();
}