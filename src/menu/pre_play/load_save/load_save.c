/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** load_save.c
*/

#include "rpg.h"

my_data_t create_data(sfVector2f pos, char *name)
{
    my_data_t data;
    char *font = "./assets/fonts/Pacifico.ttf";
    data.btn.sprite = create_sprite("./assets/menu/buttons.png");
    sfSprite_setPosition(data.btn.sprite, pos);
    data.text = create_text(font, name, pos.x + 20, pos.y + 20);
    sfSprite_setTextureRect(data.btn.sprite, initrect(0, 0, 344, 88));
    data.str = malloc(sizeof(char) * 100);
    data.str = my_strcpy(data.str, name);

    return (data);
}

void add_node(my_list_t **list, my_data_t data)
{
    my_list_t *elem = malloc(sizeof(my_list_t));
    my_list_t *tmp = *list;

    elem->data = data;
    elem->next = NULL;

    if (!(*list)) {
        *list = elem;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = elem;
}

void find_savegpre(game_t *g)
{
    DIR *s = opendir("./save/character/");
    struct dirent *dir;
    sfVector2f pos;
    pos.x = getpourcentage_x(g, 10);
    pos.y = getpourcentage_y(g, 10);

    while ((dir = readdir(s))) {
        if (dir->d_name[0] != '.') {
            add_node(&g->obj.menu.list_save, create_data(pos, dir->d_name));
            pos.y = pos.y + getpourcentage_y(g, 20);
        }
    }
}

char *remove_txttostr(char *str)
{
    char *new_str = malloc(sizeof(char) * 200);
    int i = 0;

    for (; str[i] && str[i] != '.'; i++)
        new_str[i] = str[i];
    new_str[i] = '\0';
    return (new_str);
}

void save_filepre(game_t *g)
{
    my_list_t *tmp = g->obj.menu.list_save;
    sfVector2f m = g->var.pos_mouse_click;
    int i = 0;

    sfRenderWindow_drawSprite(W, BUILD_PREPLAY.bg, NULL);
    while (tmp) {
        sfRenderWindow_drawSprite(W, tmp->data.btn.sprite, NULL);
        sfRenderWindow_drawText(W, tmp->data.text, NULL);
        i++;
        if (test_hitbox(m, G(tmp->data.btn.sprite), 344, 88) == 1) {
            char *test = malloc(sizeof(char) * 100);
            test = my_strcpy(test, "./save/character/");
            parse_colorpre(g, my_strcat(test, tmp->data.str));
            g->obj.menu.preplay.name = remove_txttostr(
                (char *)sfText_getString(tmp->data.text));
        }
        tmp = tmp->next;
    }
    if (i == 0)
        g->obj.menu.preplay.etat_preplay = 1;
}