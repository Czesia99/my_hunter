/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** destroy everything !
*/

#include "include/hunter.h"

void destroyer(Clock_t *Clocks, objects_t *objs)
{
    sfClock_destroy(Clocks->bclock);
    sfClock_destroy(Clocks->gclock);
    sfSprite_destroy(objs->sight->sprite);
    sfTexture_destroy(objs->sight->texture);
    sfSprite_destroy(objs->health->sprite);
    sfTexture_destroy(objs->health->texture);
    sfFont_destroy(objs->scr->font);
    sfText_destroy(objs->scr->text);
}
