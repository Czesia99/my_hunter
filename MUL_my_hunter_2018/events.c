/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** duck hunt events analyse
*/

#include "include/hunter.h"

void close_window(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(window);
}

void analyse_shot(sfRenderWindow *window, sfEvent event, birds_t *birds, \
objects_t *objs)
{
    sfVector2i vector = sfMouse_getPositionRenderWindow(window);

    for (int i = 0; i <= birds->count; i++) {
        if ((event.type == sfEvtMouseButtonPressed) && \
        ((vector.x >= birds->bird[i].vect.x && \
        vector.x <= birds->bird[i].vect.x + 170)\
        && (vector.y >= birds->bird[i].vect.y && \
        vector.y <= birds->bird[i].vect.y + 170))) {
            birds->bird[i].vect.x = (rand() % (-200) + 1) + -400;
            birds->bird[i].vect.y = (rand() % (400) + 1) + 50;
            objs->scr->score += 1;
            sfSprite_setPosition(birds->bird[i].sprite, \
            birds->bird[i].vect);
        }
    }
}

void analyse_events(sfRenderWindow *window, sfEvent event, birds_t *birds, \
objects_t *objs)
{
    close_window(window, event);
    analyse_shot(window, event, birds, objs);
}
