/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_sprite.c
*/

#include "rpg.h"

void init_spritebtn(game_t *g)
{
    sfVector2f p1;
    sfVector2f p2;
    int xp = getpourcentage_x(g, 5);
    p1.x = getpourcentage_x(g, 8);
    p1.y = getpourcentage_y(g, 90);
    p2.x = getpourcentage_x(g, 40);
    p2.y = getpourcentage_y(g, 90);
    BUILD_PREPLAY.btn[0].sprite = create_sprite(PATH_BUTTON);
    BUILD_PREPLAY.btn[1].sprite = create_sprite(PATH_BUTTON);
    sfSprite_setPosition(BUILD_PREPLAY.btn[0].sprite, p1);
    sfSprite_setPosition(BUILD_PREPLAY.btn[1].sprite, p2);
    STR(BUILD_PREPLAY.btn[0].sprite, initrect(0, 0, 340, 88));
    STR(BUILD_PREPLAY.btn[1].sprite, initrect(0, 0, 340, 88));
    BUILD_PREPLAY.text[0] = C(PATH_FONT, "Home", p1.x + xp, p1.y + 20);
    BUILD_PREPLAY.text[1] = C(PATH_FONT, "Next", p2.x + xp, p2.y + 20);
}

void initsprite_again(game_t *g)
{
    int x = g->window.size_window.x / 2;
    float xp = getpourcentage_x(g, 18);
    int b = getpourcentage_y(g, 32);

    BUILD_PREPLAY.button_text[0] = C(PATH_FONT, STR_ONBTN, x + xp, b);
    BUILD_PREPLAY.button_text[1] = C(PATH_FONT, STR_ONBTN, x + xp, b + 120);
    BUILD_PREPLAY.button_text[2] = C(PATH_FONT, STR_ONBTN, x + xp, b + 220);
    BUILD_PREPLAY.button_text[3] = C(PATH_FONT, STR_ONBTN, x + xp, b + 320);
    BUILD_PREPLAY.button_text[4] = C(PATH_FONT, STR_ONBTN, x + xp, b + 420);
    for (int i = 0; i < 5; i++)
        STR(BUILD_PREPLAY.button[i].sprite, initrect(0, 0, 340, 88));
    init_spritebtn(g);
}

void init_otherpre(game_t *g)
{
    sfVector2f p1 = init_vector(getpourcentage_x(g, 30),
    getpourcentage_y(g, 45));
    sfVector2f p2 = init_vector(getpourcentage_x(g, 50),
    getpourcentage_y(g, 45));

    g->obj.menu.list_save = NULL;
    g->obj.menu.preplay.button_choice[0].sprite = create_sprite(PATH_BUTTON);
    g->obj.menu.preplay.button_choice[1].sprite = create_sprite(PATH_BUTTON);
    SP(BUILD_PREPLAY.button_choice[0].sprite, p1);
    SP(BUILD_PREPLAY.button_choice[1].sprite, p2);
    STR(BUILD_PREPLAY.button_choice[0].sprite, initrect(0, 0, 340, 88));
    STR(BUILD_PREPLAY.button_choice[1].sprite, initrect(0, 0, 340, 88));
    BUILD_PREPLAY.text_choice[0] = C(PATH_FONT, STR_N_CHAR,
    p1.x + 30, p1.y + 30);
    BUILD_PREPLAY.text_choice[1] = C(PATH_FONT, STR_L_CHAR,
    p2.x + 30, p2.y + 30);
}