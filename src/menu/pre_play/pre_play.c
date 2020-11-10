/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** pre_play.c
*/

#include "rpg.h"

void check_redirection(game_t *g)
{
    int save1 = g->player.map_actu;

    if (test_hitbox(M, G(BUILD_PREPLAY.btn[0].sprite), 340, 88) == 1) {
        g->etat = MENU;
        return;
    }
    if (test_hitbox(M, G(BUILD_PREPLAY.btn[1].sprite), 340, 88) == 1) {
        if (g->obj.menu.preplay.bool_name == FALSE)
            if (my_strcmp(BUILD_PREPLAY.name, MESSAGE_USERNAME) == 0)
                return;
        g->etat = INTRO_GAME;
        g->player.name = malloc(sizeof(char) *
        (my_strlen(BUILD_PREPLAY.name) + 1));
        g->player.name = my_strcpy(g->player.name, BUILD_PREPLAY.name);
        init_all_game(g);
        set_pos_player_default(g, 840, 362);
        save_myprofile(g, init_vector(0, 0));
        consolelog(GAME_ETAT, "PrePlay => Intro Game");
        if (save1 != 1)
            init_other_map(g, save1);
        return;
    }
}

void update_text(game_t *g)
{
    int x = (g->window.size_window.x / 2) - (160 / 5) * 3;
    int y = (g->window.size_window.y / 2) - (256 / 4) * 3;
    sfVector2f tmp = init_vector(x, y);

    SP(g->player.player.cape, tmp);
    SP(g->player.player.cloth, tmp);
    SP(g->player.player.eyes, tmp);
    SP(g->player.player.hair, tmp);
    SP(g->player.player.skin, tmp);
    sfText_setString(g->obj.menu.preplay.name_text, g->obj.menu.preplay.name);
}

void test_clickbuttonpreplay(game_t *g)
{
    sfVector2f m = g->var.pos_mouse_click;
    if (test_hitbox(m, G(BUILD_PREPLAY.button_choice[0].sprite),\
    344, 88) == 1) {
        g->obj.menu.preplay.etat_preplay = 1;
        consolelog(OTHER, "Create a new Character !");
    }
    if (test_hitbox(m, G(BUILD_PREPLAY.button_choice[1].sprite),
    344, 88) == 1) {
        g->obj.menu.preplay.etat_preplay = 2;
        consolelog(OTHER, "Load a Character !");
        find_savegpre(g);
    }
}

void preplay_firstscene(game_t *g)
{
    sfRenderWindow_drawSprite(W, BUILD_PREPLAY.bg, NULL);
    D(W, g->obj.menu.preplay.button_choice[0].sprite, NULL);
    D(W, g->obj.menu.preplay.button_choice[1].sprite, NULL);
    T(W, BUILD_PREPLAY.text_choice[0], NULL);
    T(W, BUILD_PREPLAY.text_choice[1], NULL);
    test_clickbuttonpreplay(g);
}

void pre_play(game_t *g)
{
    int time = sfClock_getElapsedTime(g->window.clock).microseconds / 10000;
    if (time > 10) {
        sfRenderWindow_clear(W, sfColor_fromRGB(4, 181, 253));
        if (g->obj.menu.preplay.etat_preplay == 0) {
            preplay_firstscene(g);
        }else if (g->obj.menu.preplay.etat_preplay == 1) {
            sfRenderWindow_drawSprite(W, BUILD_PREPLAY.bg, NULL);
            update_text(g);
            draw_preplay(g);
            manage_colorselection(g);
            check_redirection(g);
        } else
            save_filepre(g);
        sfRenderWindow_display(W);
        sfClock_restart(g->window.clock);
    }
}