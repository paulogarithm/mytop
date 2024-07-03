/*
** EPITECH PROJECT, 2024
** mytop
** File description:
** theader
*/

#include <ncurses.h>

#include "topconf.h"

int header_line0(char const *line, int x)
{
    (void)mvprintw(x, 0, line, );
    return 0;
}
