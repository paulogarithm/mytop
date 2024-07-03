/*
** EPITECH PROJECT, 2024
** top
** File description:
** tstart
*/

#include <ncurses.h>

#include "topconf.h"

void top_start(void)
{
    initscr();
    noecho();
    cbreak();
    timeout(TOP_UPDATE);
    mousemask(ALL_MOUSE_EVENTS, NULL);
    refresh();
}

void top_end(void)
{
    endwin();
}
