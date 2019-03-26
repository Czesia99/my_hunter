/*
** EPITECH PROJECT, 2018
** display_window.c
** File description:
** display window functions
*/

#include "include/hunter.h"

void display_window(sfRenderWindow *window, objects_t *objs, birds_t *birds, \
Clock_t *Clocks)
{
    set_background(window, objs);
    bird_spawn(birds, Clocks);
    bird_animation(birds, Clocks, window);
    display_objects(window, objs, birds);
    sfRenderWindow_display(window);
    sfRenderWindow_clear(window, sfBlack);
}