/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** bird management more functions
*/

#include "include/hunter.h"

void bird_spawn(birds_t *birds, Clock_t *Clocks)
{
    Clocks->time = sfClock_getElapsedTime(Clocks->gclock);
    Clocks->seconds = Clocks->time.microseconds / 1000000.0;

    if (Clocks->seconds >= 3 && birds->count < birds->max) {
        birds->count += 1;
        sfClock_restart(Clocks->gclock);
    }
}

birds_t *create_birds(void)
{
    birds_t *birds = malloc(sizeof(*birds));
    birds->max = 20;
    birds->count = 1;
    birds->bird = malloc(sizeof(bird_t) * birds->max);

    for (int i = 0; i < birds->max; i++)
        birds->bird[i] = bird_create();
    return (birds);
}
