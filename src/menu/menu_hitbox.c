/*
** EPITECH PROJECT, 2020
** menu_hitbox.c
** File description:
** menu_hitbox.c
*/

#include "rpg.h"

int test_hitbox_o(sfVector2f pos, sfVector2f posobject, int w, int h)
{
    int enter_compteur = 0;
    if (pos.x >= posobject.x - (w / 2))
        enter_compteur++;
    if (pos.x <= posobject.x + (w / 2))
        enter_compteur++;
    if (pos.y >= posobject.y - (h / 2))
        enter_compteur++;
    if (pos.y <= posobject.y + (h / 2))
        enter_compteur++;
    if (enter_compteur == 4)
        return 1;
    return 0;
}

void set_player_pos1(game_t *game)
{
    int y = (game->window.size_window.y / 2) - (256 / 4) * 3;
    int x = (game->window.size_window.x / 2) - (160 / 5) * 3;
    sfVector2f tmp = init_vector(x, y);

    sfSprite_setPosition(player_.cape, tmp);
    sfSprite_setPosition(player_.cloth, tmp);
    sfSprite_setPosition(player_.eyes, tmp);
    sfSprite_setPosition(player_.hair, tmp);
    sfSprite_setPosition(player_.skin, tmp);
    sfSprite_setScale(player_.cape, init_vector(3, 3));
    sfSprite_setScale(player_.cloth, init_vector(3, 3));
    sfSprite_setScale(player_.eyes, init_vector(3, 3));
    sfSprite_setScale(player_.hair, init_vector(3, 3));
    sfSprite_setScale(player_.skin, init_vector(3, 3));
}

void check_click(game_t *game)
{
    if (test_hitbox_o(game->var.pos_mouse_click,\
    sfSprite_getPosition(game->obj.menu.buttons[0].sprite), 340, 88) == 1) {
        game->etat = HTP;
        set_player_pos1(game);
    }
    if (test_hitbox_o(game->var.pos_mouse_click,\
    sfSprite_getPosition(game->obj.menu.buttons[1].sprite), 340, 88) == 1) {
        game->etat = SETTINGS;
        game->var.pos_mouse_click = init_vector(-100, -100);
    }
    if (test_hitbox_o(game->var.pos_mouse_click,\
    sfSprite_getPosition(game->obj.menu.buttons[2].sprite), 340, 88) == 1)
        game->etat = CREDITS;
    if (test_hitbox_o(game->var.pos_mouse_click,\
    sfSprite_getPosition(game->obj.menu.buttons[3].sprite), 340, 88) == 1)
        game->etat = END;
}