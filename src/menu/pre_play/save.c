/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** save.c
*/

#include "rpg.h"

int recup_nbr(char *str)
{
    int	nb = 0;
    int	isneg = 1;
    int	i = 0;

    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-')
            isneg = isneg * -1;
        i = i + 1;
    }
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            nb = nb * 10;
            nb = nb + str[i] - '0';
        }
        i++;
    }
    return (nb * isneg);
}

void parse_colorpre(game_t *g, char *path)
{
    int nbr[5];
    char *buff = malloc(sizeof(char) * 100);
    int fd = open(path, O_RDONLY);
    int i = 0;

    g->player.map_actu = my_getnbr(get_next_line(fd));
    g->player.life = my_getnbr(get_next_line(fd));
    g->player.gold = my_getnbr(get_next_line(fd));
    load_positionplayer(g, get_next_line(fd));
    while ((buff = get_next_line(fd)) != NULL) {
        nbr[i] = recup_nbr(buff);
        i++;
    }
    close(fd);
    load_saverecolor(g, nbr);
}

char *clean_buffer(char *str)
{
    int i = 0;
    int j = 0;
    char *dest = malloc(sizeof(char) * my_strlen(str) + 1);

    for (; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            dest[j] = str[i];
            j++;
        }
    }
    dest[j] = '\0';
    return (my_strlowcase(dest));
}

char *create_profilestr(game_t *g, sfVector2f pos)
{
    char *name = malloc(sizeof(char) * 10000);
    name = my_strcpy(name, my_itc(g->player.map_actu));
    name = my_strcat(name, "\n");
    name = my_strcat(name, my_itc(g->player.life));
    name = my_strcat(name, "\n");
    name = my_strcat(name, my_itc(g->player.gold));
    name = my_strcat(name, "\n");
    name = my_strcat(name, create_myposjoueur(pos));
    name = my_strcat(name, "EYES:");
    name = my_strcat(name, my_itc(g->player.player.id_eyes));
    name = my_strcat(name, "\n");
    name = my_strcat(name, "SKIN:");
    name = my_strcat(name, my_itc(g->player.player.id_skin));
    name = my_strcat(name, "\n");
    name = my_strcat(name, "HAIR:");
    name = my_strcat(name, my_itc(g->player.player.id_hair));
    name = my_strcat(name, "\n");
    name = my_strcat(name, "CAPE:");
    name = my_strcat(name, my_itc(g->player.player.id_cape));
    name = my_strcat(name, "\n");
    name = my_strcat(name, "CLOTH:");
    name = my_strcat(name, my_itc(g->player.player.id_cloth));
    name = my_strcat(name, "\n");
    return (name);
}

void save_myprofile(game_t *g, sfVector2f pos)
{
    int fp;
    char *str = create_profilestr(g, pos);
    char *name = malloc(sizeof(char) * 100);
    g->obj.menu.preplay.name = clean_buffer(g->obj.menu.preplay.name);
    name[0] = '.';
    name[1] = '/';
    name[2] = 's';
    name[3] = 'a';
    name[4] = 'v';
    name[5] = 'e';
    name[6] = '/';
    name[7] = '\0';
    name = my_strcat(name, "character/");
    name = my_strcat(name, g->obj.menu.preplay.name);
    name = my_strcat(name, ".txt");
    fp = open(name, O_WRONLY | O_CREAT, 0666);
    write (fp, str, my_strlen(str));
}