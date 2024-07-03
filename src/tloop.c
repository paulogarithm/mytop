/*
** EPITECH PROJECT, 2024
** mytop
** File description:
** tloop
*/

#include <ncurses.h>

#include "topfunc.h"

int top_loop(void)
{
    int input = 0;
    int res = 0;

    res = top_updatescreen();
    while (res != -1) {
        refresh();
        input = getch();
        if (input == ERR) {
            res = top_updatescreen();
            continue;
        }
        if (top_treatinput(input) == -1)
            break;
    }
    return res;
}
