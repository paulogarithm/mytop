/*
** EPITECH PROJECT, 2024
** top
** File description:
** topfunc
*/

#ifndef TOPFUNC_H_
    #define TOPFUNC_H_

    #include "topconf.h"

/* Start the top functions. */
void top_start(void);

/* Stop the top. */
void top_end(void);

/* Update the screen. */
int top_updatescreen(void);

/* The main loop. */
int top_loop(void);

/* Treat the 'in' input. */
int top_treatinput(int in);

/* Get the process infos. */
processinfo_t *top_getprocessinfos(void);

#endif /* !TOPFUNC_H_ */
