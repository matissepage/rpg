/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** parse_dialog.c
*/

#include "rpg.h"

void add_nodedialog(my_list_t **list, datafordialg_t data)
{
    my_list_t *elem = malloc(sizeof(my_list_t));
    my_list_t *tmp = *list;

    elem->data_dial = data;
    elem->next = NULL;
    if (!(*list)) {
        *list = elem;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = elem;
}

datafordialg_t init_datadialoge(char *str)
{
    datafordialg_t new_data;

    new_data.str = malloc(sizeof(char) * (my_strlen(str) + 1));
    new_data.str = my_strcpy(new_data.str, str);
    new_data.text.text = create_text(PATH_FONT, str, 750, 250);

    return (new_data);
}

void get_parsedialoglinkedlist(game_t *g)
{
    char *str = malloc(sizeof(char) * 200);
    int j = 0;

    for (int i = 0; BUILD_DIALOG.quest_actu.dialog_1[i]; i++) {
        if (BUILD_DIALOG.quest_actu.dialog_1[i] == '&') {
            str[j] = '\0';
            add_nodedialog(&BUILD_DIALOG.linked_dialog, init_datadialoge(str));
            j = 0;
            free(str);
            str = malloc(sizeof(char) * 200);
        } else if (BUILD_DIALOG.quest_actu.dialog_1[i] != '"')
            str[j++] = BUILD_DIALOG.quest_actu.dialog_1[i];
    }
    str[j] = '\0';
    add_nodedialog(&BUILD_DIALOG.linked_dialog, init_datadialoge(str));
    free(str);
}

void get_parsedialoglinkedlistend(game_t *g)
{
    char *str = malloc(sizeof(char) * 200);
    int j = 0;

    for (int i = 0; BUILD_DIALOG.quest_actu.dialog_2[i]; i++) {
        if (BUILD_DIALOG.quest_actu.dialog_2[i] == '&') {
            str[j] = '\0';
            add_nodedialog(&BUILD_DIALOG.linked_dialog, init_datadialoge(str));
            j = 0;
            free(str);
            str = malloc(sizeof(char) * 200);
        } else if (BUILD_DIALOG.quest_actu.dialog_2[i] != '"')
            str[j++] = BUILD_DIALOG.quest_actu.dialog_2[i];
    }
    str[j] = '\0';
    add_nodedialog(&BUILD_DIALOG.linked_dialog, init_datadialoge(str));
    free(str);
}