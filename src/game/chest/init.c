/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init.c
*/

#include "rpg.h"

char *get_strintxt(char *str, int sp)
{
    int i = 0;
    int sp_local = 0;
    int j = 0;
    char *new_buff = malloc(sizeof(char) * 200);

    for (; str[i] && sp_local < sp; i++)
        if (str[i] == ' ')
            sp_local++;
    while (str[i] && str[i] != ' ')
        new_buff[j++] = str[i++];
    new_buff[j] = '\0';
    return (new_buff);
}

void import_chestmore(game_t *g, char *str)
{
    int money = my_getnbr(get_strintxt(str, 4));
    char *object = get_strintxt(str, 5);
    sfVector2f pos;
    pos.x = (float)my_getnbr(get_strintxt(str, 2));
    pos.y = (float)my_getnbr(get_strintxt(str, 3));
    add_chest(&g->obj.quest.chest_list, create_datachest(money, object, pos));
}

void import_chest(game_t *g, int map)
{
    int fd = open("./save/chest/info.txt", O_RDONLY);
    char *buff = malloc(sizeof(char) * 400);
    char *new_buff = malloc(sizeof(char) * 100);
    int j = 0;

    get_next_line(fd);
    get_next_line(fd);
    while ((buff = get_next_line(fd))) {
        for (int i = 0; buff[i] != ' ' && buff[i]; i++) {
            new_buff[j++] = buff[i];
            new_buff[j] = '\0';
        }
        if (my_getnbr(new_buff) == map) {
            import_chestmore(g, buff);
        }
        j = 0;
        new_buff = malloc(sizeof(char) * 100);
        buff = malloc(sizeof(char) * 400);
    }
}

void destroy_chest(game_t *g)
{
    my_list_t *tmp = g->obj.quest.chest_list;
    my_list_t *tmp1 = NULL;

    while (tmp) {
        tmp1 = tmp;
        tmp = tmp->next;
        free(tmp1);
    }
    g->obj.quest.chest_list = NULL;
}

void init_chest(game_t *g)
{
    g->obj.quest.chest_list = NULL;
    import_chest(g, 1);
    g->obj.quest.notif_chest = create_text(PATH_FONT,
    "Press [N] For open chest", -100, -100);
}