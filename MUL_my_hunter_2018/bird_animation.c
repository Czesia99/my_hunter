/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** bird animation functions
*/

#include "include/hunter.h"

Clock_t *bird_clock_create(void)
{
    Clock_t *bclock = malloc(sizeof(*bclock));
    bclock->clock = sfClock_create();
    return (bclock);
}

void move_bird(bird_t *bird, int pix)
{
    bird->vect.x += pix;
}

void move_bird_rect (bird_t *bird, int offset, int max_value)
{
    if (offset + (bird->rect).left >= max_value - offset)
        (bird->rect).left = 0;
    else
        (bird->rect).left += offset;
}

void bird_animation(birds_t *birds, Clock_t *Clocks, sfRenderWindow *window)
{
    Clocks->time = sfClock_getElapsedTime(Clocks->bclock);
    Clocks->seconds = Clocks->time.microseconds / 1000000.0;
    for (int i = 0; i < birds->count; i++) {
        if (Clocks->seconds >= 0.0500) {
            move_bird_rect(&birds->bird[i], 207, 1865);
            move_bird(&birds->bird[i], 20);
            sfSprite_setTextureRect(birds->bird[i].sprite, birds->bird[i].rect);
            sfClock_restart(Clocks->bclock);
        }
        sfSprite_setPosition(birds->bird[i].sprite, birds->bird[i].vect);
        sfRenderWindow_drawSprite(window, birds->bird[i].sprite, NULL);
    }
}

bird_t bird_create(void)
{
    bird_t bird;
    sfVector2f vect;
    vect.x = (rand() % (-200) + 1) + -400;
    vect.y = (rand() % (400) + 1) + 50;
    sfIntRect rect = {0, 0, 207, 207};

    bird.texture = sfTexture_createFromFile("ressources/blackbird.png", NULL);
    bird.sprite = sfSprite_create();
    bird.vect = vect;
    bird.rect = rect;
    sfSprite_setTexture(bird.sprite, bird.texture, sfTrue);
    sfSprite_setTextureRect(bird.sprite, bird.rect);
    return (bird);
}
