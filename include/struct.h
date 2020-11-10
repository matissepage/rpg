/*
** EPITECH PROJECT, 2020
** struct
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include "struct.h"
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
#include "define.h"

/*/////////////////////////////////////////|
                 ENUM                      |
*/////////////////////////////////////////*|

typedef enum enum_g {
    MENU,
    INTRO_GAME,
    PREPLAY,
    PAUSE,
    GAME,
    OPT,
    CREDITS,
    SETTINGS,
    FIGHT,
    END,
    SHOP,
    DIALOG,
    HTP,
    LOOSE,
    WIN,
    INVT,
} game_e;

typedef enum type_info {
    TOP,
    LEFT,
} type_infoe;

typedef enum perso {
    CAPE,
    HAIR,
    EYES,
    CLOTH,
    SKIN,
} perso_e;

typedef enum myfight_s {
    WATER,
    FIRE,
    MANA,
} myfight_t;

typedef enum id_log {
    OTHER,
    DESTROY,
    GAME_ETAT,
    INIT,
    ERROR,
} id_log_e;

typedef enum id_typeanim {
    MOVEMENT,
    ATTACK,
    ANIMATION,
    DEATH
} id_typeanim_e;

/*/////////////////////////////////////////|
                 PARSING                   |
*/////////////////////////////////////////*|

typedef struct info_s {
    char *data;
    char **map;
    int height;
    int widht;
} info_t;

/*/////////////////////////////////////////|
                WINDOW                     |
*/////////////////////////////////////////*|

typedef struct window_s {
    sfRenderWindow *window;
    sfVector2f size_window;
    sfEvent evt;
    sfClock *clock;
    sfTime time;
    sfView *view_game;
    sfView *view;
    sfFloatRect rect_view;
    sfVector2f vc_view;
    sfView *mini_map;
    float sec;
} window_t;

/*/////////////////////////////////////////|
                 QUESTS                    |
*/////////////////////////////////////////*|

typedef struct dataquests_s {
    int id;
    int lvl_min;
    int xp_win;
    char *objectwin;
    char *dialog_1;
    char *dialog_2;
    int x;
    int y;
    int etat;
    int icon;
    char *name;
    int accept;
    int rendu;
    int init_beginquest;
} dataquests_t;

/*/////////////////////////////////////////|
        PLAYER AND SPRITE + inventory      |
*/////////////////////////////////////////*|

typedef struct col_s {
    int x;
    int y;
} col_t;

typedef struct sprite_s {
    sfTexture *texture;
    sfRectangleShape *rectangle;
    sfSprite *sprite;
    sfVector2f vector;
    sfIntRect rect;
    sfClock *clock;
    sfTime time;
    sfText *text;
    int velocity;
    float sec;
    int data;
    int pv;
    int damage;
    int type;
    sfBool b_data;
} sprite_t;

typedef struct spriteplayer_s {
    int id_eyes;
    int id_skin;
    int id_hair;
    int id_cape;
    int id_cloth;
    sfSprite *eyes;
    sfSprite *skin;
    sfSprite *hair;
    sfSprite *cape;
    sfSprite *cloth;
    sfIntRect player_r;
    sfIntRect cape_r;
    sfIntRect hair_r;
    sfIntRect skin_r;
    sfIntRect cloth_r;
    sfVector2f cape_v;
    sfVector2f skin_v;
    sfVector2f hair_v;
    sfVector2f eyes_v;
    sfVector2f cloth_v;
} spriteplayer_t;

typedef struct player_s {
    spriteplayer_t player;
    sfClock *clock;
    sfTime time;
    sprite_t ui;
    sfVector2f tmp_vec;
    sfText *text[2];
    int etat;
    int life;
    int mana;
    int exp;
    int gold;
    float sec;
    int damage;
    char *name;
    sfVector2f pos;
    int bool_quest[15];
    int map_actu;
    int bool_entermaisonmap2;
} player_t;

/*/////////////////////////////////////////|
                 LINK INVENTORY            |
*/////////////////////////////////////////*|

typedef struct item_s {
    char *name;
    char *path;
    sfIntRect rect;
    int gold;
    int dammage;
    char *id;
} item_t;

typedef struct node_s {
    char *name;
    char *path;
    sfIntRect rect;
    int gold;
    int dammage;
    char *id;
    sprite_t sprite;
    int etat;
    struct node_s *next;
} node_t;

typedef struct link_s {
    node_t *head;
} link_t;

