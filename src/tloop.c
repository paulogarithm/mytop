/*
** EPITECH PROJECT, 2024
** mytop
** File description:
** tloop
*/

#include <ncurses.h>

#include "topfunc.h"

void top_loop(void)
{
    int input = 0;
    int res = 0;

    top_updatescreen();
    do {
        refresh();
        input = getch();
        if (input == ERR) {
            res = top_updatescreen();
            continue;
        }
        if (top_treatinput(input) == -1)
            break;
    } while (res != -1);
}
