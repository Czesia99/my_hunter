/*
** EPITECH PROJECT, 2018
** setup_objects.c
** File description:
** setup my hunter objects
*/

#include "include/hunter.h"

obj_t *setup_score(objects_t *objs)
{
    sfVector2f scale = {1, 1};
    sfVector2f vect = {1810, 60};
    objs->scr = malloc(sizeof(*objs->scr));
    objs->scr->text = sfText_create();
    objs->scr->font = sfFont_createFromFile("ressources/SIXTY.TTF");
    objs->scr->vect = vect;
    objs->scr->scale = scale;
    objs->scr->score = 0;
    sfText_setPosition(objs->scr->text, objs->scr->vect);
    sfText_setFont(objs->scr->text, objs->scr->font);
    sfText_setScale(objs->scr->text, objs->scr->scale);
    return (objs->scr);
}

obj_t *setup_sight(objects_t *objs)
{
    objs->sight = malloc(sizeof(*objs->sight));
    objs->sight->texture = sfTexture_createFromFile("ressources/targetr.png", \
    NULL);
    objs->sight->sprite = sfSprite_create();

    sfSprite_setTexture(objs->sight->sprite, objs->sight->texture, sfTrue);
    return (objs->sight);
}

obj_t *setup_health(objects_t *objs)
{
    objs->health = malloc(sizeof(*objs->health));
    sfIntRect rect = {0, 0, 40, 40};
    sfVector2f vect = {1800, 20};

    objs->health->texture = sfTexture_createFromFile("ressources/heart.png", \
    NULL);
    objs->health->sprite = sfSprite_create();
    objs->health->rect = rect;
    objs->health->vect = vect;
    objs->health->life = 4;
    return (objs->health);
}

objects_t *setup_objects(objects_t *objs)
{
    objs->health = setup_health(objs);
    objs->sight = setup_sight(objs);
    objs->scr = setup_score(objs);
    return (objs);
}