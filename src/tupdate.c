/*
** EPITECH PROJECT, 2024
** mytop
** File description:
** tupdate
*/

#include <ncurses.h>
#include <stddef.h>
#include <pwd.h>

#include "topfunc.h"
#include "topconf.h"
#include "vec/vec.h"

static char const *get_user_name(unsigned int pwuid)
{
    struct passwd *pw = NULL;

    pw = getpwuid(pwuid);
    if (pw == NULL)
        return "unknown";
    return pw->pw_name;
}

static int display_processes(processinfo_t *vec)
{
    (void)mvprintw((TOP_PROSCLINES - 1), 0, "PID  USER  PR  NI  VIRT  RES  "
        "SHR  S  %%CPU  %%MEM  TIME+");
    for (size_t n = 0; n < vec_nmemb(vec); ++n)
        (void)mvprintw((TOP_PROSCLINES + n), 0, "%u  %s  %d  %c",
            vec[n].pid,
            get_user_name(vec[n].pwuid),
            vec[n].prio,
            vec[n].status + 'A'
        );
    return 0;
}

static int display_header_lines(processinfo_t *vec)
{
    int res = 0;

    for (int n = 0; n < HEADER_FORMAT_LEN && res != -1; ++n)
        res = HEADER_FORMAT[n].f(HEADER_FORMAT[n].s, vec, n);
    return res;
}

int top_updatescreen(void)
{
    processinfo_t *vec = top_getprocessinfos();
    int res = 0;

    if (vec == NULL)
        return -1;
    res = display_header_lines(vec);
    if (res != -1)
        res = display_processes(vec);
    vec_close(vec);
    return res;
}
