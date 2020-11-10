/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** rpg.h
*/

#ifndef MY_RPG_H
#define MY_RPG_H

#include "my_printf.h"
#include "my.h"
#include "struct.h"
#include "define.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <math.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/types.h>
#include <dirent.h>
#include <math.h>
#include "transition.h"

#define W_WINDOW
#define H_WINDOW

/*/////////////////////////////////////////|
                 WHILE INFIN               |
*/////////////////////////////////////////*|

void manage_scene(game_t *game);
void manage_eventgame(game_t *game);
void change_view(game_t *game, int height, int width);
void remove_node_pos(my_list_t **list, int position);
void finishquest3(game_t *g);
void lunch_animationopen(game_t *g);
void init_map_4(game_t *game, struct stat info);
void init_map_5(game_t *game, struct stat info);
sprite_t sendmonster(int id, int pv, int damage, int type);
void init_view_map(game_t *game);
void init_map_1(game_t *game, struct stat info);

/*/////////////////////////////////////////|
                 TEST HITBOX               |
*/////////////////////////////////////////*|

int test_hitbox(sfVector2f pos, sfVector2f posobject, int w, int h);
sfVector2f init_vector(int x, int y);
sfIntRect initrect(int top, int left, int w, int h);
void move_rect(sfIntRect *rect, int offset, int max);
sfSprite *create_sprite(char *path);
sfText *create_text(char *path_font, char *str, int x, int y);
char *my_itc(int nbr);

/*/////////////////////////////////////////|
                 LOOP GAME                 |
*/////////////////////////////////////////*|

void loop_game(game_t *game);

/*/////////////////////////////////////////|
                MANAGE_QUEST               |
*/////////////////////////////////////////*|

void manage_quest(game_t *g);
void manage_drawquest(game_t *g);

/*/////////////////////////////////////////|
                 PLAYER GAME               |
*/////////////////////////////////////////*|

void move_vector(sfVector2f *vector, float x, float y);
void moove_ui_d(game_t *g, float coef);
void move_ui_z(game_t *g, float coef);
void move_ui_q(game_t *g, float coef);
void move_ui_s(game_t *g, float coef);
void draw_player_game(game_t *g);
void move_rect_right(game_t *g);
void move_rect_left(game_t *g);
void move_rect_down(game_t *g);
void move_rect_up(game_t *g);
void init_player_rect_g(game_t *g);
void move_player(game_t *g, sfEvent evt);
void move_player_right(game_t *g, float coef);
void move_player_up(game_t *g, float coef);
void move_player_down(game_t *g, float coef);
void move_player_left(game_t *g, float coef);
int recup_pos_player_y(char **map);
int recup_pos_player_x(char **map);
void moove_player_dtxt(char **map, game_t *g);
void moove_player_qtxt(char **map, game_t *g);
void moove_player_stxt(char **map, game_t *g);
void moove_player_ztxt(char **map, game_t *g);
void draw_basi_player(game_t *g);
void animation_right(game_t *g);
void play_on_wall(game_t *game);
void play_on_buy(game_t *game);
void display_ui_player(game_t *g);

/*/////////////////////////////////////////|
                 INIT                      |
*/////////////////////////////////////////*|

