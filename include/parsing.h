/*
** EPITECH PROJECT, 2021
** tail
** File description:
** Created by mlambotin,
*/

#ifndef TAIL_PARSING_H
#define TAIL_PARSING_H

#include <stdbool.h>
#include "tail.h"

struct arg_s {
	char letter;
	bool (*fun_ptr)(tail_t *);
};
typedef struct arg_s arg_t;

bool parse_args(tail_t *tail, int ac, char **av);

#endif //TAIL_PARSING_H
