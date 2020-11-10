/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_fight.c
*/

#include "rpg.h"

void init_clock_click(game_t *g)
{
    g->obj.fight.gest.clock = sfClock_create();
    g->obj.fight.gest.clock2 = sfClock_create();
    g->obj.fight.gest.clock3 = sfClock_create();
    char *msg = my_itc(g->obj.fight.gest.sec);
    char *msg2 = my_itc(g->obj.fight.gest.sec2);
    int x = 1560;
    int y = 740;
    char *pathfont = "./assets/fonts/Pacifico.ttf";
    g->obj.fight.gest.text_clock = create_text(pathfont, msg, x, y);
    g->obj.fight.gest.text_clock2 = create_text(pathfont, msg2, x, y);
}

void init_warning_text(game_t *game)
{
    char *msg = "An attack same type of the\nenemy will not cause it damage.";
    int x = 200;
    int y = 200;
    char *pathfont = "./assets/fonts/Pacifico.ttf";
    game->obj.fight.warning = create_text(pathfont, msg, x, y);
}

void init_fight(game_t *game)
{
    game->obj.fight.turn = 0;
    game->obj.fight.etat = 0;
    game->obj.fight.atk = 0;
    init_bg_fight(game);
    init_bg_type(game);
    init_bg_button(game);
    init_all_type(game);
    init_clock_click(game);
    init_ennemies_fight(game);
    init_life_ennemies(game);
    init_player_fight(game);
    init_attack_player_fire(game);
    init_attack_player_water(game);
    init_attack_player_mana(game);
    init_buttonatk_fight(game);
    init_ennemis_attack_fire(game);
    init_warning_text(game);
}