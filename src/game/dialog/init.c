/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init.c
*/

#include "rpg.h"

void init_textdialog(game_t *g)
{
    sfVector2f pos;
    char *str[3] = {"Continuer...", NONE, "Je dois y aller"};

    pos = init_vector(getpourcentage_x(g, 55), getpourcentage_y(g, 65));
    for (int i = 0; i < 3; i++) {
        BUILD_DIALOG.text_btn[i] = create_text(PATH_FONT, str[i], pos.x, pos.y);
        pos.y += 120;
    }
}

void init_rectdialog(game_t *g)
{
    sfVector2f pos;
    sfVector2f size = init_vector(600, 100);

    pos = init_vector(getpourcentage_x(g, 50), getpourcentage_y(g, 64));
    for (int i = 0; i < 3; i++) {
        BUILD_DIALOG.btn[i] = sfRectangleShape_create();
        sfRectangleShape_setPosition(BUILD_DIALOG.btn[i], pos);
        pos.y += 120;
        sfRectangleShape_setSize(BUILD_DIALOG.btn[i], size);
        sfRectangleShape_setFillColor(BUILD_DIALOG.btn[i], MARRON);
    }
}

void init_spritedialog(game_t *g)
{
    sfIntRect rect = initrect(0, 0, 3372 / 6, 652);

    BUILD_DIALOG.background.sprite = create_sprite(PATH_BACKGROUNDDIALOG);
    for (int i = 0; i < 6; i++) {
        BUILD_DIALOG.icon_pnj[i].sprite = create_sprite(PATH_ICONDIALOG);
        STR(BUILD_DIALOG.icon_pnj[i].sprite, rect);
        move_rect(&rect, 3372 / 6, 3372);
    }
}

void init_dialog(game_t *g)
{
    consolelog(INIT, "Begin of Init_Dialog");
    init_spritedialog(g);
    init_rectdialog(g);
    consolelog(INIT, "[50%] Init_Dialog");
    init_textdialog(g);
    BUILD_DIALOG.load_this = FALSE;
    consolelog(INIT, "End of Init_Dialog");
    BUILD_DIALOG.linked_dialog = NULL;
}