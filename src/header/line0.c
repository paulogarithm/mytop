/*
** EPITECH PROJECT, 2024
** mytop
** File description:
** theader
*/

#include <ncurses.h>
#include <sys/sysinfo.h>
#include <sys/param.h>
#include <utmp.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "topconf.h"

static int get_loadavg(double arr[])
{
    struct sysinfo info = {0};
    int const loadscale = 1 << SI_LOAD_SHIFT;

    if (sysinfo(&info) == -1)
        return -1;
    for (int n = 0; n < 3; ++n)
        arr[n] = (double)info.loads[n] / loadscale;
    return 0;
}

static int get_nbusers(int *users)
{
    FILE *ufp = fopen(_PATH_UTMP, "r");
    struct utmp usr = { 0 };
    int nbusers = 0;

    if (ufp == NULL)
        return -1;
    while (fread(&usr, sizeof(usr), 1, ufp) == 1)
        if (*usr.ut_user && *usr.ut_line && *usr.ut_line != '~')
            ++nbusers;
    if (fclose(ufp) == -1)
        return -1;
    *users = nbusers;
    return -(nbusers < 1);
}

static int get_currenttime(char **bufptr)
{
    struct timeval tv = { 0 };
    struct tm *today = NULL;

    if (gettimeofday(&tv, NULL) == -1)
        return -1;
    today = localtime(&tv.tv_sec);
    if (today == NULL)
        return -1;
    if (asprintf(bufptr, "%d:%02d:%02d", today->tm_hour, today->tm_min,
    today->tm_sec) == -1)
        return -1;
    return 0;
}

int header_line0(char const *line)
{
    char *buf = NULL;
    double arr[3] = { 0.0 };
    int nbusers = 0;

    if (get_loadavg(arr) == -1 || get_nbusers(&nbusers) == -1
    || get_currenttime(&buf) == -1)
        return -1;
    (void)mvprintw(0, 0, line, buf, 0, 0, nbusers, arr[0], arr[1], arr[2]);
    free(buf);
    return 0;
}
