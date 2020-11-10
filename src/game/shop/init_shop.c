/*
** EPITECH PROJECT, 2020
** init_shop.c
** File description:
** init_shop.c
*/

#include "rpg.h"

void init_shop_sprite(sfVector2f vec, sfIntRect rect, sprite_t *sprite)
{
    sprite->texture = sfTexture_createFromFile("./assets/pnj/pnj1.png", NULL);
    sprite->sprite = sfSprite_create();
    sprite->vector = vec;
    sprite->rect = rect;
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    sfSprite_setPosition(sprite->sprite, sprite->vector);
}

void init_scene_shop(sfVector2f vec, sprite_t *sprite, char *path, \
sfVector2f scale)
{
    sprite->texture = sfTexture_createFromFile(path, NULL);
    sprite->sprite = sfSprite_create();
    sprite->vector = vec;
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
    sfSprite_setPosition(sprite->sprite, sprite->vector);
    sfSprite_setScale(sprite->sprite, scale);
}

static void init_text(game_t *game)
{
    char *text1 = "";
    char *text3 = "Informations";
    sfVector2f pos[5];

    pos[0] = (sfVector2f){900, 840};
    pos[1] = (sfVector2f){900, 885};
    pos[2] = (sfVector2f){getpourcentage_x(game, 50), 900};
    pos[3] = (sfVector2f){getpourcentage_x(game, 50) - 70, 782};
    pos[4] = (sfVector2f){900, 920};

    game->shop.infos[0] = create_text(ffont, text1, pos[0].x, pos[0].y);
    game->shop.infos[1] = create_text(ffont, text1, pos[1].x, pos[1].y);
    game->shop.infos[2] = create_text(ffont, text3, pos[3].x, pos[3].y);
    game->shop.infos[3] = create_text(ffont, text1, pos[4].x, pos[4].y);
    game->shop.information.sprite = create_sprite("./assets/shop/tfou.png");
    sfSprite_setOrigin(game->shop.information.sprite, (sfVector2f){200, 131.5});
    sfSprite_setPosition(game->shop.information.sprite, pos[2]);
}

void init_shop(game_t *g)
{
    init_item_sprite(&g->shop.gold, "./assets/ui.png", \
    (sfIntRect){95, 0, 250, 38});
    sfSprite_setPosition(g->shop.gold.sprite, (sfVector2f){1600, 100});
    sfSprite_setScale(g->shop.gold.sprite, (sfVector2f){1.5, 1.5});
    init_shop_sprite(init_vector(1000, 562), initrect(163-32, 16*4, 16, 32), \
    &g->shop.pnj[0]);
    init_text(g);
    init_shop_sprite(init_vector(1000, 562), initrect(163-32, 16*4, 16, 32), \
    &g->shop.pnj[0]);
    sfSprite_setScale(g->shop.pnj[0].sprite, (sfVector2f){2, 2});
    g->shop.text[0] = create_text(PATH_FONT, STR_SHOP_ENTER, -1000, -1000);
    init_scene_shop((sfVector2f){0, 0}, &g->shop.shop, PT_SHOP, \
    (sfVector2f){1, 1});
    init_scene_shop((sfVector2f){100, 50}, &g->shop.hud, HUD_SHOP, \
    (sfVector2f){2, 2});
    change_scale_item(g);
    place_item_shop(g);
}