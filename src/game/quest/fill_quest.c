/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** fill_quest.c
*/

#include "rpg.h"

dataquests_t parse_linequest(char *line_actu)
{
    dataquests_t new_data;
    sfVector2f pos;

    new_data.id = get_idq(line_actu);
    new_data.lvl_min  = get_lvlmin(line_actu);
    new_data.xp_win = get_xpwin(line_actu);
    new_data.objectwin = get_objectwin(line_actu);
    new_data.dialog_1 = get_dialog(line_actu, 0);
    new_data.dialog_2 = get_dialog(line_actu, 1);
    new_data.icon = get_iconiddialog(line_actu);
    new_data.name = get_namedialog(line_actu);
    pos = get_posquest(line_actu);
    new_data.x = pos.x;
    new_data.y = pos.y;
    new_data.accept = FALSE;
    new_data.rendu = FALSE;
    new_data.init_beginquest = FALSE;
    return (new_data);
}

int getmapid(char *str)
{
    int sp = 0;
    char *new_str = malloc(sizeof(char) * 100);
    int j = 0;
    int i = 0;

    for (i = 0; str[i] && sp != 10; i++) {
        if (str[i] == ':')
            sp++;
    }
    while (str[i] && str[i] != ':')
        new_str[j++] = str[i++];
    return (my_getnbr(new_str));
}

void fill_quest(game_t *g, int map)
{
    int fd = open(PATHQUEST, O_RDONLY);
    char *line_actu = NULL;

    get_next_line(fd);
    get_next_line(fd);
    while ((line_actu = get_next_line(fd))) {
        get_next_line(fd);
        if (getmapid(line_actu) == map)
            add_quests(&g->obj.quest.all_quest, parse_linequest(line_actu));
        free(line_actu);
    }
    free(line_actu);
}

void destroy_quest(game_t *g)
{
    my_list_t *tmp = g->obj.quest.all_quest;
    my_list_t *tmp1 = NULL;

    while (tmp) {
        tmp1 = tmp;
        tmp = tmp->next;
        free(tmp1);
    }
    g->obj.quest.all_quest = NULL;
}