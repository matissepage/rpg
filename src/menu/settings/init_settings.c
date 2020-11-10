/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_settings.c
*/

#include "rpg.h"

void init_settext(game_t *g)
{
    char *font = "./assets/fonts/Pacifico.ttf";

    BUILD.bool_music.text = create_text(font, "Music : On", f_x(22), f_y(11));
    BUILD.volume_music.text = create_text(font, "Change Volume", f_x(47), \
    f_y(11));
    BUILD.slide_volume.text = create_text(font, "", f_x(45), f_y(11));
    BUILD.size_windows.text = create_text(font, "Change Resolution", f_x(30), \
    f_y(10));
    BUILD.go_back.text = create_text(font, "Go Home", f_x(72), f_y(52));
    BUILD.btn_size[0].text = create_text(font, "1280x800", f_x(30), f_y(31));
    BUILD.btn_size[1].text = create_text(font, "1920x1080", f_x(30), f_y(36));
    BUILD.btn_size[2].text = create_text(font, "1920x1200", f_x(30), f_y(41));
    BUILD.btn_size[3].text = create_text(font, "800x600", f_x(30), f_y(46));
}

void initrectpos(game_t *g)
{
    BUILD.check_music.rect = initrect(0, 0, 21, 20);
    BUILD.slider_right.rect = initrect(0, 42, 39, 31);
    r_set(BUILD.bool_music.sprite, initrect(0, 0, 340, 88));
    r_set(BUILD.volume_music.sprite, initrect(0, 0, 340, 88));
    r_set(BUILD.slide_volume.sprite, initrect(0, 0, 340, 88));
    r_set(BUILD.size_windows.sprite, initrect(0, 0, 340, 88));
    r_set(BUILD.go_back.sprite, initrect(0, 0, 340, 88));
    for (int i = 0; i < 4; i++)
        r_set(BUILD.btn_size[i].sprite, initrect(0, 0, 340, 88));
    r_set(BUILD.check_music.sprite, BUILD.check_music.rect);
    r_set(BUILD.slider_right.sprite, BUILD.slider_right.rect);
    sfSprite_setScale(BUILD.check_music.sprite, init_vector(2, 2));
}

void initpossettigns(game_t *g)
{
    BUILD.slider_findecourse1 = f_x(65);
    BUILD.slider_findecourse2 = f_x(65) + 300;
    BUILD.slider_findecousey = ((f_y(10) + f_y(10) + 88) / 2) - 15;
    BUILD.slider_right.vector = init_vector(f_x(65), f_y(11));
    s_pos(BUILD.bool_music.sprite, init_vector(f_x(20), f_y(10)));
    s_pos(BUILD.volume_music.sprite, init_vector(f_x(45), f_y(10)));
    s_pos(BUILD.slide_volume.sprite, init_vector(f_x(65), f_y(10)));
    s_pos(BUILD.size_windows.sprite, init_vector(f_x(20), f_y(30)));
    s_pos(BUILD.btn_size[0].sprite, init_vector(f_x(20), f_y(30)));
    s_pos(BUILD.btn_size[1].sprite, init_vector(f_x(20), f_y(35)));
    s_pos(BUILD.btn_size[2].sprite, init_vector(f_x(20), f_y(40)));
    s_pos(BUILD.btn_size[3].sprite, init_vector(f_x(20), f_y(45)));
    s_pos(BUILD.check_music.sprite, init_vector(f_x(32), f_y(11)));
    s_pos(BUILD.go_back.sprite, init_vector(f_x(70), f_y(50)));
    s_pos(BUILD.slider_right.sprite, BUILD.slider_right.vector);
}

void init_settingssprite(game_t *g)
{
    char *btn = "./assets/menu/buttons.png";
    char *sheet = "./assets/menu/spritesheet.png";

    BUILD.bool_music.sprite = create_sprite(btn);
    BUILD.volume_music.sprite = create_sprite(btn);
    BUILD.slide_volume.sprite = create_sprite(btn);
    BUILD.size_windows.sprite = create_sprite(btn);
    for (int i = 0; i < 4; i++)
        BUILD.btn_size[i].sprite = create_sprite(btn);
    BUILD.check_music.sprite = create_sprite(sheet);
    BUILD.slider_right.sprite = create_sprite(sheet);
    BUILD.go_back.sprite = create_sprite(btn);
}

void init_settings(game_t *g)
{
    init_settingssprite(g);
    initpossettigns(g);
    initrectpos(g);
    init_settext(g);
    g->var.music = sfTrue;
}