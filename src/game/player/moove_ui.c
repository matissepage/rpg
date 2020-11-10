/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** moove_ui
*/

#include "rpg.h"

void moove_ui_d(game_t *g, float coef)
{
    sfVector2f vec = sfSprite_getPosition(g->player.ui.sprite);

    move_vector(&vec, coef, 0);
    SP(g->player.ui.sprite, vec);
    vec = sfText_getPosition(g->player.text[0]);
    move_vector(&vec, coef, 0);
    sfText_setPosition(g->player.text[0], vec);
    vec = sfText_getPosition(g->player.text[1]);
    move_vector(&vec, coef, 0);
    sfText_setPosition(g->player.text[1], vec);
}

void move_ui_z(game_t *g, float coef)
{
    sfVector2f vec = sfSprite_getPosition(g->player.ui.sprite);

    move_vector(&vec, 0, -coef);
    SP(g->player.ui.sprite, vec);
    vec = sfText_getPosition(g->player.text[0]);
    move_vector(&vec, 0, -coef);
    sfText_setPosition(g->player.text[0], vec);
    vec = sfText_getPosition(g->player.text[1]);
    move_vector(&vec, 0, -coef);
    sfText_setPosition(g->player.text[1], vec);
}

void move_ui_q(game_t *g, float coef)
{
    sfVector2f vec = sfSprite_getPosition(g->player.ui.sprite);

    move_vector(&vec, -coef, 0);
    SP(g->player.ui.sprite, vec);
    vec = sfText_getPosition(g->player.text[0]);
    move_vector(&vec, -coef, 0);
    sfText_setPosition(g->player.text[0], vec);
    vec = sfText_getPosition(g->player.text[1]);
    move_vector(&vec, -coef, 0);
    sfText_setPosition(g->player.text[1], vec);
}

void move_ui_s(game_t *g, float coef)
{
    sfVector2f vec = sfSprite_getPosition(g->player.ui.sprite);

    move_vector(&vec, 0, coef);
    SP(g->player.ui.sprite, vec);
    vec = sfText_getPosition(g->player.text[0]);
    move_vector(&vec, 0, coef);
    sfText_setPosition(g->player.text[0], vec);
    vec = sfText_getPosition(g->player.text[1]);
    move_vector(&vec, 0, coef);
    sfText_setPosition(g->player.text[1], vec);
}