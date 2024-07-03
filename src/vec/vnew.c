/*
** EPITECH PROJECT, 2024
** c_vectors_2
** File description:
** vctor
*/

#include <stdlib.h>

#include "vec.h"

void *vec_newvector(size_t elemsize)
{
    vecmeta_t *meta = calloc(1,
        sizeof(vecmeta_t) + (elemsize * _V_STARTMAXMEMB));
    void *start = NULL;

    if (meta == NULL)
        return NULL;
    start = meta + 1;
    meta->elemsize = elemsize;
    meta->maxmemb = _V_STARTMAXMEMB;
    meta->nmemb = 0;
    return start;
}