void init_sprite_game(char const *path, sfIntRect rect, sprite_t *sprite);
void init_all_game(game_t *game);
void pre_play(game_t *game);
void manage_arrow(game_t *g);
void init_preplay(game_t *game);
void save_filepre(game_t *g);
void draw_preplay(game_t *g);
void init_color(game_t *g);
float getpourcentage_x(game_t *game, float pourcentage);
float getpourcentage_y(game_t *game, float pourcentage);
sfVector2f where_is_my_mouse(sfRenderWindow* window);
char *get_next_line(const int fd);
void load_saverecolor(game_t *g, int nbr[]);
void parse_colorpre(game_t *g, char *path);
void move_background(game_t *game);
void init_menu(game_t *game);
void check_click(game_t *game);
int test_hitbox_o(sfVector2f pos, sfVector2f posobject, int w, int h);
void drawsprite_menu(game_t *g);
void intro_game(game_t *g);
void settings(game_t *g);
void save_myprofile(game_t *g, sfVector2f pos);
char *create_myposjoueur(sfVector2f pos);
void find_savegpre(game_t *g);
void manage_colorselection(game_t *g);
void set_panelrect(game_t *g);
void set_panel(game_t *g);
void interaction_settings(game_t *g);
void is_mouse_on_btn(game_t *game, sfSprite *sprite, sfIntRect rect);
void set_credits_text(game_t *game);
void menu(game_t *game);
void init_background(game_t *game);
void anim_button(game_t *game, sfSprite *sprite, sfIntRect rect);
void credits(game_t *game);
void reset_anim_button(sfSprite *sprite, sfIntRect rect);
void set_pos_player_default(game_t *g, float x, float y);
void init_all_item(game_t *game);
void initsprite_again(game_t *g);
void init_otherpre(game_t *g);
void load_positionplayer(game_t *g, char *str);
void save_pos(game_t *g, sfVector2f pos);
void init_map_txt(game_t *game);
void get_parsedialoglinkedlistend(game_t *g);
void init_shop(game_t *g);
void init_ui_player(game_t *g);
void init_sounds(game_t *game);
void play_first_music(game_t *game);
void play_second_music(game_t *game);
void init_waiting_screen(game_t *game);
void draw_waiting_screen(game_t *game);
void init_mob_map1(game_t *g);
void init_map_2(game_t *game, struct stat info);
void init_map_1(game_t *game, struct stat info);
void init_sprite_wht_rect(char const *path, int x, int y, sprite_t *sprite);
void checkclickbtntrue2(game_t *g);
void draw_htp(game_t *game);
void init_htp(game_t *game);
void init_win_screen(game_t *game);
void draw_win(game_t *game);
void init_loose_screen(game_t *game);
void draw_loose(game_t *game);
void event_invt_game(game_t *game, sfEvent evt);

/*/////////////////////////////////////////|
                 INVENTORY                 |
*/////////////////////////////////////////*|

void init_item_sprite(sprite_t *sprite, char const *path, sfIntRect rect);
void init_one_sprite_game(sprite_t *sprite, char const *path, int x, int y);
void draw_inventory(game_t *game);
void init_inventory(game_t *game);
char **read_files_invt(struct stat *file_info, char *path);
void add_node_invt(char *str, link_t *link);
void delete_node(int size, link_t *link);
link_t *init_list(void);
void display_invt_link(link_t *link);
char *pars_data_invt(char **tab, char *id);
char **create_tab_invt(char *map);
link_t *create_link_invt(game_t *game);
int check_save_exist(char *name);
void save_invt(game_t *game);
void write_in_file(char *str, int fd, int space);
void write_data_save(node_t *node, int fd, int end);
node_t *create_item_node(item_t item);
void add_node_item_invt(item_t item, link_t *link);
int item_exist(link_t *link, char *name);
void manage_interaction_dialogend(game_t *g);
void checkclickbtntrue2(game_t *g);
void rendre_quest(game_t *g);
void check_item_select_invt(game_t *g, int x, int y);
void init_map_3(game_t *game, struct stat info);

/*/////////////////////////////////////////|
                 PARSING MAP               |
*/////////////////////////////////////////*|
void search_nb_map(game_t *game, char nb);
char *read_files(struct stat *file_info, char *path);
int files_open(char const *path);
char *recup_data_line(char *buffer, info_t *info, int i);
void get_parsedialoglinkedlistend(game_t *g);
int check_conditionrendu(game_t *g, int id);
my_data_t create_datapopup(int time, char *texte, int state);
void add_popup(my_list_t **list, my_data_t data);

