/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** manage_scene.c
*/

#include "rpg.h"

void move_background(game_t *game);

void init_settings(game_t *g);

void init_all(game_t *g)
{
    init_settings(g);
    init_menu(g);
    set_credits_text(g);
    init_quest(g);
    init_pause_menu(g);
    init_dialog(g);
    init_intro(g);
    init_pause_menu_option(g);
    init_sounds(g);
    init_waiting_screen(g);
    init_preplay(g);
    init_htp(g);
    init_win_screen(g);
    init_loose_screen(g);
    init_particles(g);
    g->player.map_actu = 1;
    g->player.gold = 1000;
    g->player.life = 10;
    g->win = FALSE;
    consolelog(INIT, "End init all\n\n\n");
}

void scene_game(game_t *game)
{
    if (game->etat == GAME)
        loop_game(game);
    if (game->etat == PREPLAY)
        pre_play(game);
    if (game->etat == MENU)
        menu(game);
    if (game->etat == HTP)
        draw_htp(game);
    if (game->etat == FIGHT)
        loop_fight(game);
    if (game->etat == OPT)
        pause_menu_settings(game);
    if (game->etat == CREDITS)
        credits(game);
    if (game->etat == PAUSE)
        pause_menu(game);
    if (game->etat == WIN)
        draw_win(game);
    if (game->etat == LOOSE)
        draw_loose(game);
}

void scene_other(game_t *game)
{
    if (game->etat == INTRO_GAME)
        intro_game(game);
    if (game->etat == SETTINGS)
        settings(game);
    if (game->etat == DIALOG)
        loop_dialog(game);
    if (game->etat == SHOP)
        shop(game);
    if (game->etat == INVT)
        draw_inventory(game);
}

void manage_scene(game_t *game)
{
    init_all(game);
    game->var.music = sfFalse;
    sfMusic_pause(game->background.music.music);
    while (sfRenderWindow_isOpen(game->window.window)) {
        if (game->allow_event == TRUE)
            manage_eventgame(game);
        scene_game(game);
        scene_other(game);
        if (game->etat == END) {
            destroy_all(game);
            return;
        }
    }
}