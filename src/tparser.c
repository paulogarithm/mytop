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

#include "vec/vec.h"
#include "topconf.h"
#include "topfunc.h"

static int is_number(char const *what)
{
    char *endptr = NULL;

    (void)strtol(what, &endptr, 10);
    return (endptr != NULL) && (*endptr == '\0');
}

static int loop_through_proc(processinfo_t **vecptr)
{
    DIR *dir = opendir("/proc");
    processinfo_t tmp = { 0 };

    if (dir == NULL)
        return -1;
    for (struct dirent *it = readdir(dir); it != NULL; it = readdir(dir)) {
        if (!is_number(it->d_name))
            continue;
        tmp.pid = atoi(it->d_name);
        tmp.status = 'S';
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
