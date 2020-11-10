/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** event.c
*/

#include "rpg.h"

sfVector2f where_is_my_mouse(sfRenderWindow* window)
{
    sfVector2i tempo;
    sfVector2f new;
    tempo = sfMouse_getPositionRenderWindow(window);
    new.x = (float)tempo.x;
    new.y = (float)tempo.y;

    return (new);
}

void manage_eventpreplay(game_t *g, sfEvent event)
{
    if (event.type == sfEvtTextEntered) {
        if (g->obj.menu.preplay.index > 37 || \
        !(g->var.pos_mouse_click.y < 200 && g->var.pos_mouse_click.x > 200))
            return;
        g->obj.menu.preplay.name[g->obj.menu.preplay.index++] = \
        event.text.unicode;
        g->obj.menu.preplay.name[g->obj.menu.preplay.index] = '\0';
    }
}

void do_key_released(game_t *game, sfEvent event)
{
    game->my_event.is_released = 1;
    game->my_event.key = event.key;
}

void basic_event(game_t *g, sfEvent event)
{
    switch(event.type) {
        case sfEvtClosed:
            sfRenderWindow_close(g->window.window);
            g->etat = END;
            break;
        case sfEvtMouseButtonPressed :
            g->var.pos_mouse_click.x = event.mouseButton.x;
            g->var.pos_mouse_click.y = event.mouseButton.y;
            break;
        case sfEvtKeyReleased :
            do_key_released(g, event);
            break;
        default:
            break;
    }
    analyse_game(g, event);
    event_shop(g, event);
    if (g->etat == DIALOG)
        analyse_indialog(g, event);
    event_inventory(g, event);
}

void manage_eventgame(game_t *g)
{
    sfEvent event;

    g->var.pos_mouse = where_is_my_mouse(g->window.window);
    while (sfRenderWindow_pollEvent(g->window.window, &event)) {
        switch(event.type) {
            case sfEvtClosed:
                sfRenderWindow_close(g->window.window);
                g->etat = END;
                break;
            case sfEvtMouseButtonPressed:
                g->var.pos_mouse_click.x = event.mouseButton.x;
                g->var.pos_mouse_click.y = event.mouseButton.y;
                break;
            case sfEvtTextEntered:
                manage_eventpreplay(g, event);
            default:
                break;
        }
        get_event_particles(g, event);
        basic_event(g, event);
    }
}