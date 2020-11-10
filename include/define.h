/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** define.h
*/

#ifndef DEFINE_GENE_H
#define DEFINE_GENE_H

#include "rpg.h"
#include "struct.h"
#define SSTR(A, B) sfSprite_setTextureRect(A, B)
#define ffont "assets/fonts/font1.ttf"
/* CONSTANTE VALUE */

#define PATH_MOB "./assets/mob/mob.png"
#define MAP_1 "./map/map_quest1.png"
#define MAP_2 "./assets/map_rpg_lvl1.png"
#define MAP2TXT "./map/map2.txt"
#define MAP_3 "./map/map2.png"
#define MAP4TXT "./map/map3.txt"
#define MAP_4 "./map/map3.png"
#define MAP5TXT "./map/map4.txt"
#define MAP_5 "./map/map4.png"
#define MAP6TXT "./map/map5.txt"
#define MAP_6 "./map/map5.png"

#define CIN_TRANSITION 9856
#define SHEET "./assets/menu/spritesheet.png"
#define PATH_CAPE "./assets/player/hero_cape.png"
#define PATH_CLOTH "./assets/player/hero.png"
#define PATH_EYES "./assets/player/hero_eyes.png"
#define PATH_SKIN "./assets/player/hero_skin.png"
#define PATH_HAIR "./assets/player/hero_hair.png"
#define PATH_BUTTON "./assets/menu/buttons.png"
#define PATH_FONT "./assets/fonts/Pacifico.ttf"
#define PATH_BACKGROUNDDIALOG "./assets/pnj/bg_dialog.png"
#define PATHQUEST "./save/quests/quest.txt"
#define PATH_ICONDIALOG "./assets/pnj/spritesheet_portrait.png"
#define PATH_WOOD "./assets/texture_bois.png"
#define PATH_BGINTRO "./assets/frame1.png"
#define PATH_POPUP "./assets/zone.png"
#define PATH_CHEST "./assets/chest.png"
#define PT_SHOP "./assets/shop/shop1.png"
#define HUD_SHOP "./assets/shop/shop.png"
#define MOB_F "./assets/mob/mob_f.png"

#define MESSAGE_USERNAME "Click here to enter a Username"
#define STR_N_CHAR "New Character"
#define STR_L_CHAR "Load Character"
#define STR_MSG_PNJ "Press [SPACE]"
#define STR_ONBTN "Modife Color"
#define MESSAGE_SKIP "Press [SPACE] For skip"

#define INV g->obj.invt.link
#define STR_SHOP_ENTER "Press N for open Shop"
#define NONE "NONE"
#define POSITION_START "840:375\n"
#define VALUE_NOINIT 9999
#define TRUE 1
#define FALSE 0
#define RANGE_QUEST 75
#define MARRON sfColor_fromRGBA(91, 60, 17, 155)

#define RSC(A, B) sfRectangleShape_setFillColor(A, B)
#define STR(A, B) sfSprite_setTextureRect(A, B)
#define SP(A, C) sfSprite_setPosition(A, C)
#define G(A) sfSprite_getPosition(A)
#define C(A, B, C, D) create_text(A, B, C, D)

#define D(A, B, C) sfRenderWindow_drawSprite(A, B, C)

#define player_ game->player.player
#define BUILD_PREPLAY g->obj.menu.preplay
#define BUILD_QUEST g->obj.quest
#define BUILD_DIALOG g->obj.dialog
#define BUILD_INTRO g->obj.intro

#define W g->window.window
#define W_g game->window.window

#define M g->var.pos_mouse_click

#define T(A, B, C) sfRenderWindow_drawText(A, B, C)
#define R(A, B, C) sfRenderWindow_drawRectangleShape(A, B, C)
#define RGF(A) sfRectangleShape_getFillColor(A)
#define RGP(A) sfRectangleShape_getPosition(A)
#define R(A, B, C) sfRenderWindow_drawRectangleShape(A, B, C)
#define btn_anim game->obj.menu.anim_btn

#define g_x(A) getpourcentage_x(game, A)
#define g_y(A) getpourcentage_y(game, A)

#define SRWDS(A, B, C) sfRenderWindow_drawSprite(A, B, C)
#define SFTR(A, B) sfSprite_setTextureRect(A, B)
#define SFSP(A, B) sfSprite_setPosition(A, B)
#define SFSS(A, B) sfSprite_setScale(A, B)
#define W g->window.window
#define STCFF(A, B) sfTexture_createFromFile(A, B)
#define SSST(A, B, C) sfSprite_setTexture(A, B, C)
#define bstruct game->background
#define btn_s game->obj.menu.buttons[i].sprite
#define btn_r game->obj.menu.buttons[i].rect
#define player_ game->player.player
#define bkg g->obj.menu
#define BUILD g->obj.settings
#define s_pos(A, B) sfSprite_setPosition(A, B)
#define r_set(A, B) sfSprite_setTextureRect(A, B)
#define f_x(B) getpourcentage_x(g, B)
#define f_y(B) getpourcentage_x(g, B)
#define g_pos(A) sfSprite_getPosition(A)
#define btn_ss g->obj.settings.go_back.sprite
#define btn_rr g->obj.settings.go_back.rect
#define BBUILD g->obj.quest.pnj_quest
#define p game->credit.button[0]
#define ffontt "assets/fonts/font1.ttf"
#define A(A, B) sfRectangleShape_setFillColor(A, B)
#define I(A, B) init_vector(A, B)
#define SCGET(A) sfClock_getElapsedTime(A)
#define CONVERT game->obj.fight.gest.time.microseconds
#define SRWDT(A, B, C) sfRenderWindow_drawText(A, B, C);
#define PARTICLE_ANGLE_MIN (0)
#define PARTICLE_ANGLE_MAX (M_PI * 4)
#define GRAVITY_X (1.0f * 0)
#define GRAVITY_Y (1.0f * 0)
#define ALPHA (1)
#define PARTICLE_MAX (100)
#define SPEED (2.0f)

#endif