typedef struct inventory_s {
    sprite_t inventory;
    link_t *link;
    int etat;
    sfVector2f tmp_vec;
} inventory_t;

/*/////////////////////////////////////////|
                 GAME OBJ AND GAME         |
*/////////////////////////////////////////*|

typedef struct varglobal_s {
    sfVector2f pos_mouse;
    sfVector2f pos_mouse_click;
    sfBool music;
} varglobal_t;

typedef struct pause_s {
    sprite_t button[5];
    sfTexture *tback;
    sfSprite *sback;
    int is_activated;
} pause_t;

/*/////////////////////////////////////////|
                 PRE PLAY                  |
*/////////////////////////////////////////*|

typedef struct preplay_s {
    int etat_slide;
    sfText *modif_hair;
    sfText *modif_skin;
    sfText *modif_cape;
    sfText *modif_cloth;
    sfText *modif_eyes;
    sfText *name_text;
    char *name;
    int index;
    sprite_t btn[2];
    sprite_t button[5];
    sfText *button_text[5];
    sfRectangleShape *panel_color[65];
    sfVector2f panel_pos[65];
    int etat;
    sfSprite *bg;
    sfRectangleShape *cadre[3];
    sfText *text[2];
    int etat_preplay;
    sprite_t button_choice[2];
    sfText *text_choice[2];
    int bool_name;
} preplay_t;

typedef struct my_music_s {
    sfMusic *music;
} my_music_t;

/*/////////////////////////////////////////|
                 MENU AND GAME             |
*/////////////////////////////////////////*|

typedef struct sounds_s {
    sfSound *bought;
    sfSound *hit;
    sfSoundBuffer *buf;
    sfSoundBuffer *buf1;
} sounds_t;

typedef struct my_event_s {
    int is_released;
    sfKeyEvent key;
} my_event_t;

typedef struct background_s {
    my_music_t music;
    my_music_t music2;
    sfTexture **texture;
    sfSprite *sprite;
    sfClock *clock;
    sfTime time;
    float seconds;
    int i;
} background_t;

typedef struct button_s {
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect rect;
    sfText *text;
}button_t;

typedef struct my_dataannim_s {
    int type;
    int id_pnj;
    sfVector2f where;
} my_dataannim_t;

typedef struct my_data_s{
    int key;
    sfText *text;
    char *str;
    sprite_t btn;
    sfSprite *sprite;
    sfClock *clock;
    sfIntRect rect;
    sfVector2f pos;
    int open;
    int state;
    int data_int;
    sfRectangleShape *rectangle;
    sfVector2f dest;
}my_data_t;

typedef struct datafordialg_s {
    char *str;
    sprite_t text;
} datafordialg_t;

typedef struct dataquestactu_s {
    char *name;
    int pourcentage;
    int status;
    struct dataquestactu_s *next;
} dataquestactu_t;

typedef struct my_list_s {
    my_data_t data;
    dataquests_t data_quest;
    datafordialg_t data_dial;
    dataquestactu_t data_actu;
    my_dataannim_t animation;
    my_data_t anim_pop;
    struct my_list_s *next;
} my_list_t;

typedef struct credits_s {
    sfText *text[6];
    button_t button[1];
} credits_t;

typedef struct dialog_s {
    int status_btn2;
    int load_this;
    sprite_t background;
    sprite_t icon_pnj[6];
    sfRectangleShape *btn[3];
    sfText *text_btn[3];
    dataquests_t quest_actu;
    my_list_t *linked_dialog;
} dialog_t;

typedef struct button_clock_s {
    sfClock *clock;
    sfTime time;
    float seconds;
} button_clock_t;

typedef struct menu_s {
    sprite_t background;
    preplay_t preplay;
    sprite_t buttons[4];
    my_list_t *list_save;
    button_clock_t anim_btn;
} menu_t;

typedef struct pause_settings_t {
    button_t button[3];
    sprite_t sprite[3];
    sfIntRect rect[3];
    sfText *volume;
    sfText *settings;
    int index;
    char **vol;
} pause_settings_t;

typedef struct settings_t {
    sprite_t bool_music;
    sprite_t volume_music;
    sprite_t slide_volume;
    sprite_t size_windows;
    sprite_t check_music;
    sprite_t slider_right;
    sprite_t btn_size[4];
    sprite_t go_back;
    int slider_findecourse1;
    int slider_findecourse2;
    int slider_findecousey;
}settings_t;

