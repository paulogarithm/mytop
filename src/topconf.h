/*
** EPITECH PROJECT, 2024
** top
** File description:
** topconf
*/

#ifndef TOPCONF_H_
    #define TOPCONF_H_

    #define TOP_UPDATE 3000 /* Update time in ms */

int header_line0(char const *line, int x);

/* Default function for header */
static inline int default_func(char const *line, int x)
{
    mvprintw(x, 0, "%s", line);
    return 0;
}

/* All header functions. */
static struct {
    char const *s;
    int (*f)(char const *line, int x);
} const HEADER_FORMAT[] = {
    {
        "top - %s up %d:%02d, %d user, load average: %.2f, %.2f, %.2f",
        header_line0
    },
    {
        "Tasks: %d total, %d running, %d sleeping, %d stopped, %d zombie",
        default_func
    },
    {
        "%%Cpu(s): %.1f us, %.1f sy, %.1f ni, %.1f id, %.1f wa, "
            "%.1f hi, %.1f si, %.1f st",
        default_func
    },
    {
        "MiB Mem : %.1f total, %.1f free, %.1f used, %.1f buff/cache",
        default_func
    },
    {
        "MiB Swap: %.1f total, %.1f free, %.1f used. %.1f avail Mem",
        default_func
    },
};

/* How many header lines there is. */
static int const HEADER_FORMAT_LEN =
sizeof(HEADER_FORMAT) / sizeof(HEADER_FORMAT[0]);

/* asprintf from <stdio.h> */
int asprintf(char **strp, const char *fmt, ...);

#endif /* !TOPCONF_H_ */
