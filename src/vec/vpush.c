/*
** EPITECH PROJECT, 2024
** c_vectors_2
** File description:
** vpush
*/

#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "vec.h"

int vec_pushref(void *vecptr, void const *ptr)
{
    vecmeta_t *meta = (*(vecmeta_t **)vecptr) - 1;
    char *start = *(void **)vecptr;

    if (meta->nmemb == meta->maxmemb) {
        meta->maxmemb = _V_MOREMEMB(meta);
        meta = realloc(meta, sizeof(vecmeta_t) +
            (meta->maxmemb * meta->elemsize));
        if (meta == NULL)
            return -1;
        start = (char *)(meta + 1);
        *(void **)vecptr = start;
    }
    (void)memcpy(start + meta->elemsize * meta->nmemb, ptr, meta->elemsize);
    ++(meta->nmemb);
    return 0;
}

int vec_pushnum(void *vecptr, __int128_t elem)
{
    return vec_pushref(vecptr, &elem);
}

int vec_pushptr(void *vecptr, void *elem)
{
    return vec_pushnum(vecptr, (uintptr_t)elem);
}

int vec_pushdata(void *vecptr, void const *data, size_t datanmemb)
{
    vecmeta_t *meta = NULL;
    int res = 0;
    char const *ptr = data;

    for (size_t n = 0; n < datanmemb; ++n) {
        res = vec_pushref(vecptr, ptr);
        meta = (*(vecmeta_t **)vecptr) - 1;
        ptr += meta->elemsize;
    }
    return res;
}
