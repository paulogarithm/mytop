/*
** EPITECH PROJECT, 2024
** mytop
** File description:
** tupdate
*/

#include <ncurses.h>

#include "topfunc.h"
#include "topconf.h"

static int display_header_lines(void)
{
    int res = 0;

    for (int n = 0; n < HEADER_FORMAT_LEN && res != -1; ++n)
        res = HEADER_FORMAT[n].f(HEADER_FORMAT[n].s);
    return res;
}

int top_updatescreen(void)
{
    return display_header_lines();
}
