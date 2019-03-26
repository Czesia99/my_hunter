/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** hunter headers
*/

//includes
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include "../lib/my/my.h"
#include "../lib/my_printf/include/my_printf.h"

//structures
typedef struct Clock_s {
    sfClock *clock;
    sfClock *bclock;
    sfClock *gclock;
    sfTime time;
    float seconds;
} Clock_t;

typedef struct bird_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f vect;
} bird_t;

typedef struct obj_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f vect;
    sfVector2f scale;
    sfMusic *music;
    sfFont *font;
    sfText *text;
    int life;
    int score;
} obj_t;

typedef struct objects_s {
    obj_t *shotn;
    obj_t *sight;
    obj_t *health;
    obj_t *bgrd;
    obj_t *scr;
} objects_t;

typedef struct birds_s {
    bird_t *bird;
    int count;
    int max;
} birds_t;

//prototypes
//main.c
void window_create();
void global_clock_create(Clock_t *Clocks);

//events.c
void analyse_shot(sfRenderWindow *window, sfEvent event, birds_t *birds, \
objects_t *objs);
void analyse_events(sfRenderWindow *window, sfEvent event, birds_t *birds, \
objects_t *objs);
void close_window(sfRenderWindow *window, sfEvent event);

//bird_animation.c
Clock_t *bird_clock_create();
bird_t bird_create();
void bird_animation(birds_t *bird, Clock_t *bclock, sfRenderWindow *window);
void move_bird_rect (bird_t *bird, int offset, int max_value);
void move_bird(bird_t *bird, int pix);

//bird_management
birds_t *create_birds();
void bird_spawn(birds_t *birds, Clock_t *Clocks);

//setup_objects.c
objects_t *setup_objects(objects_t *objs);
obj_t *setup_health(objects_t *objs);
obj_t *setup_sight(objects_t *objs);

//objects.c
void set_sight(sfRenderWindow *window, objects_t *objs);
void set_life(sfRenderWindow *window, objects_t *objs, birds_t *birds);
void set_score(sfRenderWindow *window, objects_t *objs);
void display_objects(sfRenderWindow *window, objects_t *objs, birds_t *birds);

//background.c
void set_background(sfRenderWindow *window, objects_t *objs);

//display_window.c
void display_window(sfRenderWindow *window, objects_t *objs, \
birds_t *birds,  Clock_t *Clocks);

//clear.c
void destroyer(Clock_t *Clocks, objects_t *objs);

//manual.c
void display_man();
char *my_put_scr(int nb);