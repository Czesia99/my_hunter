/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** my_Hunter main function
*/

#include "include/hunter.h"

void global_clock_create(Clock_t *Clocks)
{
    Clocks->gclock = malloc(sizeof(Clocks->gclock));
    Clocks->gclock = sfClock_create();
    Clocks->bclock = malloc(sizeof(Clocks->bclock));
    Clocks->bclock = sfClock_create();
}

void window_create(void)
{
    sfRenderWindow *window;
    sfVideoMode vm = {1920, 1080, 64};
    sfEvent event;
    birds_t *birds = create_birds();
    Clock_t *Clocks = malloc(sizeof(*Clocks));
    objects_t *objs = malloc(sizeof(*objs));

    window = sfRenderWindow_create(vm, "my hunter", sfResize | sfClose, NULL);
    objs = setup_objects(objs);
    global_clock_create(Clocks);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            analyse_events(window, event, birds, objs);
        display_window(window, objs, birds, Clocks);
    }
    destroyer(Clocks, objs);
    sfRenderWindow_destroy(window);
}

int main(int ac, char **av)
{
    if (ac == 1) {
        srand(time(NULL));
        window_create();
    }
    else if (ac == 2 && (av[1][0] == '-' && av[1][1] == 'h'))
        display_man();
    else {
        my_printf("-h for game manual\n");
        return (84);
    }
}
