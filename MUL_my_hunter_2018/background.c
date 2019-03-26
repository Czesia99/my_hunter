/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** background management
*/

#include "include/hunter.h"

void set_background(sfRenderWindow *window, objects_t *objs)
{
    objs->bgrd = malloc(sizeof(*objs->bgrd));
    objs->bgrd->texture = sfTexture_createFromFile("ressources/font.jpg", NULL);
    objs->bgrd->sprite = sfSprite_create();

    sfSprite_setTexture(objs->bgrd->sprite, objs->bgrd->texture, sfTrue);
    sfRenderWindow_drawSprite(window, objs->bgrd->sprite, NULL);
    sfSprite_destroy(objs->bgrd->sprite);
    sfTexture_destroy(objs->bgrd->texture);
}
