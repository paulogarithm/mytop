/*
** EPITECH PROJECT, 2024
** c_vectors_2
** File description:
** vector
*/

#ifndef VECTOR_H_
    #define VECTOR_H_

    #include <stddef.h>

    /* How many elements your vector can contain at creation. */
    #define _V_STARTMAXMEMB 4

    #ifndef _V_MOREMEMB
        /* The equation for adding more size in vector. */
        #define _V_MOREMEMB(meta) ((meta->maxmemb) * 2)
    #endif

    /* Create a new vector using type. */
    #define VEC_NEW(type) vec_newvector(sizeof(type))

/* The vector metadata that contains all informations. */
typedef struct {
    size_t nmemb;       /* How many elem there is. */
    size_t maxmemb;     /* How many elem you can store. */
    size_t elemsize;    /* The size of each elem. */
} vecmeta_t;

/* Create a new vector using size. */
void *vec_newvector(size_t elemsize);

/* Close a vector. */
void vec_close(void *vec);

/* Push a pointer in your vector. */
int vec_pushptr(void *vecptr, void *elem);

/* Push a number in your vector. */
int vec_pushnum(void *vecptr, __int128_t elem);

/* Push the value stored in the ref pointer. */
int vec_pushref(void *vecptr, void *ref);

/* Get the number of elements in a vector. */
size_t vec_nmemb(void const *vec);

/* Get the max number of elements the vector can handle. */
size_t vec_maxmemb(void const *ptr);

/* Convert a vector into a regular allocated C array. */
void *vec_todata(void *vec);

/* Push an entire segment of data in your vector. */
int vec_pushdata(void *vecptr, void *data, size_t datanmemb);

/* Like strcmp but with vectors. */
int vec_cmp(void const *a, void const *b);

#endif /* !VECTOR_H_ */
