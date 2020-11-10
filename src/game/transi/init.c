/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init.c
*/

#include "rpg.h"

void init_texttransi(game_t *g)
{
    char *str[] = {
        "Bon, on en fait quoi\nmaintenant ?\nIl est rentre\nchez le vieux",
        "Je ne sais pas...\n Tu l'as fouille ?",
        "Non.\nJe vais m'en occuper",
        "C'est quoi ces traces\nqu'il a dans le dos ?!",
        "On dirait qu'il\navait des ailes..\n qui lui on etait arraches",
        "Sa change tous...\nLes demons\nauront une bourse pour nous..."
    };
    int x[] = {900, 750, 900, 750, 900, 750, 900, 0, 0, 0, 0, 0};
    int y[] = {1980, 2080, 1980, 2080, 1980, 2080, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < 6; i++) {
        g->transi.bulle_dialog[i].text =
        create_text(PATH_FONT, str[i], x[i], y[i]);
        sfText_setCharacterSize(g->transi.bulle_dialog[i].text, 20);
        sfText_setColor(g->transi.bulle_dialog[i].text, sfBlack);
    }
}

void init_bull(game_t *g)
{
    char *path = "./assets/speech.png";
    sfVector2f vec = (sfVector2f) {-0.3, 0.3};
    sfIntRect rect = initrect(0, 0, 1200, (2914 / 3));

    for (int i = 0; i < 6; i++) {
        g->transi.bulle_dialog[i].sprite = create_sprite(path);
        sfSprite_setTextureRect(g->transi.bulle_dialog[i].sprite, rect);
        sfSprite_setScale(g->transi.bulle_dialog[i].sprite, vec);
    }
    sfSprite_setPosition(g->transi.bulle_dialog[0].sprite,
    (sfVector2f) {1170, 1920});
    sfSprite_setPosition(g->transi.bulle_dialog[1].sprite,
    (sfVector2f) {1020, 2020});
    sfSprite_setPosition(g->transi.bulle_dialog[2].sprite,
    (sfVector2f) {1170, 1920});
    sfSprite_setPosition(g->transi.bulle_dialog[3].sprite,
    (sfVector2f) {1020, 2020});
    sfSprite_setPosition(g->transi.bulle_dialog[4].sprite,
    (sfVector2f) {1170, 1920});
    sfSprite_setPosition(g->transi.bulle_dialog[5].sprite,
    (sfVector2f) {1020, 2020});
}

void init_transition(game_t *g)
{
    sfVector2f spawn = (sfVector2f) {1126, 1944};
    sfVector2f spawn1 = (sfVector2f) {1000, 2300};
    sfVector2f spawn2 = (sfVector2f) {1150, 2208};
    sfVector2f dest = (sfVector2f) {2200, 1944};
    sfVector2f dest1 = (sfVector2f) {1000, 2300};
    sfVector2f dest2 = (sfVector2f) {2200, 1944};
    char *PATH_PNJ = "./assets/pnj/pnj1.png";

    g->transi.bigclock = sfClock_create();
    consolelog(INIT, "Transition [0%]");
    g->transi.list = NULL;
    add_pnjtransi(&g->transi.list,
    create_datatransi(EVIL_BOAT, spawn, dest, 30));
    add_pnjtransi(&g->transi.list,
    create_datatransi(PATH_PNJ, spawn1, dest1, 31));
    add_pnjtransi(&g->transi.list,
    create_datatransi(PATH_PNJ, spawn2, dest2, 31));
    init_bull(g);
    init_texttransi(g);
}

void free_transition(game_t *g)
{
    sfClock_destroy(g->transi.bigclock);
    my_list_t *tmp1 = NULL;

    for (my_list_t *tmp = g->transi.list; tmp;) {
        tmp1 = tmp;
        tmp = tmp->next;
        free(tmp1);
    }
    for (int i = 0; i < 6; i++) {
        sfSprite_destroy(g->transi.bulle_dialog[i].sprite);
        sfText_destroy(g->transi.bulle_dialog[i].text);
    }
}