/*/////////////////////////////////////////|
                 EVENT GAME                |
*/////////////////////////////////////////*|
void destroy_quest(game_t *g);
void move_player(game_t *g, sfEvent evt);
void analyse_game(game_t *game, sfEvent evt);
void event_inventory(game_t *game, sfEvent event);

/*/////////////////////////////////////////|
                 FIGHT SCENE               |
*/////////////////////////////////////////*|

// init
void init_fight(game_t *game);
void init_attack_fight(game_t *game);
void init_life_ennemies(game_t *g);
void init_ennemies_fight(game_t *g);
void init_player_fight(game_t *g);
void init_buttonatk_fight(game_t *g);
void init_attack_player_fire(game_t *g);
void init_attack_player_water(game_t *g);
void init_attack_player_mana(game_t *g);
void init_ennemis_attack_fire(game_t *g);
void init_life_text_ennemie(game_t *game);
void init_bg_fight(game_t *g);
void init_bg_button(game_t *g);
void init_bg_type(game_t *g);
void init_all_type(game_t *game);

// display
void display_attack(game_t *g, int i);
void display_fight(game_t *g);
void display_button_atk(game_t *game);
void display_bg_button(game_t *game);
void manage_type(game_t *game);

// movement
void move_life_simple(game_t *game, int i);
void move_rect_ennemy(game_t *game);
void move_water_attack(game_t *game);
void move_fire_attack(game_t *game);
void move_purple_attack(game_t *game);
void move_rect_attack(game_t *game, int i);
void move_fireball_ennemy(game_t *g);
void reset_pos_fireball_ennemy(game_t *g);
void move_fireball_player(game_t *g, int i);
void reset_pos_fireball_player(game_t * g);
void gest_life_ennemy(game_t *game);
void gest_life(game_t *game);
void change_boss(game_t *game);
void gestion_attack_time(game_t *game);

// attack
void choose_atk(game_t *g);
int manage_attack_fight(game_t *game);
void ennemis_turn(game_t *game);
void lunchattackwithkey(game_t *g);

// main fight
void loop_fight(game_t *game);

/*/////////////////////////////////////////|
                   KANYE QUEST             |
*/////////////////////////////////////////*|

void analyse_questevent(game_t *g, sfEvent evt);
int get_idq(char *line_actu);
int get_lvlmin(char *line_actu);
void fill_quest(game_t *g, int map);
char *get_objectwin(char *line_actu);
char *get_dialog(char *line_actu, int id);
void add_quests(my_list_t **list, dataquests_t dataquest);
int get_nbrquest(game_t *g);
void init_charquest(game_t *g);
void draw_pnj(game_t *g);
void dislay_infoquestpnj(game_t *g, sfVector2f pos);
void quest_pnjevent(game_t *g, sfEvent evt);
void interaction_pnjcheck(game_t *g);
int get_xpwin(char *line_actu);
void display_map(game_t *game);
void init_quest(game_t *g);
void notif_user(game_t *g);
void init_questactu(game_t *g);
dataquestactu_t init_dataquestactu(char *name);
void add_nodequestactu(my_list_t **list, dataquestactu_t data);
void check_infoquestactu(game_t *g);
void minimap_displaymanage(game_t *g);
void analyse_eventmap(game_t *g, sfEvent evt);
void remove_charquest(game_t *g);

/*/////////////////////////////////////////|
                   DIALOG                  |
*/////////////////////////////////////////*|

void loop_dialog(game_t *g);
void init_dialog(game_t *g);
void draw_spritedialog(game_t *g);
void get_parsedialoglinkedlist(game_t *g);
void manage_interaction_dialog(game_t *g);
void analyse_indialog(game_t *g, sfEvent event);
void destroy_dialog(game_t *g);
void consolelog(int id, char *str);
void gotodialogbtn2(game_t *g);
void checkclickbtntrue(game_t *g);
void dialoggotogame(game_t *g);
void quest1_main(game_t *g, my_list_t *tmp);
void add_movementpnj(game_t *g, int id_pnj, sfVector2f where);
void move_allpnj(game_t *g);
sfVector2f calc_newvel(sfVector2f start, sfVector2f target, int speed);

