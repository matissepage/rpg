/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** display.c
*/

#include "rpg.h"

int get_state_transition(sfClock *clock)
{
    int time = sfClock_getElapsedTime(clock).microseconds / 1000000;

    if (time >= 5 && time <= 10)
        return (1);
    if (time >= 10 && time <= 15)
        return (2);
    if (time >= 15 && time <= 20)
        return (3);
    if (time >= 20 && time <= 25)
        return (4);
    if (time >= 25 && time <= 30)
        return (5);
    if (time >= 30 && time <= 35)
        return (6);
    if (time >= 35 && time <= 40)
        return (6);
    if (time >= 40)
        return (7);
    return (-1);
}

void display_transition(game_t *g)
{
    int where_time = get_state_transition(g->transi.bigclock);
    for (my_list_t *tmp = g->transi.list; tmp ; tmp = tmp->next) {
        sfSprite_setPosition(tmp->data.sprite, tmp->data.pos);
    }
    for (my_list_t *tmp = g->transi.list; tmp ; tmp = tmp->next)
        D(W, tmp->data.sprite, NULL);
    if (where_time >= 1 && where_time <= 6) {
        D(W, g->transi.bulle_dialog[where_time - 1].sprite, NULL);
        T(W, g->transi.bulle_dialog[where_time - 1].text, NULL);
    }
    if (where_time == 7)
        end_cinematic(g);
}

void loop_transition(game_t *g)
{
    display_map(g);
    draw_player_game(g);
    get_to_pause(g);
    display_transition(g);
    display_linkedanim(g);
    sfRenderWindow_display(W);
    sfClock_restart(g->window.clock);
}