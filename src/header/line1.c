/*
** EPITECH PROJECT, 2024
** mytop
** File description:
** theader
*/

#include <ncurses.h>

#include "topconf.h"
#include "topfunc.h"
#include "vec/vec.h"

int header_line1(char const *line, int x)
{
    processinfo_t *vec = top_getprocessinfos();

    if (vec == NULL)
        return -1;
    (void)mvprintw(x, 0, "%ld\n", vec_nmemb(vec));
    vec_close(vec);
    return 0;
}