typedef struct gestclick_s {
    sfClock *clock;
    sfTime time;
    float sec;
    sfText *text_clock;
    sfClock *clock2;
    sfTime time2;
    float sec2;
    sfText *text_clock2;
    sfClock *clock3;
    sfTime time3;
    float sec3;
    sfText *text_clock3;
} gestclick_t;

typedef struct fight_s {
    sprite_t bg_fight;
    sprite_t ennemis;
    int damage;
    int damage_player;
    player_t py;
    sprite_t life[2];
    sprite_t attack[3];
    sprite_t buttonatk[4];
    sprite_t type[3];
    sprite_t attack_ennemis[1];
    sprite_t bg_button[2];
    gestclick_t gest;
    int turn;
    int etat;
    int tmp;
    int atk;
    int win;
    sfText *life_player;
    sfText *warning;
} fight_t;


/*/////////////////////////////////////////|
                 QUEST                     |
*/////////////////////////////////////////*|

typedef struct notif_s {
    int etat;
    sprite_t box;
    sfText *text_notif;
} notif_t;

typedef struct quest_s {
    int etat;
    int etat_event;
    sfRectangleShape *info;
    sfText *quest[5];
    my_list_t *all_quest;
    my_list_t *quest_actu;
    my_list_t *animation_on;
    my_list_t *chest_list;
    sprite_t *pnj_quest;
    sfText *info_pnj;
    int can_pressenter;
    int id_select;
    int press_enter;
    notif_t notif;
    sfText *notif_chest;
    sfText *first_quest;
}quest_t;

typedef struct intro_s {
    sprite_t bg;
    sfText *press_skip;
} intro_t;

/*/////////////////////////////////////////|
                 SHOP                      |
*/////////////////////////////////////////*|

typedef struct shop_info_s {
    int etat;
    int index;
} shop_info_t;

typedef struct shop_s {
    sprite_t shop;
    sprite_t hud;
    sprite_t gold;
    sprite_t pnj[5];
    sfText *text[2];
    shop_info_t info[2];
    sfText *infos[4];
    sprite_t information;
} shop_t;

typedef struct obj_s {
    menu_t menu;
    fight_t fight;
    settings_t settings;
    quest_t quest;
    sfMusic *click;
    sprite_t map[3];
    inventory_t invt;
    dialog_t dialog;
    link_t *item;
    intro_t intro;
    sprite_t mini_map_wood;
    int status_minimap;
    my_list_t *anim;
    sprite_t mob[5];
} obj_t;

typedef struct map_s {
    char **map_q1;
    char **map;
    int etat_map;
    int x;
    int y;
    float coef_x;
    float coef_y;
} map_t;

typedef struct win_screen_s {
    sprite_t sprite[1];
    button_t button[1];
    sfText *text;
} win_screen_t;

typedef struct loose_screen_s {
    sprite_t sprite[1];
    button_t button[1];
    sfText *text;
} loose_screen_t;

typedef struct waiting_s {
    sprite_t sprite[3];
    sfText *loading;
} waiting_t;

typedef struct htp_s {
    button_t button[1];
    sfText *text[7];
} htp_t;

typedef struct transitions_s {
    my_list_t *list;
    sfClock *bigclock;
    sprite_t bulle_dialog[6];
    sprite_t *portefightl;
    sprite_t *portefightr;
} transitions_t;

typedef struct particle_s
{
    sfVector2f pos;
    sfVector2f vel;
    sfColor color;
    size_t radius;
    int living;
} particle_t;

typedef struct particle_environment_s
{
    float angle_min;
    float angle_max;
    float speed;
    sfVector2f gravity;
    sfUint8 alpha;
    sfClock *clock;
    sfCircleShape *circle_shape;
} particle_environment_t;

typedef struct screen_s {
    sfRenderWindow *window;
    sfEvent event;
    sfKeyCode key;
    particle_t particle[PARTICLE_MAX];
    particle_environment_t particle_environment;
} screen_t;

typedef struct game_s {
    window_t window;
    varglobal_t var;
    obj_t obj;
    background_t background;
    game_e etat;
    player_t player;
    pause_t pause;
    pause_settings_t pause_s;
    my_event_t my_event;
    map_t map;
    credits_t credit;
    shop_t shop;
    sounds_t sounds;
    waiting_t waiting;
    transitions_t transi;
    htp_t htp;
    int allow_event;
    win_screen_t win_screen;
    loose_screen_t loose_screen;
    sfVector2f save_pos;
    int win;
    screen_t screen;
} game_t;

#endif /* !STRUCT_H_ */