/*
** EPITECH PROJECT, 2024
** c_vectors_2
** File description:
** vclose
*/

#include <stdlib.h>

#include "vec.h"

void vec_close(void *vecptr)
{
    vecmeta_t *meta = vecptr;

    --meta;
    free(meta);
}
