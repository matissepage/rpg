/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** loop game
*/

#include "rpg.h"

void analyse_game(game_t *game, sfEvent evt)
{
    if (game->etat == GAME) {
        quest_pnjevent(game, evt);
        analyse_questevent(game, evt);
        analyse_eventmap(game, evt);
        if (game->obj.invt.etat != 1)
            move_player(game, evt);
        if (game->obj.invt.etat == 1 && evt.type == sfEvtMouseButtonPressed)
            check_item_select_invt(game, evt.mouseButton.x, evt.mouseButton.y);
        event_invt_game(game, evt);
        event_pnj_shop(game, evt);
        if (evt.key.code == sfKeyM)
            save_invt(game);
    }
    if (game->etat == INTRO_GAME)
        event_intro(game, evt);
}

void display_map(game_t *game)
{
    sfRenderWindow_drawSprite(W_g, game->obj.map[0].sprite, NULL);
}

void get_to_pause(game_t *game)
{
    if ((game->my_event.key.code == sfKeyEscape)\
    && game->my_event.is_released == 1) {
        change_view(game, 1010, 1920);
        sfView_setCenter(game->window.view_game, (sfVector2f){960, 540});
        game->my_event.is_released = 0;
        game->etat = PAUSE;
        consolelog(GAME_ETAT, "game etat = pause");
    }
}

void inloop_gameview(game_t *game)
{
    game->window.time = sfClock_getElapsedTime(game->window.clock);
    game->window.sec = game->window.time.microseconds / 10000.0;
    sfRenderWindow_setView(W_g, game->window.view_game);
}

void loop_game(game_t *game)
{
    inloop_gameview(game);
    if (game->window.sec > 1) {
        sfRenderWindow_clear(W_g, sfBlack);
        if (game->map.etat_map == CIN_TRANSITION) {
            loop_transition(game);
            return;
        } else {
            display_map(game);
            draw_pnj_shop(game);
            draw_player_game(game);
            manage_quest(game);
            manage_chest(game);
            get_to_pause(game);
            display_linkedanim(game);
            draw_mob(game);
            if (game->obj.invt.etat == 1)
                draw_inventory(game);
            minimap_displaymanage(game);
            check_positions(game);
            if (game->player.life <= 0)
                game->etat = LOOSE;
            sfClock_restart(game->window.clock);
            sfRenderWindow_display(W_g);
        }
    }
}