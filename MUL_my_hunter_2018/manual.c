/*
** EPITECH PROJECT, 2018
** manual.c
** File description:
** game help option
*/

#include "include/hunter.h"

char *my_put_scr(int nb)
{
    char *str = malloc(sizeof(char) * 13);
    int tmp;
    int i = -1;

    for (int compt =  nb; compt >= 1; i++)
        compt = compt / 10;
    tmp = i;
    while (nb >= 1) {
        str[i] = nb % 10 + 48;
        nb = nb / 10;
        i--;
    }
    str[tmp + 1] = '\0';
    if (str[0] == '\0') {
        str[0] = '0';
        str[1] = '\0';
    }
    return (str);
}

void display_man(void)
{
    my_printf("\nmyHunter game manual\n\n");
    my_printf("USAGE\n");
    my_printf("./my_hunter without option to launch game\n\n");
    my_printf("DESCRIPTION\n");
    my_printf("The goal of the game is to survive as much as possible\n");
    my_printf("by killing crawls.\nEach killed crawl give one point\n");
    my_printf("Do not let them pass the screen or you'll loose one life.\n");
    my_printf("Loose 4 life and it's game over, good luck !\n\n");
}