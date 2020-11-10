/*
** EPITECH PROJECT, 2020
** pause_menu_draw.c
** File description:
** pause_menu_draw.c
*/

#include "rpg.h"

void check_pause_click2(game_t *game)
{
    sfVector2f pos = sfSprite_getPosition(game->player.player.cape);

    if (test_hitbox_o(game->var.pos_mouse_click,\
    sfSprite_getPosition(game->pause.button[2].sprite), 340, 88) == 1) {
        save_myprofile(game, pos);
        save_invt(game);
        game->var.pos_mouse_click = init_vector(-100, -100);
    }
    if (test_hitbox_o(game->var.pos_mouse_click,\
    sfSprite_getPosition(game->pause.button[3].sprite), 340, 88) == 1) {
        game->etat = MENU;
        change_view(game, 1010, 1920);
        game->var.pos_mouse_click = init_vector(-100, -100);
    }
}

void check_pause_click(game_t *game)
{
    if (test_hitbox_o(game->var.pos_mouse_click,\
    sfSprite_getPosition(game->pause.button[0].sprite), 340, 88) == 1) {
        change_view(game, 650, 1200);
        game->etat = GAME;
        game->var.pos_mouse_click = init_vector(-100, -100);
    }
    if (test_hitbox_o(game->var.pos_mouse_click,\
    sfSprite_getPosition(game->pause.button[1].sprite), 340, 88) == 1) {
        game->etat = OPT;
        game->var.pos_mouse_click = init_vector(-100, -100);
    }
    check_pause_click2(game);
}

void draw_pause_menu(game_t *game)
{
    sfRenderWindow_clear(game->window.window, sfBlack);
    sfRenderWindow_drawSprite(game->window.window,\
    game->pause.button[0].sprite, NULL);
    sfRenderWindow_drawSprite(game->window.window,\
    game->pause.button[1].sprite, NULL);
    sfRenderWindow_drawSprite(game->window.window,\
    game->pause.button[2].sprite, NULL);
    sfRenderWindow_drawSprite(game->window.window,\
    game->pause.button[3].sprite, NULL);
    for (int i = 0; i < 4; i++) {
        sfRenderWindow_drawText(game->window.window,\
        game->pause.button[i].text, NULL);
    }
    sfRenderWindow_display(game->window.window);
}

void pause_menu(game_t *game)
{
    game->window.time = sfClock_getElapsedTime(game->window.clock);
    game->window.sec = game->window.time.microseconds / 10000.0;

    for (int i = 0; i < 4; i++) {
        is_mouse_on_btn(game, game->pause.button[i].sprite,\
        game->pause.button[i].rect);
    }
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        check_pause_click(game);
    }

    if (game->window.sec > 1) {
        draw_pause_menu(game);
    }
}