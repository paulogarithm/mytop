/*
** EPITECH PROJECT, 2024
** mytop
** File description:
** tparser
*/

#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "vec/vec.h"
#include "topconf.h"
#include "topfunc.h"

static int is_number(char const *what)
{
    char *endptr = NULL;

    (void)strtol(what, &endptr, 10);
    return (endptr != NULL) && (*endptr == '\0');
}

static char get_status_of(char const *this)
{
    FILE *file = fopen(this, "r");
    char *line = NULL;
    size_t len = 0;
    char c = '\0';
    char *foo = NULL;

    if (file == NULL)
        return -1;
    for (int n = 0; n < 3; ++n)
        if (getline(&line, &len, file) == -1)
            return -1;
    if (strtok(line, ": \t") == NULL)
        return -1;
    foo = strtok(NULL, ": \t");
    if (foo == NULL)
        return -1;
    c = foo[0] - 'A';
    free(line);
    return c;
}

static char get_status_of_fixed(char const *filename, char const *root)
{
    char *str = VEC_NEW(char);
    char res = '\0';

    if (str == NULL)
        return -1;
    (void)vec_pushdata(&str, root, strlen(root));
    (void)vec_pushnum(&str, '/');
    (void)vec_pushdata(&str, filename, strlen(filename));
    (void)vec_pushdata(&str, "/status", 7);
    str = vec_todata(str);
    res = get_status_of(str);
    free(str);
    return res;
}

static int loop_through_proc(processinfo_t **vecptr)
{
    char const *root = "/proc";
    DIR *dir = opendir(root);
    processinfo_t tmp = { 0 };

    if (dir == NULL)
        return -1;
    for (struct dirent *it = readdir(dir); it != NULL; it = readdir(dir)) {
        if (!is_number(it->d_name))
            continue;
        tmp.pid = atoi(it->d_name);
        tmp.status = get_status_of_fixed(it->d_name, root);
        (void)vec_pushref(vecptr, &tmp);
    }
    return 0;
}

processinfo_t *top_getprocessinfos(void)
{
    processinfo_t *vec = VEC_NEW(processinfo_t);

    if (vec == NULL)
        return NULL;
    if (loop_through_proc(&vec) == -1) {
        vec_close(vec);
        return NULL;
    }
    return vec;
}
