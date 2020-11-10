/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** call_fightquest.c
*/

#include "rpg.h"

void mob_addrect(sprite_t *mob, sfIntRect rect)
{
    mob->rect = rect;
}

sprite_t create_mob(char *path_sprite, int pv, int damage, int type)
{
    sprite_t new_data;

    new_data.sprite = create_sprite(path_sprite);
    new_data.pv = pv;
    new_data.damage = damage;
    new_data.type = type;
    return (new_data);
}

void  backupafterfight(game_t *g, int save, sfVector2f pos_save)
{
    sfSprite_setScale(g->player.player.cape, (sfVector2f) {1, 1});
    sfSprite_setScale(g->player.player.cloth, (sfVector2f) {1, 1});
    sfSprite_setScale(g->player.player.eyes, (sfVector2f) {1, 1});
    sfSprite_setScale(g->player.player.skin, (sfVector2f) {1, 1});
    sfSprite_setScale(g->player.player.hair, (sfVector2f) {1, 1});
    change_pos_player_g(g, pos_save);
    g->player.pos = pos_save;
    g->etat = save;
}

void beforecallfight(game_t *g)
{
    g->obj.fight.win = -1;
    sfRenderWindow_clear(g->window.window, sfBlack);
    change_view(g, 1080, 1920);
    init_fight(g);
    g->etat = FIGHT;
}

void call_fightquest(game_t *g, sprite_t mob)
{
    int active = TRUE;
    int save = g->etat;
    sfVector2f pos_save = sfSprite_getPosition(g->player.player.cape);

    g->obj.fight.ennemis = mob;
    beforecallfight(g);
    lunch_animationopen(g);
    while (sfRenderWindow_isOpen(g->window.window) && active) {
        manage_eventgame(g);
        if (g->obj.fight.win != -1)
            active = FALSE;
        loop_fight(g);
    }
    backupafterfight(g, save, pos_save);
    if (g->obj.fight.win == FALSE)
        g->etat = LOOSE;
}