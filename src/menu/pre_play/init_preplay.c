/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_preplay.c
*/

#include "rpg.h"

void init_sprite(game_t *g)
{
    int x = g->window.size_window.x / 2;
    float xp = getpourcentage_x(g, 15);
    int begin = getpourcentage_y(g, 30);
    int sup = getpourcentage_y(g, 10);

    for (int i = 0; i < 5; i++)
        BUILD_PREPLAY.button[i].sprite = create_sprite(PATH_BUTTON);
    BUILD_PREPLAY.button[0].vector = init_vector(x + xp, begin);
    BUILD_PREPLAY.button[1].vector = init_vector(x + xp, begin + sup);
    BUILD_PREPLAY.button[2].vector = init_vector(x + xp, begin + sup * 2);
    BUILD_PREPLAY.button[3].vector = init_vector(x + xp, begin + sup * 3);
    BUILD_PREPLAY.button[4].vector = init_vector(x + xp, begin + sup * 4);
    for (int i = 0; i < 5; i++)
        SP(BUILD_PREPLAY.button[i].sprite, BUILD_PREPLAY.button[i].vector);
    initsprite_again(g);
    BUILD_PREPLAY.bg = create_sprite("./assets/menu_bcg/bg.png");
    SP(BUILD_PREPLAY.bg, init_vector(0, 0));
}

void init_text(game_t *g)
{
    int x = (int)g->window.size_window.x / 2;
    int y = (int)g->window.size_window.y / 2;
    int x2 = (int)(g->window.size_window.x / 2) - getpourcentage_x(g, 15);
    int y2 = getpourcentage_y(g, 10);
    char *pathfont = "./assets/fonts/Pacifico.ttf";

    BUILD_PREPLAY.name_text = C(pathfont, " ", x2, y2);
    BUILD_PREPLAY.modif_cape = C(pathfont, "Cape", x + 200, y - 200);
    BUILD_PREPLAY.modif_hair = C(pathfont, "Hair", x + 200, y - 100);
    BUILD_PREPLAY.modif_cloth = C(pathfont, "Cloth", x + 200, y);
    BUILD_PREPLAY.modif_eyes = C(pathfont, "Eyes", x + 200, y + 100);
    BUILD_PREPLAY.modif_skin = C(pathfont, "Skin", x + 200, y + 200);
    BUILD_PREPLAY.name = malloc(sizeof(char) * 100);
    BUILD_PREPLAY.name = my_strcpy(BUILD_PREPLAY.name, MESSAGE_USERNAME);
}

void init_var(game_t *g)
{
    g->obj.menu.preplay.etat_slide = 0;
    set_panel(g);
    set_panelrect(g);
    g->var.pos_mouse_click = init_vector(-100, 100);
    init_sprite(g);
    g->obj.menu.preplay.etat = -1;
    g->obj.menu.preplay.etat_preplay = 0;
}

void init_perso(game_t *game)
{
    player_.cape = create_sprite(PATH_CAPE);
    player_.cloth = create_sprite(PATH_CLOTH);
    player_.eyes = create_sprite(PATH_EYES);
    player_.skin = create_sprite(PATH_SKIN);
    player_.hair = create_sprite(PATH_HAIR);
    STR(player_.cape, initrect(0, 0, 160 / 5, 256 / 4));
    STR(player_.cloth, initrect(0, 0, 160 / 5, 256 / 4));
    STR(player_.eyes, initrect(0, 0, 160 / 5, 256 / 4));
    STR(player_.hair, initrect(0, 0, 160 / 5, 256 / 4));
    STR(player_.skin, initrect(0, 0, 160 / 5, 256 / 4));
}

void init_preplay(game_t *game)
{
    int x = (game->window.size_window.x / 2) - (160 / 5) * 3;
    int y = (game->window.size_window.y / 2) - (256 / 4) * 3;
    sfVector2f tmp = init_vector(x, y);
    init_perso(game);
    SP(player_.cape, tmp);
    SP(player_.cloth, tmp);
    SP(player_.eyes, tmp);
    SP(player_.hair, tmp);
    SP(player_.skin, tmp);
    sfSprite_setScale(player_.cape, init_vector(3, 3));
    sfSprite_setScale(player_.cloth, init_vector(3, 3));
    sfSprite_setScale(player_.eyes, init_vector(3, 3));
    sfSprite_setScale(player_.hair, init_vector(3, 3));
    sfSprite_setScale(player_.skin, init_vector(3, 3));
    init_var(game);
    init_text(game);
    game->obj.click = sfMusic_createFromFile("./assets/music/click1.ogg");
    init_otherpre(game);
}