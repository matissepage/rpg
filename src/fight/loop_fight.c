/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** loop_fight.c
*/

#include "rpg.h"

void change_dataenemy(game_t *g, sprite_t enemis)
{
    g->obj.fight.ennemis = enemis;
    g->obj.fight.ennemis.type = enemis.type;
}

void reset_status(game_t *game)
{
    game->obj.fight.atk = 0;
    game->obj.fight.etat = 0;
    game->obj.fight.turn = 1;
}

void ennemy_attack_turn(game_t *game)
{
    game->obj.fight.gest.time2 = SCGET(game->obj.fight.gest.clock2);
    game->obj.fight.gest.sec2 = \
    game->obj.fight.gest.time2.microseconds / 1000000.0;
    SRWDS(game->window.window, game->obj.fight.attack_ennemis[0].sprite, NULL);
    SRWDT(game->window.window, game->obj.fight.gest.text_clock2, NULL);
    sfText_setString(game->obj.fight.gest.text_clock2, \
    my_itc(game->obj.fight.gest.sec + 2));
    move_fireball_ennemy(game);
    reset_pos_fireball_player(game);
    if (game->obj.fight.gest.sec2 > 1.5) {
        game->obj.fight.etat = 0;
        game->obj.fight.turn = 0;
        sfClock_restart(game->obj.fight.gest.clock2);
    }
}

void gestion_attack_time(game_t *game)
{
    if (manage_attack_fight(game) == 1) {
        game->obj.fight.gest.time = SCGET(game->obj.fight.gest.clock);
        game->obj.fight.gest.sec = \
        game->obj.fight.gest.time.microseconds / 1000000.0;
        SRWDT(game->window.window, game->obj.fight.gest.text_clock, NULL);
        sfText_setString(game->obj.fight.gest.text_clock, \
        my_itc(game->obj.fight.gest.sec));
        if (game->obj.fight.gest.sec > 1.5) {
            reset_status(game);
            sfClock_restart(game->obj.fight.gest.clock);
        }
    }
}

void loop_fight(game_t *game)
{
    display_fight(game);
    if (game->obj.fight.turn == 0) {
        reset_pos_fireball_ennemy(game);
        lunchattackwithkey(game);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            game->obj.fight.etat = 1;
        }
    }
    if (game->obj.fight.etat == 1) {
        gestion_attack_time(game);
    } else
        sfClock_restart(game->obj.fight.gest.clock);
    if (game->obj.fight.turn == 1) {
        ennemy_attack_turn(game);
    } else
        sfClock_restart(game->obj.fight.gest.clock2);
    sfRenderWindow_display(game->window.window);
}