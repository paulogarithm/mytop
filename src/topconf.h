/*
** EPITECH PROJECT, 2024
** top
** File description:
** topconf
*/

#ifndef TOPCONF_H_
    #define TOPCONF_H_

    #define TOP_UPDATE 3000 /* Update time in ms */

int header_line0(char const *line);

/* All header functions. */
static struct {
    char const *s;
    int (*f)(char const *line);
} const HEADER_FORMAT[] = {
    {
        "top - %s up %d:%0d, %d user, load average: %.2f, %.2f, %.2f",
        header_line0
    }
};

/* How many header lines there is. */
static int const HEADER_FORMAT_LEN =
sizeof(HEADER_FORMAT) / sizeof(HEADER_FORMAT[0]);

int asprintf(char **strp, const char *fmt, ...);

#endif /* !TOPCONF_H_ */