/*/////////////////////////////////////////|
                   TOOL                    |
*/////////////////////////////////////////*|
char *my_atoi(int nb);
int size_link(link_t *link);
char **str_to_array(char *str, char sep);
int nb_line_map_txt(char **map);
void print_map_txt(char **map);

/*/////////////////////////////////////////|
                   PAUSE                   |
*/////////////////////////////////////////*|

void init_pause_menu(game_t *game);
void draw_pause_menu(game_t *game);
void pause_menu(game_t *game);
void pause_menu_settings(game_t *game);
void init_pause_menu_option(game_t *game);
void check_pause_settings_click(game_t *game);
void check_pause_settings_click2(game_t *game);
void change_vol(game_t *game, int add);
void pause_menu_settings(game_t *game);
void draw_pause_settings(game_t *game);


/*/////////////////////////////////////////|
                   INTRO                   |
*/////////////////////////////////////////*|

void event_intro(game_t *g, sfEvent evt);
void intro_game(game_t *g);
void init_intro(game_t *g);
void change_view(game_t *game, int height, int width);
void change_pos_player_g(game_t *g, sfVector2f vec);
void set_accept(int id, game_t *g);
void manage_questactive(game_t *g);

/*/////////////////////////////////////////|
                 DESTROYER                 |
*/////////////////////////////////////////*|

void destroy_all(game_t *game);
void destroy_other(game_t *g);

/*/////////////////////////////////////////|
                   SHOP                    |
*/////////////////////////////////////////*|

void check_shop(game_t *g);
void draw_pnj_shop(game_t *g);
void event_pnj_shop(game_t *g, sfEvent evt);
void shop(game_t *g);
void event_shop(game_t *g, sfEvent evt);
void draw_item_shop(game_t *g);
void change_scale_item(game_t *g);
void check_item_select(game_t *g, int x, int y);
void place_item_shop(game_t *g);
node_t *cpy_data_node(node_t *node);

/*/////////////////////////////////////////|
                   MAP                     |
*/////////////////////////////////////////*|

void init_other_map(game_t *game, int map);
void draw_mob(game_t *game);
void button_checkexitdialog(game_t *g);
void button_checkpressdialog(game_t *g);
void button_higllightdialog(game_t *g, int id);
char *get_namedialog(char *str);
int get_iconiddialog(char *str);
sfVector2f get_posquest(char *str);
my_data_t create_datachest(int money, char *object, sfVector2f pos);
void display_chest(game_t *g);
void manage_chest(game_t *g);
void change_datachest(my_list_t **list, int id);
void add_chest(my_list_t **list, my_data_t data);
void init_chest(game_t *g);
void destroy_chest(game_t *g);
void import_chest(game_t *g, int map);
char *get_strintxt(char *str, int sp);
void mob_addrect(sprite_t *mob, sfIntRect rect);
void check_positions(game_t *g);
sprite_t create_mob(char *path_sprite, int pv, int damage, int type);
void display_linkedanim(game_t *g);
void call_fightquest(game_t *g, sprite_t mob);
void get_to_pause(game_t *game);
void init_particles(game_t *game);
void add_particle(const particle_environment_t *particle_environment, \
particle_t *particule, const size_t particle_num, const sfVector2f pos);
void update_particle(const particle_environment_t *particle_environment, \
particle_t *particule);
void display_particle(sfRenderWindow *window, const particle_t *particule, \
sfCircleShape *circle_shape);
void init_particule(const particle_environment_t *particle_environment, \
particle_t *particule, const sfVector2f pos);
void init_particle_environment(particle_environment_t *particle_environment, \
const sfVector2f angle, const sfVector2f gravity, const sfUint8 alpha);
void get_event_particles(game_t *g, sfEvent event);

#endif