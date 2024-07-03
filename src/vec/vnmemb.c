/*
** EPITECH PROJECT, 2024
** c_vectors_2
** File description:
** vsize
*/

#include "vec.h"

size_t vec_nmemb(void const *ptr)
{
    return ((vecmeta_t *)ptr - 1)->nmemb;
}

size_t vec_maxmemb(void const *ptr)
{
    return ((vecmeta_t *)ptr - 1)->maxmemb;
}
