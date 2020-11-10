/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** transition.h
*/

#ifndef H_WINDOW_TRANSITION
#define H_WINDOW_TRANSITION

#include "struct.h"

#define EVIL_BOAT "./assets/evil.png"

void init_transition(game_t *g);
void manage_transition(game_t *g);
void display_transition(game_t *g);
void loop_transition(game_t *g);
my_data_t create_datatransi(char *path, sfVector2f spawn, sfVector2f dest,
int time);
void add_pnjtransi(my_list_t **list, my_data_t data);
void animationpnj(game_t *g);
void end_cinematic(game_t *g);
void free_transition(game_t *g);

#endif