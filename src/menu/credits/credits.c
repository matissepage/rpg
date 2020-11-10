/*
** EPITECH PROJECT, 2020
** credits.c
** File description:
** credits.c
*/

#include "rpg.h"

void draw_credits(game_t *game)
{
    for (int i = 0; i < 5; i++) {
        SRWDT(game->window.window, game->credit.text[i], NULL);
    }
    sfRenderWindow_drawSprite(game->window.window, p.sprite, NULL);
    SRWDT(game->window.window, p.text, NULL);
}

void create_the_button(game_t *game)
{
    game->credit.button[0].sprite = create_sprite("assets/menu/buttons.png");
    game->credit.button[0].rect = (sfIntRect){0, 0, 340, 88};
    SSTR(game->credit.button[0].sprite, game->credit.button[0].rect);
    sfSprite_setOrigin(game->credit.button[0].sprite, (sfVector2f){170, 44});
    game->credit.button[0].pos.x = getpourcentage_x(game, 50);
    game->credit.button[0].pos.y = getpourcentage_y(game, 70);
    game->credit.button[0].text = create_text(ffontt, "Menu", p.pos.x - 25,\
    p.pos.y - 20);
    sfSprite_setPosition(p.sprite, p.pos);
}

void check_credit_click(game_t *game)
{
    if (test_hitbox_o(game->var.pos_mouse_click,\
    sfSprite_getPosition(p.sprite), 340, 88) == 1) {
        game->etat = MENU;
    }
}

void set_credits_text(game_t *game)
{
    char *font = "assets/fonts/font1.ttf";
    char *text = "Dedicasse a personne ! Fallait etre la !";

    game->credit.text[0] = create_text(font, "CREDITS :", g_x(42), g_y(10));
    sfText_setCharacterSize(game->credit.text[0], 70);
    game->credit.text[1] = create_text(font, "Loic 'La roue libre' Warisse",\
    g_x(15), g_y(25));
    game->credit.text[2] = create_text(font, "Matisse 'Oh Solene !' Page",\
    g_x(15), g_y(35));
    game->credit.text[3] = create_text(font, "Clement 'Oh Lisa !' Bolin",\
    g_x(15), g_y(45));
    game->credit.text[4] = create_text(font, "Gabriel 'La vida loca' Knies",\
    g_x(15), g_y(55));
    game->credit.text[5] = create_text(font, text, g_x(15), g_y(65));
    create_the_button(game);
}

void credits(game_t *game)
{
    int time = sfClock_getElapsedTime(game->window.clock).microseconds / 10000;
    is_mouse_on_btn(game, p.sprite, p.rect);
    if (time > 5) {
        check_credit_click(game);
        sfRenderWindow_clear(game->window.window, sfBlack);
        draw_credits(game);
        sfRenderWindow_display(game->window.window);
        sfClock_restart(game->window.clock);
    }
}