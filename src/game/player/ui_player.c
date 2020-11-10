/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** ui_player
*/

#include "rpg.h"

void init_ui_player(game_t *g)
{
    sfIntRect rect = {0, 0, 310, 38};
    sfVector2f vec;

    vec.x = g->window.vc_view.x-540;
    vec.y = g->window.vc_view.y-470;
    init_item_sprite(&g->player.ui, "./assets/ui.png", rect);
    sfSprite_setPosition(g->player.ui.sprite, vec);
    sfSprite_setScale(g->player.ui.sprite, (sfVector2f){0.8, 0.8});
    g->player.text[0] = create_text(PATH_FONT, my_atoi(g->player.life), \
    vec.x+35, vec.y-5);
    g->player.text[1] = create_text(PATH_FONT, my_atoi(g->player.gold), \
    vec.x+119, vec.y-5);
}

void display_ui_player(game_t *g)
{
    sfText_setString(g->player.text[0], my_atoi(g->player.life));
    sfText_setString(g->player.text[1], my_atoi(g->player.gold));
    sfRenderWindow_drawSprite(g->window.window, g->player.ui.sprite, NULL);
    for (int i = 0; i < 2; i++)
        sfRenderWindow_drawText(g->window.window, g->player.text[i], NULL);
}