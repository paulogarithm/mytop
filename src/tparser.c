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
#include <pwd.h>
#include <sys/stat.h>

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

static char *get_vector_newpath(char const *root, char const *filename)
{
    char *str = VEC_NEW(char);

    if (str == NULL)
        return NULL;
    (void)vec_pushdata(&str, root, strlen(root));
    (void)vec_pushnum(&str, '/');
    (void)vec_pushdata(&str, filename, strlen(filename));
    return str;
}

static char get_status_of_fixed(char const *root, char const *filename)
{
    char *str = get_vector_newpath(root, filename);
    char res = -1;

    if (str == NULL)
        return -1;
    (void)vec_pushdata(&str, "/status", 7);
    str = vec_todata(str);
    res = get_status_of(str);
    free(str);
    return res;
}

static unsigned int get_user(char const *root, char const *filename)
{
    char *str = get_vector_newpath(root, filename);
    struct stat st = {0};

    if (str == NULL)
        return 0;
    str = vec_todata(str);
    if (stat(str, &st) == -1) {
        free(str);
        return -1;
    }
    free(str);
    return st.st_uid;
}

static int get_num_at(char const *filename, int n)
{
    FILE *file = fopen(filename, "r");
    size_t size = 0;
    char *content = NULL;

    if (file == NULL)
        return -1;
    while (n)
        n = ((getdelim(&content, &size, ' ', file) == -1) ? (0) : (n - 1));
    size = (size_t)atoi(content);
    free(content);
    fclose(file);
    return (int)size;
}

static int get_priority(char const *root, char const *filename)
{
    char *str = get_vector_newpath(root, filename);
    int num = 0;

    if (str == NULL)
        return -1;
    (void)vec_pushdata(&str, "/stat", 5);
    str = vec_todata(str);
    num = get_num_at(str, 18);
    free(str);
    return num;
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
        tmp.status = get_status_of_fixed(root, it->d_name);
        tmp.pwuid = get_user(root, it->d_name);
        tmp.prio = get_priority(root, it->d_name);
        (void)vec_pushref(vecptr, &tmp);
    }
    return closedir(dir);
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
