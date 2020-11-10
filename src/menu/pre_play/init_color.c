/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_color.c
*/

#include "rpg.h"

void init_color3(game_t *g)
{
    RSC(g->obj.menu.preplay.panel_color[55], sfColor_fromRGB(121, 28, 248));
    RSC(g->obj.menu.preplay.panel_color[56], sfColor_fromRGB(218, 112, 214));
    RSC(g->obj.menu.preplay.panel_color[57], sfColor_fromRGB(102, 0, 255));
    RSC(g->obj.menu.preplay.panel_color[58], sfColor_fromRGB(18, 13, 22));
    RSC(g->obj.menu.preplay.panel_color[59], sfColor_fromRGB(63, 34, 4));
    RSC(g->obj.menu.preplay.panel_color[60], sfColor_fromRGB(45, 36, 30));
    RSC(g->obj.menu.preplay.panel_color[61], sfColor_fromRGB(199, 207, 0));
    RSC(g->obj.menu.preplay.panel_color[62], sfColor_fromRGB(173, 79, 9));
    RSC(g->obj.menu.preplay.panel_color[63], sfColor_fromRGB(255, 255, 0));
    RSC(g->obj.menu.preplay.panel_color[64], sfColor_fromRGB(237, 237, 237));
    g->player.player.id_eyes = VALUE_NOINIT;
    g->player.player.id_skin = VALUE_NOINIT;
    g->player.player.id_hair = VALUE_NOINIT;
    g->player.player.id_cape = VALUE_NOINIT;
    g->player.player.id_cloth = VALUE_NOINIT;
}

void init_color21(game_t *g)
{
    RSC(g->obj.menu.preplay.panel_color[47], sfColor_fromRGB(252, 93, 93));
    RSC(g->obj.menu.preplay.panel_color[48], sfColor_fromRGB(107, 13, 13));
    RSC(g->obj.menu.preplay.panel_color[49], sfColor_fromRGB(238, 16, 16));
    RSC(g->obj.menu.preplay.panel_color[50], sfColor_fromRGB(108, 2, 119));
    RSC(g->obj.menu.preplay.panel_color[51], sfColor_fromRGB(0, 255, 0));
    RSC(g->obj.menu.preplay.panel_color[52], sfColor_fromRGB(127, 221, 76));
    RSC(g->obj.menu.preplay.panel_color[53], sfColor_fromRGB(194, 247, 50));
    RSC(g->obj.menu.preplay.panel_color[54], sfColor_fromRGB(24, 57, 30));
}

void init_color2(game_t *g)
{
    RSC(g->obj.menu.preplay.panel_color[35], sfColor_fromRGB(253, 108, 158));
    RSC(g->obj.menu.preplay.panel_color[36], sfColor_fromRGB(255, 228, 196));
    RSC(g->obj.menu.preplay.panel_color[37], sfColor_fromRGB(222, 49, 99));
    RSC(g->obj.menu.preplay.panel_color[38], sfColor_fromRGB(254, 195, 172));
    RSC(g->obj.menu.preplay.panel_color[39], sfColor_fromRGB(253, 233, 224));
    RSC(g->obj.menu.preplay.panel_color[40], sfColor_fromRGB(199, 44, 72));
    RSC(g->obj.menu.preplay.panel_color[41], sfColor_fromRGB(223, 115, 255));
    RSC(g->obj.menu.preplay.panel_color[42], sfColor_fromRGB(248, 142, 85));
    RSC(g->obj.menu.preplay.panel_color[43], sfColor_fromRGB(255, 0, 127));
    RSC(g->obj.menu.preplay.panel_color[44], sfColor_fromRGB(145, 40, 59));
    RSC(g->obj.menu.preplay.panel_color[45], sfColor_fromRGB(237, 0, 0));
    RSC(g->obj.menu.preplay.panel_color[46], sfColor_fromRGB(255, 0, 255));
    init_color21(g);
    init_color3(g);
}

void init_color(game_t *g)
{
    RSC(g->obj.menu.preplay.panel_color[16], sfColor_fromRGB(240, 195, 0));
    RSC(g->obj.menu.preplay.panel_color[17], sfColor_fromRGB(157, 62, 12));
    RSC(g->obj.menu.preplay.panel_color[18], sfColor_fromRGB(139, 108, 66));
    RSC(g->obj.menu.preplay.panel_color[19], sfColor_fromRGB(245, 245, 220));
    RSC(g->obj.menu.preplay.panel_color[20], sfColor_fromRGB(61, 43, 31));
    RSC(g->obj.menu.preplay.panel_color[21], sfColor_fromRGB(223, 109, 20));
    RSC(g->obj.menu.preplay.panel_color[22], sfColor_fromRGB(159, 85, 30));
    RSC(g->obj.menu.preplay.panel_color[23], sfColor_fromRGB(131, 166, 151));
    RSC(g->obj.menu.preplay.panel_color[24], sfColor_fromRGB(187, 210, 225));
    RSC(g->obj.menu.preplay.panel_color[25], sfColor_fromRGB(193, 191, 177));
    RSC(g->obj.menu.preplay.panel_color[26], sfColor_fromRGB(153, 122, 144));
    RSC(g->obj.menu.preplay.panel_color[27], sfColor_fromRGB(255, 255, 0));
    RSC(g->obj.menu.preplay.panel_color[28], sfColor_fromRGB(240, 195, 0));
    RSC(g->obj.menu.preplay.panel_color[29], sfColor_fromRGB(173, 79, 9));
    RSC(g->obj.menu.preplay.panel_color[30], sfColor_fromRGB(128, 128, 0));
    RSC(g->obj.menu.preplay.panel_color[31], sfColor_fromRGB(165, 38, 10));
    RSC(g->obj.menu.preplay.panel_color[32], sfColor_fromRGB(174, 74, 52));
    RSC(g->obj.menu.preplay.panel_color[33], sfColor_fromRGB(146, 109, 39));
    RSC(g->obj.menu.preplay.panel_color[34], sfColor_fromRGB(225, 206, 154));
    init_color2(g);
}