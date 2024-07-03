/*
** EPITECH PROJECT, 2024
** mytop
** File description:
** theader
*/

#include <ncurses.h>
#include <string.h>

#include "topconf.h"
#include "topfunc.h"
#include "vec/vec.h"

static int get_counts(processinfo_t *vec, int *letters)
{
    for (size_t n = 0; n < vec_nmemb(vec); ++n) {
        if (vec[n].status == -1)
            vec[n].status = ('T' - 'A');
        ++(letters[(int)(vec[n].status)]);
    }
    return 0;
}

int header_line1(char const *line, int x)
{
    processinfo_t *vec = top_getprocessinfos();
    int letters[26] = { 0 };

    if (vec == NULL)
        return -1;
    if (get_counts(vec, letters) == -1)
        return -1;
    (void)mvprintw(x, 0, line,
        (int)vec_nmemb(vec),
        letters['R' - 'A'],
        letters['I' - 'A'] + letters['S' - 'A'],
        letters['T' - 'A'],
        letters['Z' - 'A']);
    vec_close(vec);
    return 0;
}
