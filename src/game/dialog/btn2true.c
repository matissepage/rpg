/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** btn2true.c
*/

#include "rpg.h"

void dialoggotogame(game_t *g)
{
    char *str[3] = {"Continuer...", NONE, "Je dois y aller"};

    consolelog(GAME_ETAT, "GAME");
    g->etat = GAME;
    BUILD_DIALOG.load_this = FALSE;
    BUILD_DIALOG.status_btn2 = FALSE;
    for (int i = 0; i < 3; i++)
        sfText_setString(BUILD_DIALOG.text_btn[i], str[i]);
    destroy_dialog(g);
    change_view(g, 650, 1200);
    consolelog(OTHER, "View Change : 650 1200");
}

void denied_queste(game_t *g)
{
    consolelog(OTHER, "Questes Refused");
    dialoggotogame(g);
}

void add_questequeu(game_t *g)
{
    consolelog(OTHER, "Questes Accepted");
    add_nodequestactu(&BUILD_QUEST.quest_actu, init_dataquestactu( \
    BUILD_DIALOG.quest_actu.name));
    BUILD_DIALOG.quest_actu.accept = TRUE;
    BUILD_DIALOG.quest_actu.rendu = FALSE;
    set_accept(BUILD_DIALOG.quest_actu.id, g);
    dialoggotogame(g);
}

void gotodialogbtn2(game_t *g)
{
    BUILD_DIALOG.status_btn2 = TRUE;
    sfText_setString(BUILD_DIALOG.text_btn[0], "J'accepte la quete !");
    sfText_setString(BUILD_DIALOG.text_btn[1], "Je refuse la quete !");
}

void checkclickbtntrue(game_t *g)
{
    if (test_hitbox(M, RGP(BUILD_DIALOG.btn[0]), 600, 100) == 1)
        add_questequeu(g);
    if (test_hitbox(M, RGP(BUILD_DIALOG.btn[1]), 600, 100) == 1)
        denied_queste(g);
}