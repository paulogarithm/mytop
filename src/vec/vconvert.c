/*
** EPITECH PROJECT, 2024
** c_vectors_2
** File description:
** vtoraw
*/

#include <string.h>

#include "vec.h"

void *vec_todata(void *vec)
{
    vecmeta_t *meta = (vecmeta_t *)vec - 1;
    char *ptr = (void *)meta;
    size_t oldsize = meta->elemsize;
    size_t size = oldsize * meta->nmemb;

    (void)memmove(ptr, vec, size);
    (void)memset(ptr + size, 0, oldsize);
    return ptr;
}
