/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** vcmp
*/

#include <string.h>

#include "vec.h"

int vec_cmp(void const *a, void const *b)
{
    vecmeta_t *ameta = (vecmeta_t *)a - 1;
    vecmeta_t *bmeta = (vecmeta_t *)b - 1;
    size_t asize = ameta->nmemb * ameta->elemsize;
    size_t bsize = bmeta->nmemb * bmeta->elemsize;

    return memcmp(a, b, ((asize < bsize) ? asize : bsize));
}
