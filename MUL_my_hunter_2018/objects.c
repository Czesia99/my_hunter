/*
** EPITECH PROJECT, 2018
** weapon.c
** File description:
** weapon + sight
*/

#include "include/hunter.h"

void set_sight(sfRenderWindow *window, objects_t *objs)
{
    sfVector2i vector = sfMouse_getPositionRenderWindow(window);
    sfVector2f vect;
    vect.x = vector.x - 32;
    vect.y = vector.y - 32;
    objs->sight->vect = vect;
    sfSprite_setPosition(objs->sight->sprite, objs->sight->vect);
    sfRenderWindow_drawSprite(window, objs->sight->sprite, NULL);
    sfRenderWindow_setMouseCursorVisible(window, 0);
}

void set_score(sfRenderWindow *window, objects_t *objs)
{
    sfText_setString(objs->scr->text, my_put_scr(objs->scr->score));
    sfRenderWindow_drawText(window, objs->scr->text, NULL);
}

void set_life(sfRenderWindow *window, objects_t *objs, birds_t *birds)
{
    for (int i = 0; i < birds->count; i++) {
        if (birds->bird[i].vect.x >= 1920) {
            objs->health->rect.left += 40;
            birds->bird[i].vect.x = (rand() % (-200) + 1) + -400;
            objs->health->life -= 1;
        }
        if (objs->health->life <= 0) {
            sfRenderWindow_close(window);
        }
    }
    sfSprite_setTexture(objs->health->sprite, objs->health->texture, sfTrue);
    sfSprite_setTextureRect(objs->health->sprite, objs->health->rect);
    sfSprite_setPosition(objs->health->sprite, objs->health->vect);
    sfRenderWindow_drawSprite(window, objs->health->sprite, NULL);
}

void display_objects(sfRenderWindow *window, objects_t *objs, birds_t *birds)
{
    set_sight(window, objs);
    set_life(window, objs, birds);
    set_score(window, objs);
}